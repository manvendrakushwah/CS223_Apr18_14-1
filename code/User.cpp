#include <bits/stdc++.h>

#include "User.h"
#include "Seeker.h"
#include "Acceptor.h"

#define pb push_back
#define mp make_pair

using namespace std ;

// Functions of User Class are defined as follows .

void User::set_name(string given_name){
    name = given_name ;
}

void User::set_username(string given_username){
    username = given_username ;
}

void User::set_password(string given_password){
    password = given_password ;
}

void User::set_profile_data( string p_name , string p_username , string p_password ){
	name = p_name , username = p_username , password = p_password ;
}

void User::set_timeline( Calendar temp_cal ){
	timeline = temp_cal ;
}

string User::get_name(){
    return name ;
}

string User::get_username(){
    return username ;
}

string User::get_password(){
    return password ;
}

Calendar User::get_timeline(){
	return timeline ;
}

// Functions for additional attributes are defined as follows .

void User::set_seeker_vector( vector<Appointment> seeker_appts ){
    as_seeker = seeker_appts ;
}

void User::add_appt_to_seeker_vector( Appointment appt ){
    as_seeker.pb( appt ) ;
}

vector<Appointment> User::get_seeker_vector(){
    return as_seeker ;
}

void User::set_acceptor_vector( vector<Appointment> acceptor_appts ){
    as_acceptor = acceptor_appts ;
}

void User::add_appt_to_acceptor_vector( Appointment appt ){
    as_acceptor.pb( appt ) ;
}

vector<Appointment> User::get_acceptor_vector(){
    return as_acceptor ;
}

// Rest of the functions of User Class are defined as follows .

void User::view_profile( map<string,User> &users_data , map< string , vector<Notification> > &app_notifications ){
    system("cls") ;
    cout<<"\n\n" ;
	cout<<"\t\t\t\t\t\t\t  !!!  ACCOUNT DETAILS ARE DISPLAYED BELOW  !!!\n\n\n" ;

	cout<<"\t NAME : " ;
//	cout<<users_data[username].get_name()<<"\n\n" ;
	cout<<name<<"\n\n" ;

	cout<<"\t USERNAME : " ;
//	cout<<users_data[username].get_username()<<"\n\n" ;
	cout<<username<<"\n\n" ;

	cout<<"\t PASSWORD : " ;
//	cout<<users_data[username].get_password()<<"\n\n" ;
	cout<<password<<"\n\n" ;

    Validate_Input validator ;
	string verdict = "xxx" ; // 'return to home page' option number is the default option .
	while( validator.validate_number(verdict,1,2) == 0 ){
		cout<<"\n\n\t  SELECT ANY OF THE FOLLOWING OPTIONS TO PERFORM THE CORRESPONDING OPTION :\n\n" ;
		cout<<"\t1 -> EDIT PROFILE \n\n" ;
		cout<<"\t2 -> RETURN TO HOMEPAGE \n\n" ;
		cout<<"\t ENTERED OPTION = " ;
        cin>>ws ;
		getline(cin,verdict) ;
		if( validator.validate_number(verdict,1,2) == 0 ){
			cout<<"\t  Please enter an appropriate option number .\n" ;
		}
	}

    int option_number = validator.validate_number( verdict , 1 , 2 ) ;

	if( option_number == 1 ){
        cout<<"\n\n\t\t\t\t\t\t\tDirecting you to 'EDIT PROFILE' option now ........................\n\n" ;
  //      Sleep(3000) ;
		edit_profile( users_data , app_notifications ) ;
	}
	else if( option_number == 2 ){
        cout<<"\n\n\t\t\t\t\t\t\tDirecting to your account homepage now ..................\n\n" ;
  //      Sleep(3000) ;
		select_features( users_data , app_notifications , 1 ) ;
	}
}

void User::edit_profile( map<string,User> &users_data , map< string , vector<Notification> > &app_notifications ){
    Validate_Input validator ;
    string ch ;
    int option_number = 0 ;
	do{
        system("cls") ;
        cout<<"\n\n" ;
        cout<<"\t\t\t\t\t\t\t\t  !!!  EDITING PROFILE DETAILS  !!!\n\n\n" ;

        cout<<"\n\n\t SELECT AMONG THE FOLLOWING OPTIONS TO PERFORM THE CORRESPONDING ACTIVITY :\n\n" ;
		cout<<"\t1 -> EDIT NAME \n\n" ;
		cout<<"\t2 -> EDIT USERNAME \n\n" ;
		cout<<"\t3 -> EDIT PASSWORD \n\n" ;
		cout<<"\t4 -> RETURN TO HOMEPAGE \n\n" ;
		cout<<"\t ENTERED OPTION = " ;
    	cin>>ws ;
        getline(cin,ch) ;

        if( validator.validate_number(ch,1,4) == 0 ){
            cout<<"\t Please enter an appropriate option number .\n" ;
            continue ;
        }
        option_number = validator.validate_number(ch,1,4) ;

    	switch(option_number){
    		case 1:{
//              cout<<"Success \n" ;
    			update_name( users_data ) ;
				break;
			}
			case 2:{
//              cout<<"Success \n" ;
    			update_username( users_data , app_notifications ) ;
				break;
			}
			case 3:{
//              cout<<"Success \n" ;
    			update_password( users_data ) ;
				break;
			}
            case 4:{
                option_number = 4 ;
                cout<<"\n\n\t\t\t\t\t\t\tDirecting to your account homepage now ..................\n\n" ;
        //        Sleep(3000) ;
                break ;
            }
			default:{
                cout<<"\t Please enter an appropriate option number .\n" ;
				break;
			}
		}

	}
	while( option_number != 4 ) ;
}

