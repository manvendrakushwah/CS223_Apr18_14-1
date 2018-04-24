#include <bits/stdc++.h>

#include "Seeker.h"

#define pb push_back
#define mp make_pair

using namespace std ;

void Seeker::cancel_appointment( User &current_user , map<string,User> &users_data , bool should_recurse ){
    system("cls") ;
    cout<<"\n" ;
    cout<<"\n\t  NOTE : YOU ARE ALLOWED TO CANCEL ONLY THOSE APPOINTMENTS IN WHICH YOU SEEKED FROM ANOTHER USER/USERS i.e.\n" ;
    cout<<"\t  THE APPOINTMENTS IN WHICH YOU ARE PARTICIPATING AS A SEEKER .\n\n" ;
    if( current_user.get_seeker_vector().size() == 0 ){
        cout<<"\n\tYOU HAVE NO SUCH APPOINTMENTS THAT YOU CAN CANCEL .\n" ;
        cout<<"\n\n\t\t\t\t\t\t\tDirecting to your account homepage now ...................\n\n" ;
 //       Sleep(3000) ;
        return ;
    }

    cout<<"\n\n" ;
    cout<<"\t  NOW, SELECT AN APPOINTMENT FROM YOUR SEEKER APPOINTMENTS BY THE CORRESPONDING INDEX NUMBER DENOTED AS FOLLOWS :\n" ;
    cout<<"\n" ;

    vector<Appointment> temp_seeker_appts = current_user.get_seeker_vector() ;
    print_appointments( current_user , temp_seeker_appts ) ;

    // Steps remaining in this function .
    // (1) Take appointment input of appointment index number .
    // (2) Cancel the appointment by reflecting changes .
    // (3) Appointment successfully cancelled cout .
    // (4) Then create 2 options of cancel again or return to homepage .

    // Step 1 (begins here) .

    Validate_Input validator ;
    int number_of_appts = temp_seeker_appts.size() ;
	string verdict = "xxx" ;
	while( validator.validate_number(verdict,1,number_of_appts) == 0 ){
		cout<<"\n\t SELECT ANY ONE OF THE SHOWN APPOINTMENTS BY IT'S INDEX NUMBER :\n\n" ;
		cout<<"\tENTERED INDEX NUMBER = " ;
        cin>>ws ;
		getline(cin,verdict) ;
		if( validator.validate_number(verdict,1,number_of_appts) == 0 ){
			cout<<"\tPlease enter an appropriate option number .\n\n" ;
		}
	}
    int option_number = validator.validate_number( verdict , 1 , number_of_appts ) ;

    // Step 1 (ends here) .
        // -----------
    // Step 2 (begins here) .

        // Erasing from Appointments vector of both users .
    Appointment temp_appt = temp_seeker_appts[ option_number-1 ] ;
    Date temp_date_of_appt = temp_appt.get_date_of_appt() ;
    temp_seeker_appts.erase( temp_seeker_appts.begin() + (option_number-1) ) ;

    current_user.set_seeker_vector( temp_seeker_appts ) ;
    users_data[ current_user.get_username() ] = current_user ;
    User &t_user = users_data[ temp_appt.get_user_name() ] ;
    vector<Appointment> temp_acceptor_vec = t_user.get_acceptor_vector() ;

    Appointment temp_appt1 = temp_appt ;
    temp_appt1.set_user_name( current_user.get_username() ) ;

    int index_num = -1 ;
    for(int i=0 ; i<temp_acceptor_vec.size() ; i++){
        if( temp_appt1.is_appointment_equal( temp_acceptor_vec[i] ) ){
            index_num = i ;
            break ;
        }
    }

    temp_acceptor_vec.erase( temp_acceptor_vec.begin() + index_num ) ;
    t_user.set_acceptor_vector( temp_acceptor_vec ) ;

        // Erasing from Calender of both users .
    User& us1 = current_user , us2 = t_user ;
    Calendar cale1 = us1.get_timeline() ;
    Calendar cale2 = us2.get_timeline() ;
    map< Date , vector < pair< Slot , bool > > > cal1 = cale1.get_cal() ;
    map< Date , vector < pair< Slot , bool > > > cal2 = cale2.get_cal() ;
    vector< pair<Slot,bool> > temp_v1 = cal1[ temp_date_of_appt ] ;
    vector< pair<Slot,bool> > temp_v2 = cal2[ temp_date_of_appt ] ;

    map<int,int> temp_slot_index ;
    temp_slot_index[9] = 0 , temp_slot_index[10] = 1 , temp_slot_index[11] = 2 , temp_slot_index[12] = 3 ;
    temp_slot_index[1] = 4 , temp_slot_index[2] = 5 , temp_slot_index[3] = 6 , temp_slot_index[4] = 7 ;

    temp_v1[ temp_slot_index[ temp_appt.get_slot_of_appt().get_start_time().get_hour() ] ].second = 0 ;
    temp_v2[ temp_slot_index[ temp_appt.get_slot_of_appt().get_start_time().get_hour() ] ].second = 0 ;
    cal1[ temp_appt.get_date_of_appt() ] = temp_v1 , cal2[ temp_appt.get_date_of_appt() ] = temp_v2 ;
    cale1.set_cal1( cal1 ) , cale2.set_cal1( cal2 ) ;
    us1.set_timeline( cale1 ) , us2.set_timeline( cale2 ) ;
    users_data[ us1.get_username() ] = us1 , users_data[ us2.get_username() ] = us2 ;

    // Step 2 (ends here) .
        // -----------
    // Step 3 (begins here) .

    cout<<"\n\n\t\t\t\t\t\t\t !!!  THE SELECTED APPOINTMENT IS CANCELLED SUCCESSFULLY  !!! "<<endl ;
 //   Sleep(3000) ;

    // Step 3 (ends here) .
        // -----------
    // Step 4 (begins here) .
    if( should_recurse == 0 ){
        return ;
    }

	string verdict99 = "xxx" ; // 'return to home page' option number is the default option .
	while( validator.validate_number(verdict99,1,2) == 0 ){
		cout<<"\n\n\t SELECT ANY OF THE FOLLOWING OPTIONS TO PERFORM THE CORRESPONDING OPTION :\n\n" ;
		cout<<"\t1 -> CANCEL APPOINTMENT \n\n" ;
		cout<<"\t2 -> RETURN TO HOMEPAGE \n\n" ;
		cout<<"\t ENTERED OPTION = " ;
        cin>>ws ;
		getline(cin,verdict99) ;
		if( validator.validate_number(verdict99,1,2) == 0 ){
			cout<<"\n\n\tPlease enter an appropriate option number ." ;
		}
	}

    int option_number99 = validator.validate_number( verdict99 , 1 , 2 ) ;

	if( option_number99 == 1 ){
		cancel_appointment( current_user , users_data , 1 ) ;
	}
	else if( option_number99 == 2 ){
        cout<<"\n\n\t\t\t\t\t\t\tDirecting to your account homepage now ...................\n\n" ;
   //     Sleep(3000) ;
		return ;
	}

    // Step 4 (ends here) .
}

