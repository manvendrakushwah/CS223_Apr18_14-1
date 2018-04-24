#include <bits/stdc++.h>
#include "Appointment.h"

using namespace std ;

#ifndef UNTITLED_NOTIFICATION_H
#define UNTITLED_NOTIFICATION_H

class Notification{
    private :
        Appointment appt_notification ;

    public :
        Notification() ;
        Appointment get_appointment_notification()const ;
        void set_notification_by_appointment( Appointment ) ;
};

bool operator < ( const Notification& , const Notification& ) ;

#endif
