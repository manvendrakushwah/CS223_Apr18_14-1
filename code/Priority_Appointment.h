#include <bits/stdc++.h>
#include "Appointment.h"
#include "Validate_Input.h"
#include "User.h"

using namespace std ;

#ifndef UNTITLED_PRIORITY_APPOINTMENT_H
#define UNTITLED_PRIORITY_APPOINTMENT_H

// Declarations of Priority_Appointment Class are as follows .
class Priority_Appointment : public Appointment{
	public :
        void set_priority_appointment_data( Appointment ) ;
        Appointment get_priority_appointment_data() ;

		Appointment req_priority_appt() ;
        void print_working_days( vector<Date>& ) ;
};

#endif