void Seeker::request_appointment( User& current_user , map<string,User>& users_data ,
map< string,vector<Notification> >& app_notifications ){
    system("cls") ;
    cout<<"\n\n" ;
	cout<<"\t\t\t\t\t\t\t\t  !!!  APPOINTMENT REQUEST PROCESS BEGINS  !!!\n\n\n" ;

//  cout<<"Inside Request Appointment Function .\n" ;
    cout<<"\tTHE LIST OF USERS FROM WHOM YOU CAN REQUEST AN APPOINTMENT IS AS FOLLOWS :\n\n" ;
    Appointment temp_appt ;

    // Step 1 : Take Acceptor username input by the current user .
    map<int,string> user_index_num ;

        // 1.1 : Showing list of users in the form of table .
    print_users_list( current_user , users_data , user_index_num ) ;

        // 1.2 : Taking the Acceptor username as input by the mapped index number .
    Validate_Input validator ;
    int number_of_users = users_data.size() - 1 ;
	string verdict = "xxx" ;
	while( validator.validate_number(verdict,1,number_of_users) == 0 ){
		cout<<"\n\n\t SELECT ANY ONE OF THE SHOWN USERS (REPRESENTED BY THIER USERNAMES) BY THE CORRESPONDING INDEX NUMBER :\n\n" ;
		cout<<"\t ENTERED INDEX NUMBER = " ;
        cin>>ws ;
		getline(cin,verdict) ;
		if( validator.validate_number(verdict,1,number_of_users) == 0 ){
			cout<<"\tPlease enter an appropriate option number .\n\n" ;
		}
	}
    int option_number = validator.validate_number( verdict , 1 , number_of_users ) ;
    string acceptor_username = user_index_num[ option_number ] ;
//  cout<<"The chosen acceptor is = "<<acceptor_username<<"\n" ;
    temp_appt.set_user_name( current_user.get_username() ) ;

    // Step 2 : Take input for Appointment type .
	string verdict1 = "xxx" ; // 'return to home page' option number is the default option .
	while( validator.validate_number(verdict1,1,2) == 0 ){
		cout<<"\n\n\t SELECT ANY OF THE FOLLOWING APPOINTMENT TYPE FOR YOUR APPOINTMENT :\n\n" ;
		cout<<"\t1 -> PRIORITY APPOINTMENT (TILL THE NEXT 4 WORKING DAYS)\n\n" ;
		cout<<"\t2 -> NORMAL APPOINTMENT (FROM THE 5TH TO THE 60TH WORKING DAY)\n\n" ;
		cout<<"\t ENTERED OPTION = " ;
        cin>>ws ;
		getline(cin,verdict1) ;
		if( validator.validate_number(verdict1,1,2) == 0 ){
			cout<<"\tPlease enter an appropriate option number .\n\n" ;
		}
	}

    int option_number1 = validator.validate_number( verdict1 , 1 , 2 ) ;

    // Step 3 : Create object of Normal or Priority Appointment accordingly .
    Appointment final_computed_appointment ;
	if( option_number1 == 1 ){ // Priority Appointment .
//      cout<<"In branch for Priority Appointment .\n" ;
        temp_appt.set_appt_type( "Priority" ) ;
        Priority_Appointment pr_appt ;
        pr_appt.set_priority_appointment_data( temp_appt ) ;

        // Step 4 & 5 : Take input for Date of Appointment and Slot for Appointment accordingly based on Appointment type .
        final_computed_appointment = pr_appt.req_priority_appt() ;
	}
	else if( option_number1 == 2 ){ // Normal Appointment .
//      cout<<"In branch for Normal Appointment .\n" ;
        temp_appt.set_appt_type( "Normal" ) ;
        Normal_Appointment nr_appt ;
        nr_appt.set_normal_appointment_data( temp_appt ) ;

        // Step 4 & 5 : Take input for Date of Appointment and Slot for Appointment accordingly based on Appointment type .
        final_computed_appointment = nr_appt.req_normal_appt() ;
	}

    // Step 6 : Send Notification to the Acceptor .
    Notification temp_notification ;
    temp_notification.set_notification_by_appointment( final_computed_appointment ) ;
    app_notifications[ acceptor_username ].pb( temp_notification ) ;

    cout<<"\n\n\t\t\t             !!!  NOTIFICATION OF REQUEST FOR APPOINTMENT TO THE SPECIFIED ACCEPTOR IS SENT SUCCESSFULLY  !!! "<<endl ;
    cout<<"\n\n\t\t\t\t\t\t\tDirecting to your account homepage now ...................\n\n" ;
 //   Sleep(3000) ;
}

