#include <bits/stdc++.h>
#include "Date.h"
#include "Slot.h"

using namespace std ;

#ifndef UNTITLED_APPOINTMENT_H
#define UNTITLED_APPOINTMENT_H

class Appointment{
	protected :
		string user_name ;
		string appt_type ;
		Date date_of_appt ;
		Slot slot_of_appt ;

	public :
        Appointment() ;
        Appointment(string,string,Date,Slot) ;
        bool is_appointment_equal( Appointment ) ;
		string get_user_name()const ;
		string get_appt_type()const ;
		Date get_date_of_appt()const ;
		Slot get_slot_of_appt()const ;

		void set_user_name( string ) ;
		void set_appt_type( string ) ;
		void set_date_of_appt( Date ) ;
		void set_slot_of_appt( Slot ) ;
		void set_appt_data( string , string , Date , Slot ) ;

        void print_time_slots() ;
};

bool operator < ( const Appointment &a , const Appointment &b ) ;

#endif
