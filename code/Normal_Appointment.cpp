#include <bits/stdc++.h>

#include "Normal_Appointment.h"

#define pb push_back
#define mp make_pair

using namespace std ;

void Normal_Appointment::set_normal_appointment_data( Appointment given_appt ){
    user_name = given_appt.get_user_name() ;
    appt_type = given_appt.get_appt_type() ;
    date_of_appt = given_appt.get_date_of_appt() ;
    slot_of_appt = given_appt.get_slot_of_appt() ;
}

Appointment Normal_Appointment::get_normal_appointment_data(){
    Appointment temp_appt( user_name , appt_type , date_of_appt , slot_of_appt ) ;
    return temp_appt ;
}

Appointment Normal_Appointment::req_normal_appt(){
    // Till the call to this function User-name and Appointment type of the Appointment .
    Validate_Input validator ;

    // Step 1 : Take input of date of appointment .
    Date range_start = validator.date_of_nth_working_day( validator.get_todays_date() , 5 ) ;
    Date range_end = validator.date_of_nth_working_day( validator.get_todays_date() , 60 ) ;
    vector<Date> valid_dates ;

    for(int i=5 ; i<=60 ; i++){
        Date temp_date = validator.date_of_nth_working_day( validator.get_todays_date() , i ) ;
        valid_dates.pb( temp_date ) ;
    }

    cout<<"\n\n\t YOU MAY SELECT ANY DATE WHICH IS A WORKING DAY , FOR YOUR APPOINTMENT RANGING \n\n" ;
    cout<<"\tFrom (Date Format : dd-mm-yyyy ) : " ;
    range_start.show_date() ;
    cout<<"\n\tTo   (Date Format : dd-mm-yyyy ) : " ;
    range_end.show_date() ;
    cout<<"\n\n" ;

    cout<<"\t NOW , ENTER THE DATE OF YOUR APPOINTMENT AS FOLLOWS :\n\n" ;

    int ddi , mmi , yyi ;
    string ip ;

    // Taking appropriate input for day .
    LOOP :

    cout<<"\tENTER THE DAY FOR YOUR APPOINTMENT DATE = " ;
    cin>>ws ;
    getline( cin , ip ) ;
    ddi = validator.validate_number( ip , 1 , 31 ) ;

    cout<<"\tENTER THE MONTH FOR YOUR APPOINTMENT DATE = " ;
    cin>>ws ;
    getline( cin , ip ) ;
    mmi = validator.validate_number( ip , 1 , 12 ) ;

    cout<<"\tENTER THE YEAR FOR YOUR APPOINTMENT DATE = " ;
    cin>>ws ;
    getline( cin , ip ) ;
    yyi = validator.validate_number( ip , range_start.get_year() , range_end.get_year() ) ;

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
                date_of_appt.set_date_data1( temp_date ) ;
//              cout<<"A valid date is chosen .\n\n" ;
            }
            else{
                cout<<"\tEnter a valid date .\n\n" ;
                goto LOOP ;
            }
        }
        else{
            cout<<"\tEnter a valid date .\n\n" ;
            goto LOOP ;
        }
    }
    else{
        cout<<"\tEnter a valid date .\n\n" ;
        goto LOOP ;
    }


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
    return get_normal_appointment_data() ;
}