void User::update_name( map< string , User> &users_data ){
    system("cls") ;
    cout<<"\n\n" ;
	cout<<"\t\t\t\t\t\t\t\t  !!!  EDITING 'NAME' FOR ACCOUNT  !!!\n\n\n" ;

    Validate_Input validator ;
	string new_name ;
	int mistake = 0 , z = 0 ;
	cout<<"\n\n\n\t Instructions for 'Name' change in account -> The constraints on the format of the 'Name' are as follows :\n\n" ;
    cout<<"\t(1) It should contain only upper-case and lower-case English letters .\n\n" ;
    cout<<"\t(2) Blank spaces are allowed .\n\n" ;

    // Do-While loop for appropriate name .
    mistake = 0 ;
    do{
    	if( mistake == 0 ){
	    	cout<<"\n\n\tPlease enter a new name : " ;
		}
		else{
        	cout<<"\n\n\tPlease enter a valid new name : " ;
		}
		cin>>ws ;
    	getline(cin,new_name) ;

		int flag = 0 ;
		for(int i=0 ; i<new_name.size() ; i++){
			if( (int)new_name[i] == 32 || ( (int)new_name[i] >= 65 && (int)new_name[i] <= 90 )
			|| ( (int)new_name[i] >= 97 && (int)new_name[i] <= 122 )  ){
				// it is ok .
			}
			else{
                mistake++ ;
				flag++ ;
				break ;
			}
		}

		if( flag == 0 ){
			z ++ ;
		}

    }
	while(z!=1) ;

	users_data[username].set_name( new_name ) ; // Changes for User's profile are updated here .
	name = new_name ;

    cout<<"\n\n\t\t\t\t\t\t\t !!!  'NAME' IN YOUR ACCOUNT HAS BEEN CHANGED SUCCESSFULLY  !!! "<<endl ;
    cout<<"\n\n\t\t\t\t\t\t\tDirecting you to 'EDIT PROFILE' option now ........................\n\n" ;
  //  Sleep(3000) ;
}

void User::update_username( map<string,User> &users_data , map< string , vector<Notification> > &app_notifications ){
    system("cls") ;
    cout<<"\n\n" ;
	cout<<"\t\t\t\t\t\t\t\t  !!!  EDITING 'USERNAME' FOR ACCOUNT  !!!\n\n\n" ;
	string new_username ;
	int up = 0 , low = 0 , num = 0 , mistake = 0 ;

    cout<<"\n\n\n\t Instructions for 'Username' change in account -> The constraints on the format of the 'Username' are as follows :\n\n" ;
    cout<<"\t(1) It should contain atleast 8 characters and atmost 15 characters .\n\n" ;
    cout<<"\t(2) It should not contain any blank spaces in between .\n\n" ;
	cout<<"\t(3) It should contain atleast 1 upper-case letter, 1 lower-case letter and 1 numeric digit .\n\n" ;
	cout<<"\t(4) It should not contain any other special character .\n\n" ;
    cout<<"\t(5) It should not match with any of the usernames of the existing users .\n\n" ;

    // Do-While loop for appropriate username .
    mistake = 0 ;
    do{
    	if( mistake == 0 ){
	    	cout<<"\n\n\tPlease enter a new username : " ;
		}
		else{
        	cout<<"\n\n\tPlease enter a valid new username : " ;
		}
		cin>>ws ;
    	getline(cin,new_username) ;

    	if( new_username.size() < 8 ){
			cout<<"\t Length of username is too short .\n";
			mistake ++ ;
        	continue ;
    	}
    	else if( new_username.size() > 15 ){
			cout<<"\t Length of username is too long .\n";
			mistake ++ ;
        	continue ;
    	}
        else if( users_data.find( new_username ) != users_data.end() ){
            cout<<"\t The entered username already exists. Please choose another username .\n" ;
            mistake ++ ;
            continue ;
        }
    	else{
    		int break_flag = 0 ;
            up = 0 , low = 0 , num = 0 ;
        	for(int i=0; i<new_username.length(); i++){
        		if( (int)new_username[i] >= 48 && (int)new_username[i] <= 57){
            		num++;
        		}
        		else if( (int)new_username[i] >= 65 && (int)new_username[i] <= 90){
					up++;
        		}
        		else if( (int)new_username[i] >= 97 && (int)new_username[i] <= 122){
            		low++;
        		}
        		else{
//					cout<<"wrong2\n";
					num = 0 , low = 0 , up = 0 , break_flag ++ ;
					break ;
        		}
        	}
        	if( (break_flag != 0) || ( num == 0 ) || ( low == 0 ) || ( up == 0 ) ){
//              cout<<"Gone in break_flag condition .\n" ;
        		mistake ++ ;
        		continue ;
			}
    	}

    }
	while(num == 0 || up == 0 || low == 0) ;

    // Process to change the username throughout the application data (begins here) .
        // Steps are as follows :
        // (1) Own object in map1
        // (2) All occurrences of this username in others profiles of map1 .
        // (3) Own object in map2
        // (4) All occurrences of this username in others profiles of map2 .
    string old_username = username ;

        // Step 1 :
    User temp_user = users_data[ old_username ] ;
    temp_user.set_username( new_username ) ;
    users_data.erase( old_username ) ;
    users_data[ new_username ] = temp_user ;
	username = new_username ;

        // Step 2 :
    for( auto it = users_data.begin() ; it != users_data.end() ; it++ ){
        if( it->first != new_username ){
            User t_user = users_data[ it->first ] ;

            vector<Appointment> seeker_vector = t_user.get_seeker_vector() ;
            for(int i=0 ; i<seeker_vector.size() ; i++){
                if( seeker_vector[i].get_user_name() == old_username ){
                    seeker_vector[i].set_user_name( new_username ) ;
                }
            }
            t_user.set_seeker_vector( seeker_vector ) ;

            vector<Appointment> acceptor_vector = t_user.get_acceptor_vector() ;
            for(int i=0 ; i<acceptor_vector.size() ; i++){
                if( acceptor_vector[i].get_user_name() == old_username ){
                    acceptor_vector[i].set_user_name( new_username ) ;
                }
            }
            t_user.set_acceptor_vector( acceptor_vector ) ;

            users_data[ it->first ] = t_user ;
        }
    }

        // Step 3 :
    vector<Notification> temp_notifications = app_notifications[ old_username ] ;
    app_notifications.erase( old_username ) ;
    app_notifications[ new_username ] = temp_notifications ;

        // Step 4 :
    for( auto it = app_notifications.begin() ; it != app_notifications.end() ; it++ ){
        if( it->first != new_username ){
            vector<Notification> t_notifications = app_notifications[ it->first ] ;

            for( int i=0 ; i<t_notifications.size() ; i++ ){
                if( t_notifications[i].get_appointment_notification().get_user_name() == old_username ){
                    Appointment t_appt = t_notifications[i].get_appointment_notification() ;
                    t_appt.set_user_name( new_username ) ;
                    t_notifications[i].set_notification_by_appointment( t_appt ) ;
                }
            }

            app_notifications[ it->first ] = t_notifications ;
        }
    }

    // Process to change the username throughout the application data (begins here) .

    cout<<"\n\n\t\t\t\t\t\t\t !!!  'USERNAME' IN YOUR ACCOUNT HAS BEEN CHANGED SUCCESSFULLY  !!! "<<endl ;
    cout<<"\n\n\t\t\t\t\t\t\tDirecting you to 'EDIT PROFILE' option now ........................\n\n" ;
  //  Sleep(3000) ;
}