void Seeker::print_users_list( User& current_user , map<string,User>& users_data , map<int,string>& user_index_num ){
    int ind = 1 ;
    string cur_username = current_user.get_username() ;
    // The Item type row is printed as below .
	cout<<"\t+" ;
	for(int i=1 ; i<=31 ; i++)cout<<"-";
	cout<<"+\n" ;
	string s = "\t| Index No. |     Username      |\n" ;
	cout<<s ;
	cout<<"\t+" ;
	for(int i=1 ; i<=31 ; i++)cout<<"-";
	cout<<"+\n" ;

    // Printing the rows of the list of users as follows .
    for( auto it = users_data.begin() ; it != users_data.end() ; it++ ){
        if( it->first != cur_username && it->first != "" ){
            stringstream ss ;
            ss<<ind ;
            string index_number = ss.str() , t_username = it->first ;
            string sp1( 6 - index_number.size() , ' ' ) , sp2( 15 - t_username.size() , ' ' ) ;
            user_index_num[ ind ] = t_username ;
            cout<<"\t|"<<sp1+index_number<<"     |  "<<t_username+sp2<<"  |\n" ;
            ind++ ;
        }
    }

	cout<<"\t+" ;
	for(int i=1 ; i<=31 ; i++)cout<<"-";
	cout<<"+\n" ;
}

