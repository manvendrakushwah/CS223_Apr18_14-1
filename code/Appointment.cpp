#include <bits/stdc++.h>

#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <dos.h>
#include <windows.h>

#include "Appointment.h"

#define pb push_back
#define mp make_pair

using namespace std ;

// Custom - made Comparator Function .
bool operator < ( const Appointment &a , const Appointment &b ){
    if( a.get_date_of_appt().get_day() == b.get_date_of_appt().get_day() ){
        if( a.get_date_of_appt().get_month() == b.get_date_of_appt().get_month() ){
            if( a.get_date_of_appt().get_year() == b.get_date_of_appt().get_year() ){
                int t1 = a.get_slot_of_appt().get_start_time().get_hour(),t2 = a.get_slot_of_appt().get_start_time().get_hour() ;
                bool y1 = 1 , y2 = 1 ;
                if( t1 >= 9 ){
                    y1 = 0 ;
                }
                if( t2 >= 9 ){
                    y2 = 0 ;
                }

                // four cases arise .
                if( y1 == 0 && y2 == 0 ){
                    return t1 < t2 ;
                }
                else if( y1 == 0 && y2 == 1 ){
                    return 1 ;
                }
                else if( y1 == 1 && y2 == 0 ){
                    return 0 ;
                }
                else{
                    return t1 < t2 ;
                }
            }
            return a.get_date_of_appt().get_year() < b.get_date_of_appt().get_year() ;
        }
        return a.get_date_of_appt().get_month() < b.get_date_of_appt().get_month() ;
    }
    return a.get_date_of_appt().get_day() < b.get_date_of_appt().get_day() ;
}

Appointment::Appointment(){
    Time empty_start_time , empty_end_time ;
    user_name = "" , appt_type = "" , date_of_appt.set_date_data(0,0,0) ;
    slot_of_appt.set_slot(empty_start_time,empty_end_time) ;
}

Appointment::Appointment( string given_username , string given_appt_type , Date given_date , Slot given_slot ){
    user_name = given_username , appt_type = given_appt_type , date_of_appt = given_date ;
    slot_of_appt = given_slot ;
}

bool Appointment::is_appointment_equal( Appointment given_appt ){
    int val = 0 ;
    if( user_name == given_appt.get_user_name() ){
        val++ ;
    }
    if( appt_type == given_appt.get_appt_type() ){
        val++ ;
    }
    if( date_of_appt.is_equal( given_appt.get_date_of_appt() ) ){
        val++ ;
    }
    if( slot_of_appt.is_slot_equal( given_appt.get_slot_of_appt() ) ){
        val++ ;
    }

    if( val == 4 ){
        return 1 ;
    }
    else{
        return 0 ;
    }
}

string Appointment::get_user_name()const{
	return user_name ;
}

string Appointment::get_appt_type()const{
	return appt_type ;
}

Date Appointment::get_date_of_appt()const{
	return date_of_appt ;
}

Slot Appointment::get_slot_of_appt()const{
	return slot_of_appt ;
}

void Appointment::set_user_name( string given_user_name ){
	user_name = given_user_name ;
}

void Appointment::set_appt_type( string given_appt_type ){
	appt_type = given_appt_type ;
}

void Appointment::set_date_of_appt( Date given_date_of_appt ){
	date_of_appt = given_date_of_appt ;
}

void Appointment::set_slot_of_appt( Slot given_slot_of_appt ){
	slot_of_appt = given_slot_of_appt ;
}

void Appointment::set_appt_data( string given_username , string given_appt_type , Date given_date , Slot given_slot ){
    user_name = given_username , appt_type = given_appt_type , date_of_appt = given_date ;
    slot_of_appt = given_slot ;
}

void Appointment::print_time_slots(){
	cout<<"\t+" ;
	for(int i=1 ; i<=42 ; i++)cout<<"-";
	cout<<"+\n" ;
	string s = "\t| Index No. |           Time Slot          |\n" ;
	cout<<s ;
	cout<<"\t+" ;
	for(int i=1 ; i<=42 ; i++)cout<<"-";
	cout<<"+\n" ;

    // Manually showing the slots (begins here) .
    cout<<"\t|     1     |  9:00  am    to    10:00 am  |\n" ;
    cout<<"\t|     2     |  10:00 am    to    11:00 am  |\n" ;
    cout<<"\t|     3     |  11:00 am    to    12:00 pm  |\n" ;
    cout<<"\t|     4     |  12:00 pm    to    1:00  pm  |\n" ;
    cout<<"\t|     5     |  1:00  pm    to    2:00  pm  |\n" ;
    cout<<"\t|     6     |  2:00  pm    to    3:00  pm  |\n" ;
    cout<<"\t|     7     |  3:00  pm    to    4:00  pm  |\n" ;
    cout<<"\t|     8     |  4:00  pm    to    5:00  pm  |\n" ;

    // Manually showing the slots (ends here) .

	cout<<"\t+" ;
	for(int i=1 ; i<=42 ; i++)cout<<"-";
	cout<<"+\n" ;
}
