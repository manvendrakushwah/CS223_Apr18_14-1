#include <bits/stdc++.h>

#include "Notification.h"

#define pb push_back
#define mp make_pair

using namespace std ;

bool operator < ( const Notification& a ,const Notification &b ){
    return a.get_appointment_notification() < b.get_appointment_notification() ;
}

Notification::Notification(){
    Date temp_d ;
    Slot temp_sl ;
    appt_notification.set_appt_data("","",temp_d,temp_sl) ;
}

Appointment Notification::get_appointment_notification()const{
    return appt_notification ;
}

void Notification::set_notification_by_appointment( Appointment temp_appt ){
    appt_notification = temp_appt ;
}