void User::update_password( map<string,User> &users_data ){
    system("cls") ;
    cout<<"\n\n" ;
	cout<<"\t\t\t\t\t\t\t\t  !!!  EDITING 'PASSWORD' FOR ACCOUNT  !!!\n\n\n" ;

	string new_password ;
	int mistake = 0 , z = 0 ;
	cout<<"\n\n\n\t Instruction for 'Password' change in account -> " ;
	cout<<"The constraints on the format of the 'Password' are as follows :\n\n" ;
    cout<<"\t(1) It should contain atleast 8 characters .\n\n" ;

    // Do-While loop for appropriate password .
    mistake = 0 ;
    do{
    	if( mistake == 0 ){
	    	cout<<"\n\n\tPlease enter a new password : " ;
		}
		else{
        	cout<<"\n\n\tPlease enter a valid new password : " ;
		}
		cin>>ws ;
    	getline(cin,new_password) ;

    	if(new_password.length() < 8){
            cout<<"\t Entered Password is too short .\n" ;
			mistake ++ ;
			continue ;
    	}
    	else{
        	z++;
    	}
    }
	while(z!=1) ;

	users_data[username].set_password( new_password ) ; // Changes for User's profile are updated here .
	password = new_password ;

    cout<<"\n\n\t\t\t\t\t\t\t !!!  'PASSWORD' IN YOUR ACCOUNT HAS BEEN CHANGED SUCCESSFULLY  !!! "<<endl ;
    cout<<"\n\n\t\t\t\t\t\t\tDirecting you to 'EDIT PROFILE' option now ........................\n\n" ;
   // Sleep(3000) ;
}

void User::logout( int &option_number ){
	option_number = 7 ;
    return ;
}

void User::select_features( map<string,User> &users_data , map<string, vector<Notification> > &app_notifications , bool exit ){
	if( exit == 1 ){
		return ;
	}
    Validate_Input validator ;
	string p ;
    int option_number = 0 ;
    do{
        system("cls") ;
        cout<<"\n\n     *************************************************************  WELCOME TO YOUR ACCOUNT HOMEPAGE  ************************************************************* ";

    	cout<<"\n\n\n\t SELECT AMONG THE FOLLOWING OPTIONS TO PERFORM THE CORRESPONDING ACTIVITY : \n\n\n" ;

        cout<<"\t1 -> REQUEST APPOINTMENT \n\n" ;
        cout<<"\t2 -> CANCEL APPOINTMENT \n\n" ;
        cout<<"\t3 -> VIEW PROFILE \n\n" ;
        cout<<"\t4 -> EDIT PROFILE \n\n" ;
        cout<<"\t5 -> VIEW SCHEDULE \n\n" ;
        cout<<"\t6 -> VIEW ALL APPOINTMENTS \n\n" ;
        cout<<"\t7 -> LOGOUT \n\n" ;

		cout<<"\t ENTERED OPTION = " ;

        cin>>ws ;
        getline(cin,p) ;

        if( validator.validate_number(p,1,7) == 0 ){
            cout<<"\n\n\t Please enter an appropriate option ." ;
            continue ;
        }
        option_number = validator.validate_number(p,1,7) ;

        switch(option_number){
            case 1 :{
//              cout<<"\nIn branch for request appointment function .\n" ;
                Seeker user_as_seeker ;
                user_as_seeker.request_appointment( *this , users_data , app_notifications );
//              cout<<"\nOut request appointment function now .\n" ;
                break ;
			}
            case 2 :{
//              cout<<"\nIn branch for cancel appointment function .\n" ;
                Seeker user_as_seeker ;
                user_as_seeker.cancel_appointment( *this , users_data , 1 );
//              cout<<"\nOut of cancel appointment function .\n" ;
                break ;
			}
            case 3 :{
//              cout<<"\nIn branch for view profile function .\n" ;
                view_profile( users_data , app_notifications ) ;
//              cout<<"\nOut of view profile function .\n" ;
                break ;
			}
            case 4 :{
//              cout<<"\nIn branch for edit profile function .\n" ;
                edit_profile( users_data , app_notifications ) ;
//              cout<<"\nOut of edit profile function .\n" ;
                break ;
			}
            case 5 :{
//              cout<<"\nIn branch for view schedule function .\n" ;
                view_schedule( users_data );
//              cout<<"\nOut of view schedule function .\n" ;
                break ;
			}
            case 6 :{
//              cout<<"\nIn branch for view all appointments function .\n" ;
                view_all_appointments( users_data , app_notifications ) ;
//              cout<<"\nOut of view all appointments function .\n" ;
                break ;
			}
            case 7 :{
//              cout<<"\nIn branch for logout function .\n" ;
                logout( option_number ) ;
                cout<<"\n\n\t\t\t\t\t\tDirecting you to the application homepage now .....................\n\n" ;
         //       Sleep(3000) ;
//              cout<<"\nOut of logout function .\n" ;
                break ;
			}
            default:{
                cout<<"\n\n\t Please enter an appropriate option . " ;
                break ;
			}
        }

    }
	while( option_number != 7 ) ;
}


