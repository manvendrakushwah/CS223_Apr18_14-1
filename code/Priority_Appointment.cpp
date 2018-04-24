#include <bits/stdc++.h>

#include "Priority_Appointment.h"

#define pb push_back
#define mp make_pair

using namespace std ;

void Priority_Appointment::set_priority_appointment_data( Appointment given_appt ){
    user_name = given_appt.get_user_name() ;
    appt_type = given_appt.get_appt_type() ;
    date_of_appt = given_appt.get_date_of_appt() ;
    slot_of_appt = given_appt.get_slot_of_appt() ;
}

Appointment Priority_Appointment::get_priority_appointment_data(){
    Appointment temp_appt( user_name , appt_type , date_of_appt , slot_of_appt ) ;
    return temp_appt ;
}

Appointment Priority_Appointment::req_priority_appt(){
    // Till the call to this function User-name and Appointment type of the Appointment .
    Validate_Input validator ;

    // Step 1 : Take input of date of appointment .
    Date current_date = validator.get_todays_date() ;
    vector<Date> working_days(1,current_date) ;

    for( int i=1 ; i<=4 ; i++ ){
        working_days.pb( validator.date_of_nth_working_day( current_date , i ) ) ;
    }

    print_working_days( working_days ) ;

	string verdict = "xxx" ;
	while( validator.validate_number(verdict,1,4) == 0 ){
		cout<<"\n\n\t SELECT ANY ONE OF THE WORKING DAYS FOR APPOINTMENT BY IT'S INDEX NUMBER :\n\n" ;
		cout<<"\t ENTERED INDEX NUMBER = " ;
        cin>>ws ;
		getline(cin,verdict) ;
		if( validator.validate_number(verdict,1,4) == 0 ){
			cout<<"\tPlease enter an appropriate option number ." ;
		}
	}
    int option_number = validator.validate_number( verdict , 1 , 4 ) ;
    date_of_appt = working_days[ option_number ] ;

    // Step 2 : Take input of Slot of appointment .
    cout<<"\n\n" ;
    print_time_slots() ;

	string verdict1 = "xxx" ;
	while( validator.validate_number(verdict1,1,8) == 0 ){
		cout<<"\n\n\t SELECT ANY ONE OF THE TIME SLOTS FOR APPOINTMENT BY IT'S INDEX NUMBER :\n\n" ;
		cout<<"\t ENTERED INDEX NUMBER = " ;
        cin>>ws ;
		getline(cin,verdict1) ;
		if( validator.validate_number(verdict1,1,8) == 0 ){
			cout<<"\tPlease enter an appropriate option number .\n" ;
		}
	}
    int option_number1 = validator.validate_number( verdict1 , 1 , 8 ) ;

    // Manually filling the slot chosen in attribute (begins here) .

    Time t_start_time , t_end_time ;
    if( option_number1 == 1 ){
        t_start_time.set_time_data(9,0,"am") , t_end_time.set_time_data(10,0,"am") ;
    }
    else if( option_number1 == 2 ){
        t_start_time.set_time_data(10,0,"am") , t_end_time.set_time_data(11,0,"am") ;
    }
    else if( option_number1 == 3 ){
        t_start_time.set_time_data(11,0,"am") , t_end_time.set_time_data(12,0,"pm") ;
    }
    else if( option_number1 == 4 ){
        t_start_time.set_time_data(12,0,"pm") , t_end_time.set_time_data(1,0,"pm") ;
    }
    else if( option_number1 == 5 ){
        t_start_time.set_time_data(1,0,"pm") , t_end_time.set_time_data(2,0,"pm") ;
    }
    else if( option_number1 == 6 ){
        t_start_time.set_time_data(2,0,"pm") , t_end_time.set_time_data(3,0,"pm") ;
    }
    else if( option_number1 == 7 ){
        t_start_time.set_time_data(3,0,"pm") , t_end_time.set_time_data(4,0,"pm") ;
    }
    else if( option_number1 == 8 ){
        t_start_time.set_time_data(4,0,"pm") , t_end_time.set_time_data(5,0,"pm") ;
    }
    slot_of_appt.set_slot( t_start_time , t_end_time ) ;

    // Manually filling the slot chosen in attribute (ends here) .

    // Exit of this function .
    return get_priority_appointment_data() ;
}

void Priority_Appointment::print_working_days( vector<Date>& working_days ){
    cout<<"\n\tTHE CURRENT DATE : ";
    working_days[0].show_date() ;
    cout<<"\n\n" ;

	cout<<"\t+" ;
	for(int i=1 ; i<=38 ; i++)cout<<"-";
	cout<<"+\n" ;
	string s = "\t| Index No. |  Date( dd - mm - yyyy )  |\n" ;
	cout<<s ;
	cout<<"\t+" ;
	for(int i=1 ; i<=38 ; i++)cout<<"-";
	cout<<"+\n" ;

    for( int i=1 ; i<working_days.size() ; i++ ){
        stringstream ss ;
        ss<<i ;
        string index_num = ss.str() ;
        Date t_date = working_days[i] ;
        int add = 0 ;
        if( t_date.get_day()<10 ) add++ ;
        if( t_date.get_month()<10 ) add++ ;
        string sp1( 6 -index_num.size(),' ') , sp2(4+add,' ') ;
        cout<<"\t|"<<sp1+index_num<<"     |       " ;
        cout<<t_date.get_day()<<" - "<<t_date.get_month()<<" - "<<t_date.get_year()<<" " ;
        cout<<sp2<<"|\n" ;
    }

    cout<<"\t+" ;
	for(int i=1 ; i<=38 ; i++)cout<<"-";
	cout<<"+\n" ;
}

