#include <bits/stdc++.h>
#include "Appointment.h"
#include "Validate_Input.h"

using namespace std ;

#ifndef UNTITLED_NORMAL_APPOINTMENT_H
#define UNTITLED_NORMAL_APPOINTMENT_H

// Declarations of Normal_Appointment Class are as follows .
class Normal_Appointment : public Appointment{
	public :
        void set_normal_appointment_data( Appointment ) ;
        Appointment get_normal_appointment_data() ;

		Appointment req_normal_appt() ;
};

#endif