void User::print_appointments( User &current_user , vector<Appointment>& given_appts ){
    // The Item type row is printed as below .
	cout<<"\t+" ;
	for(int i=1 ; i<=111 ; i++)cout<<"-";
	cout<<"+\n" ;
	string s = "\t| Index No. |     Username      |  Appointment Type  |  Date(dd-mm-yyyy)  |              Time Slot              |\n" ;
	cout<<s ;
	cout<<"\t+" ;
	for(int i=1 ; i<=111 ; i++)cout<<"-";
	cout<<"+\n" ;

    // Keeping and setting data of Appointments to print (begins here) .
    vector<Appointment> temp_appts = given_appts ;
    sort( temp_appts.begin() , temp_appts.end() ) ;
    current_user.set_seeker_vector( temp_appts ) ;
    // Keeping and setting data of Appointments to print (ends here) .

    // Date is filled in the table as followed .

    for(int i=0 ; i<temp_appts.size() ; i++){
        Date d1 = temp_appts[i].get_date_of_appt() ;
        int add1 = 0 , add2 = 0 ;
        if( d1.get_day()<10 ) add1++ ;
        if( d1.get_month()<10 ) add1++ ;
        stringstream ss ;
        ss<<i+1 ;
        string index_num = ss.str() , t_username = temp_appts[i].get_user_name() ;
        string appt_type = temp_appts[i].get_appt_type() ;
        string sp1( 6 -index_num.size(),' ') , sp2(15-t_username.size(),' ') ;
        string sp3(12 - appt_type.size() ,' ') , sp4(3+add1,' ') ;
        cout<<"\t|"<<sp1+index_num<<"     |  " ;
        cout<<t_username+sp2 ;
        cout<<"  |\t"<<appt_type+sp3<<" |\t" ;
        cout<<d1.get_day()<<" - "<<d1.get_month()<<" - "<<d1.get_year()<<" ";
        cout<<sp4<<"|  " ;
        Time st_time = temp_appts[i].get_slot_of_appt().get_start_time() ;
        Time ed_time = temp_appts[i].get_slot_of_appt().get_end_time() ;
        Slot tp_slot ;
        tp_slot.set_slot( st_time , ed_time ) ;
        tp_slot.get_start_time().show_time();
        cout<<"     to     ";
        tp_slot.get_end_time().show_time();
        if( tp_slot.get_start_time().get_hour()<10 ) add2++ ;
        if( tp_slot.get_end_time().get_hour()<10 ) add2++ ;
        string sp5(2+add2,' ') ;
        cout<<sp5<<" |\n" ;
    }

	cout<<"\t+" ;
	for(int i=1 ; i<=111 ; i++)cout<<"-";
	cout<<"+\n" ;
}

void User::view_all_appointments( map<string,User> &users_data , map< string , vector<Notification> > &app_notifications ){
    system("cls") ;
    cout<<"\n\n" ;
	cout<<"\t\t\t\t\t\t\t\t  !!!  SHOWING ALL APPOINTMENTS AS FOLLOWS  !!!\n\n" ;
    User &current_user = users_data[ username ] ;
    Validate_Input validator ;

    // Filling all appointments in a vector .
    vector<Appointment> all_appointments = current_user.get_seeker_vector() ;
    vector<Appointment> temp_acceptor_appointments = current_user.get_acceptor_vector() ;
    all_appointments.insert( all_appointments.end() , temp_acceptor_appointments.begin() , temp_acceptor_appointments.end() ) ;
    sort( all_appointments.begin() , all_appointments.end() ) ;

    // Printing all appointments as follows .
    print_appointments( current_user , all_appointments ) ;

	string verdict = "Some value" ;
	while( validator.validate_number(verdict,1,3) == 0 ){
		cout<<"\n\n\n\t SELECT ANY OF THE FOLLOWING OPTIONS TO PERFORM THE CORRESPONDING ACTION :\n\n" ;
		cout<<"\t1 -> REQUEST APPOINTMENT \n\n" ;
		cout<<"\t2 -> CANCEL APPOINTMENT \n\n" ;
		cout<<"\t3 -> RETURN TO HOMEPAGE \n\n" ;
		cout<<"\t ENTERED OPTION = " ;
        cin>>ws ;
		getline(cin,verdict) ;
		if( validator.validate_number(verdict,1,3) == 0 ){
			cout<<"\n\n\tPlease enter an appropriate option number ." ;
		}
	}

    int option_number = validator.validate_number( verdict , 1 , 3 ) ;

    Seeker user_as_seeker ;
    if( option_number == 1 ){
        cout<<"\n\n\t\t\t\t\t\t\tDirecting you to 'REQUEST APPOINTMENT' option now ........................\n\n" ;
    //    Sleep(3000) ;
        user_as_seeker.request_appointment( current_user , users_data , app_notifications ) ;
    }
	else if( option_number == 2 ){
        cout<<"\n\n\t\t\t\t\t\t\tDirecting you to 'CANCEL APPOINTMENT' option now ........................\n\n" ;
      //  Sleep(3000) ;
		user_as_seeker.cancel_appointment( current_user , users_data , 1 ) ;
	}
	else if( option_number == 3 ){
        cout<<"\n\n\t\t\t\t\t\t\tDirecting to your account homepage now ...................\n\n" ;
     //   Sleep(3000) ;
		return ;
	}
}

void User::view_schedule( map<string,User> &users_data ){
    int repeat = 0 ;
    Validate_Input validator ;
    User cur_user = users_data[ username ] ;
    Date given_date = validator.get_todays_date() ;

    LOOP :
    system("cls") ;
    cout<<"\n\n" ;
	cout<<"\t\t\t\t\t\t\t\t  !!!  SHOWING ALL APPOINTMENTS AS FOLLOWS  !!!\n\n\n" ;

    string date_status ;
    if( repeat == 0 ){
        date_status = "CURRENT DATE" ;
    }
    else{
        date_status = "GIVEN DATE" ;
    }

    cout<<"THE SCHEDULE OF THE NEXT 5 WORKING DAYS FROM THE "<<date_status<<" ( ";
    given_date.show_date() ;
    cout<<") IS SHOWN AS FOLLOWS :\n\n" ;

    vector<Date> working_days ;
    for(int i=0 ; i<5 ; i++){
        working_days.pb( validator.date_of_nth_working_day( given_date , i ) ) ;
    }

    // Printing the date row ( begins here ) .
    string sp1( 25 , ' ' ) ;
	cout<<"\t+" ;
	for(int i=1 ; i<=151 ; i++)cout<<"-" ;
	cout<<"+\n" ;

    cout<<"\t|"<<sp1<<" |" ;
    for(int i=0 ; i<5 ; i++){
        string sp2(5,' ') ;
        cout<<sp2 ;
        if( working_days[i].get_day()<10 ){
            cout<<"0" ;
            cout<<working_days[i].get_day()<<" - " ;
        }
        else{
            cout<<working_days[i].get_day()<<" - " ;
        }
        if( working_days[i].get_month()<10 ){
            cout<<"0" ;
            cout<<working_days[i].get_month()<<" - " ;
        }
        else{
            cout<<working_days[i].get_month()<<" - " ;
        }
        cout<<working_days[i].get_year()<<sp2<<"|" ;
    }
    cout<<"\n" ;

	cout<<"\t+" ;
	for(int i=1 ; i<=151 ; i++)cout<<"-" ;
	cout<<"+\n" ;
    // Printing the date row ( ends here ) .

        // ---------------------

    // Printing contents of the table ( begins here ) .

        for( int i=0 ; i<8 ; i++ ){
            switch(i){
                case 0 :{
                    cout<<"\t|  09:00 am  to  10:00 am  |" ;
                    for(int j=0 ; j<5 ; j++){
                        Date t_date = working_days[j] ;
                        Time st_time , ed_time ;
                        st_time.set_time_data( 9,0,"am" ) , ed_time.set_time_data( 10,0,"am" ) ;
                        Slot t_slot ;
                        t_slot.set_slot( st_time , ed_time ) ;
                        string content ="           -            |" , val ;

                        int found = 0 ;
                        vector<Appointment> temp_appts = cur_user.get_seeker_vector() ;
                        for(int k=0 ; ( k<temp_appts.size() ) && ( found == 0 ) ; k++){
                            if( ( t_date.is_equal( temp_appts[k].get_date_of_appt() ) ) && ( t_slot.is_slot_equal( temp_appts[k].get_slot_of_appt() ) ) ){
                                found ++ ;
                                val = temp_appts[k].get_user_name() ;
                            }
                        }
                        temp_appts = cur_user.get_acceptor_vector() ;
                        for(int k=0 ; ( k<temp_appts.size() ) && ( found == 0 ) ; k++){
                            if( ( t_date.is_equal( temp_appts[k].get_date_of_appt() ) ) && ( t_slot.is_slot_equal( temp_appts[k].get_slot_of_appt() ) ) ){
                                found ++ ;
                                val = temp_appts[k].get_user_name() ;
                            }
                        }

                        if( found>0 ){
                            string sp11(4,' ') , sp12( 20-val.size() , ' ' ) ;
                            sp11 += val ;
                            sp11 += sp12 ;
                            sp11 += "|" ;
                            content = sp11 ;
                        }
                        cout<<content ;
                    }
                    cout<<"\n" ;
                    break ;
                }
                case 1 :{
                    cout<<"\t|  10:00 am  to  11:00 am  |" ;
                    for(int j=0 ; j<5 ; j++){
                        Date t_date = working_days[j] ;
                        Time st_time , ed_time ;
                        st_time.set_time_data( 10,0,"am" ) , ed_time.set_time_data( 11,0,"am" ) ;
                        Slot t_slot ;
                        t_slot.set_slot( st_time , ed_time ) ;
                        string content ="           -            |" , val ;

                        int found = 0 ;
                        vector<Appointment> temp_appts = cur_user.get_seeker_vector() ;
                        for(int k=0 ; ( k<temp_appts.size() ) && ( found == 0 ) ; k++){
                            if( ( t_date.is_equal( temp_appts[k].get_date_of_appt() ) ) && ( t_slot.is_slot_equal( temp_appts[k].get_slot_of_appt() ) ) ){
                                found ++ ;
                                val = temp_appts[k].get_user_name() ;
                            }
                        }
                        temp_appts = cur_user.get_acceptor_vector() ;
                        for(int k=0 ; ( k<temp_appts.size() ) && ( found == 0 ) ; k++){
                            if( ( t_date.is_equal( temp_appts[k].get_date_of_appt() ) ) && ( t_slot.is_slot_equal( temp_appts[k].get_slot_of_appt() ) ) ){
                                found ++ ;
                                val = temp_appts[k].get_user_name() ;
                            }
                        }

                        if( found>0 ){
                            string sp11(4,' ') , sp12( 20-val.size() , ' ' ) ;
                            sp11 += val ;
                            sp11 += sp12 ;
                            sp11 += "|" ;
                            content = sp11 ;
                        }
                        cout<<content ;
                    }
                    cout<<"\n" ;
                    break ;
                }
                case 2 :{
                    cout<<"\t|  11:00 am  to  12:00 pm  |" ;
                    for(int j=0 ; j<5 ; j++){
                        Date t_date = working_days[j] ;
                        Time st_time , ed_time ;
                        st_time.set_time_data( 11,0,"am" ) , ed_time.set_time_data( 12,0,"pm" ) ;
                        Slot t_slot ;
                        t_slot.set_slot( st_time , ed_time ) ;
                        string content ="           -            |" , val ;

                        int found = 0 ;
                        vector<Appointment> temp_appts = cur_user.get_seeker_vector() ;
                        for(int k=0 ; ( k<temp_appts.size() ) && ( found == 0 ) ; k++){
                            if( ( t_date.is_equal( temp_appts[k].get_date_of_appt() ) ) && ( t_slot.is_slot_equal( temp_appts[k].get_slot_of_appt() ) ) ){
                                found ++ ;
                                val = temp_appts[k].get_user_name() ;
                            }
                        }
                        temp_appts = cur_user.get_acceptor_vector() ;
                        for(int k=0 ; ( k<temp_appts.size() ) && ( found == 0 ) ; k++){
                            if( ( t_date.is_equal( temp_appts[k].get_date_of_appt() ) ) && ( t_slot.is_slot_equal( temp_appts[k].get_slot_of_appt() ) ) ){
                                found ++ ;
                                val = temp_appts[k].get_user_name() ;
                            }
                        }

                        if( found>0 ){
                            string sp11(4,' ') , sp12( 20-val.size() , ' ' ) ;
                            sp11 += val ;
                            sp11 += sp12 ;
                            sp11 += "|" ;
                            content = sp11 ;
                        }
                        cout<<content ;
                    }
                    cout<<"\n" ;
                    break ;
                }
                case 3 :{
                    cout<<"\t|  12:00 pm  to  01:00 pm  |" ;
                    for(int j=0 ; j<5 ; j++){
                        Date t_date = working_days[j] ;
                        Time st_time , ed_time ;
                        st_time.set_time_data( 12,0,"pm" ) , ed_time.set_time_data( 1,0,"pm" ) ;
                        Slot t_slot ;
                        t_slot.set_slot( st_time , ed_time ) ;
                        string content ="           -            |" , val ;

                        int found = 0 ;
                        vector<Appointment> temp_appts = cur_user.get_seeker_vector() ;
                        for(int k=0 ; ( k<temp_appts.size() ) && ( found == 0 ) ; k++){
                            if( ( t_date.is_equal( temp_appts[k].get_date_of_appt() ) ) && ( t_slot.is_slot_equal( temp_appts[k].get_slot_of_appt() ) ) ){
                                found ++ ;
                                val = temp_appts[k].get_user_name() ;
                            }
                        }
                        temp_appts = cur_user.get_acceptor_vector() ;
                        for(int k=0 ; ( k<temp_appts.size() ) && ( found == 0 ) ; k++){
                            if( ( t_date.is_equal( temp_appts[k].get_date_of_appt() ) ) && ( t_slot.is_slot_equal( temp_appts[k].get_slot_of_appt() ) ) ){
                                found ++ ;
                                val = temp_appts[k].get_user_name() ;
                            }
                        }

                        if( found>0 ){
                            string sp11(4,' ') , sp12( 20-val.size() , ' ' ) ;
                            sp11 += val ;
                            sp11 += sp12 ;
                            sp11 += "|" ;
                            content = sp11 ;
                        }
                        cout<<content ;
                    }
                    cout<<"\n" ;
                    break ;
                }
                case 4 :{
                    cout<<"\t|  01:00 pm  to  02:00 pm  |" ;
                    for(int j=0 ; j<5 ; j++){
                        Date t_date = working_days[j] ;
                        Time st_time , ed_time ;
                        st_time.set_time_data( 1,0,"pm" ) , ed_time.set_time_data( 2,0,"pm" ) ;
                        Slot t_slot ;
                        t_slot.set_slot( st_time , ed_time ) ;
                        string content ="           -            |" , val ;

                        int found = 0 ;
                        vector<Appointment> temp_appts = cur_user.get_seeker_vector() ;
                        for(int k=0 ; ( k<temp_appts.size() ) && ( found == 0 ) ; k++){
                            if( ( t_date.is_equal( temp_appts[k].get_date_of_appt() ) ) && ( t_slot.is_slot_equal( temp_appts[k].get_slot_of_appt() ) ) ){
                                found ++ ;
                                val = temp_appts[k].get_user_name() ;
                            }
                        }
                        temp_appts = cur_user.get_acceptor_vector() ;
                        for(int k=0 ; ( k<temp_appts.size() ) && ( found == 0 ) ; k++){
                            if( ( t_date.is_equal( temp_appts[k].get_date_of_appt() ) ) && ( t_slot.is_slot_equal( temp_appts[k].get_slot_of_appt() ) ) ){
                                found ++ ;
                                val = temp_appts[k].get_user_name() ;
                            }
                        }

                        if( found>0 ){
                            string sp11(4,' ') , sp12( 20-val.size() , ' ' ) ;
                            sp11 += val ;
                            sp11 += sp12 ;
                            sp11 += "|" ;
                            content = sp11 ;
                        }
                        cout<<content ;
                    }
                    cout<<"\n" ;
                    break ;
                }
                case 5 :{
                    cout<<"\t|  02:00 pm  to  03:00 pm  |" ;
                    for(int j=0 ; j<5 ; j++){
                        Date t_date = working_days[j] ;
                        Time st_time , ed_time ;
                        st_time.set_time_data( 2,0,"pm" ) , ed_time.set_time_data( 3,0,"pm" ) ;
                        Slot t_slot ;
                        t_slot.set_slot( st_time , ed_time ) ;
                        string content ="           -            |" , val ;

                        int found = 0 ;
                        vector<Appointment> temp_appts = cur_user.get_seeker_vector() ;
                        for(int k=0 ; ( k<temp_appts.size() ) && ( found == 0 ) ; k++){
                            if( ( t_date.is_equal( temp_appts[k].get_date_of_appt() ) ) && ( t_slot.is_slot_equal( temp_appts[k].get_slot_of_appt() ) ) ){
                                found ++ ;
                                val = temp_appts[k].get_user_name() ;
                            }
                        }
                        temp_appts = cur_user.get_acceptor_vector() ;
                        for(int k=0 ; ( k<temp_appts.size() ) && ( found == 0 ) ; k++){
                            if( ( t_date.is_equal( temp_appts[k].get_date_of_appt() ) ) && ( t_slot.is_slot_equal( temp_appts[k].get_slot_of_appt() ) ) ){
                                found ++ ;
                                val = temp_appts[k].get_user_name() ;
                            }
                        }

                        if( found>0 ){
                            string sp11(4,' ') , sp12( 20-val.size() , ' ' ) ;
                            sp11 += val ;
                            sp11 += sp12 ;
                            sp11 += "|" ;
                            content = sp11 ;
                        }
                        cout<<content ;
                    }
                    cout<<"\n" ;
                    break ;
                }
                case 6 :{
                    cout<<"\t|  03:00 pm  to  04:00 pm  |" ;
                    for(int j=0 ; j<5 ; j++){
                        Date t_date = working_days[j] ;
                        Time st_time , ed_time ;
                        st_time.set_time_data( 3,0,"pm" ) , ed_time.set_time_data( 4,0,"pm" ) ;
                        Slot t_slot ;
                        t_slot.set_slot( st_time , ed_time ) ;
                        string content ="           -            |" , val ;

                        int found = 0 ;
                        vector<Appointment> temp_appts = cur_user.get_seeker_vector() ;
                        for(int k=0 ; ( k<temp_appts.size() ) && ( found == 0 ) ; k++){
                            if( ( t_date.is_equal( temp_appts[k].get_date_of_appt() ) ) && ( t_slot.is_slot_equal( temp_appts[k].get_slot_of_appt() ) ) ){
                                found ++ ;
                                val = temp_appts[k].get_user_name() ;
                            }
                        }
                        temp_appts = cur_user.get_acceptor_vector() ;
                        for(int k=0 ; ( k<temp_appts.size() ) && ( found == 0 ) ; k++){
                            if( ( t_date.is_equal( temp_appts[k].get_date_of_appt() ) ) && ( t_slot.is_slot_equal( temp_appts[k].get_slot_of_appt() ) ) ){
                                found ++ ;
                                val = temp_appts[k].get_user_name() ;
                            }
                        }

                        if( found>0 ){
                            string sp11(4,' ') , sp12( 20-val.size() , ' ' ) ;
                            sp11 += val ;
                            sp11 += sp12 ;
                            sp11 += "|" ;
                            content = sp11 ;
                        }
                        cout<<content ;
                    }
                    cout<<"\n" ;
                    break ;
                }
                case 7 :{
                    cout<<"\t|  04:00 pm  to  05:00 pm  |" ;
                    for(int j=0 ; j<5 ; j++){
                        Date t_date = working_days[j] ;
                        Time st_time , ed_time ;
                        st_time.set_time_data( 4,0,"pm" ) , ed_time.set_time_data( 5,0,"pm" ) ;
                        Slot t_slot ;
                        t_slot.set_slot( st_time , ed_time ) ;
                        string content ="           -            |" , val ;

                        int found = 0 ;
                        vector<Appointment> temp_appts = cur_user.get_seeker_vector() ;
                        for(int k=0 ; ( k<temp_appts.size() ) && ( found == 0 ) ; k++){
                            if( ( t_date.is_equal( temp_appts[k].get_date_of_appt() ) ) && ( t_slot.is_slot_equal( temp_appts[k].get_slot_of_appt() ) ) ){
                                found ++ ;
                                val = temp_appts[k].get_user_name() ;
                            }
                        }
                        temp_appts = cur_user.get_acceptor_vector() ;
                        for(int k=0 ; ( k<temp_appts.size() ) && ( found == 0 ) ; k++){
                            if( ( t_date.is_equal( temp_appts[k].get_date_of_appt() ) ) && ( t_slot.is_slot_equal( temp_appts[k].get_slot_of_appt() ) ) ){
                                found ++ ;
                                val = temp_appts[k].get_user_name() ;
                            }
                        }

                        if( found>0 ){
                            string sp11(4,' ') , sp12( 20-val.size() , ' ' ) ;
                            sp11 += val ;
                            sp11 += sp12 ;
                            sp11 += "|" ;
                            content = sp11 ;
                        }
                        cout<<content ;
                    }
                    cout<<"\n" ;
                    break ;
                }
            }
        }

    // Printing contents of the table ( ends here ) .

       // ----------------------

    // Printing final border ( begins here ) .
	cout<<"\t+" ;
	for(int i=1 ; i<=151 ; i++)cout<<"-" ;
	cout<<"+\n" ;
    // Printing final border ( ends here ) .

        // ---------------------

    // Giving option to loop back in this function is as follows .
    cout<<"\n" ;
	string verdict = "Some value" ; // 'return to home page' option number is the default option .
	while( validator.validate_number(verdict,1,2) == 0 ){
		cout<<"\n\n\t SELECT ANY OF THE FOLLOWING OPTIONS TO PERFORM THE CORRESPONDING OPTION :\n\n\n" ;
		cout<<"\t1 -> VIEW SCHEDULE FROM GIVEN DATE \n\n" ;
		cout<<"\t2 -> RETURN TO HOMEPAGE \n\n" ;
		cout<<" ENTERED OPTION = " ;
        cin>>ws ;
		getline(cin,verdict) ;
		if( validator.validate_number(verdict,1,2) == 0 ){
			cout<<"\n\n\tPlease enter an appropriate option number ." ;
		}
	}

    int option_number = validator.validate_number( verdict , 1 , 2 ) ;

	if( option_number == 1 ){
        vector<Date> valid_dates ;
        Date range_start = validator.date_of_nth_working_day( validator.get_todays_date() , 0 ) ;
        Date range_end = validator.date_of_nth_working_day( validator.get_todays_date() , 60 ) ;

        for(int i=0 ; i<=60 ; i++){
            Date temp_date = validator.date_of_nth_working_day( validator.get_todays_date() , i ) ;
            valid_dates.pb( temp_date ) ;
        }

        cout<<"\n\n\t YOU MAY SELECT ANY DATE WHICH IS A WORKING DAY , TO VIEW YOUR SCHEDULE FOR THE NEXT 5 WORKING DAYS " ;
        cout<<"FROM THE GIVEN DATE , \n\n" ;
        cout<<"\tFrom (Date Format : dd-mm-yyyy ) : " ;
        range_start.show_date() ;
        cout<<"\n\tTo   (Date Format : dd-mm-yyyy ) : " ;
        range_end.show_date() ;
        cout<<"\n\n" ;

        cout<<"\t NOW , ENTER THE DATE OF YOUR CHOICE AS FOLLOWS :\n\n" ;

        int ddi , mmi , yyi ;
        string ip ;

        // Taking appropriate input for day .
        LOOP_BACK :

        cout<<"\tENTER THE DAY FOR YOUR APPOINTMENT DATE = " ;
        cin>>ws ;
        getline( cin , ip ) ;
        ddi = validator.validate_number( ip , 1 , 31 ) ;
        cout<<"\n" ;

        cout<<"\tENTER THE MONTH FOR YOUR APPOINTMENT DATE = " ;
        cin>>ws ;
        getline( cin , ip ) ;
        mmi = validator.validate_number( ip , 1 , 12 ) ;
        cout<<"\n" ;

        cout<<"\tENTER THE YEAR FOR YOUR APPOINTMENT DATE = " ;
        cin>>ws ;
        getline( cin , ip ) ;
        yyi = validator.validate_number( ip , range_start.get_year() , range_end.get_year() ) ;
        cout<<"\n" ;

        //  cout<<"ddi = "<<ddi<<" mmi = "<<mmi<<" yyi = "<<yyi<<"\n" ;

        if( (ddi != 0) && (mmi != 0) && (yyi != 0) ){
            if( ddi>=1 && ddi<=validator.get_days_in_month( mmi , yyi ) ){
                Date temp_date( ddi , mmi , yyi ) ;
                bool found = 0 ;
                for(int i=0 ; i<valid_dates.size() ; i++){
                    if( valid_dates[i] == temp_date ){
                        found = 1 ;
                        break ;
                    }
                }
                if( found ){
                    given_date.set_date_data1( temp_date ) ;
//                  cout<<"A valid date is chosen .\n\n" ;
                }
                else{
                    cout<<"\n\n\t Enter a valid date ." ;
                    goto LOOP_BACK ;
                }
            }
            else{
                cout<<"\n\n\t Enter a valid date ." ;
                goto LOOP_BACK ;
            }
        }
        else{
            cout<<"\n\n\t Enter a valid date ." ;
            goto LOOP_BACK ;
        }

        repeat ++ ;
        goto LOOP ;
	}
	else if( option_number == 2 ){
		return ;
	}
}

