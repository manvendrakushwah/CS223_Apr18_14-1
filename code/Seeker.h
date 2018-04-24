#include <bits/stdc++.h>
#include <time.h>
#include <unistd.h>
#include <cstdlib>

#include "User.h"
#include "Calendar.h"
#include "Slot.h"
#include "Appointment.h"
#include "Date.h"
#include "Notification.h"
#include "Priority_Appointment.h"
#include "Normal_Appointment.h"

using namespace std ;

#ifndef UNTITLED_SEEKER_H
#define UNTITLED_SEEKER_H

class Seeker:public User{
    public :
        void cancel_appointment( User& , map<string,User>& , bool ) ;
        void request_appointment( User& , map<string,User>& , map< string,vector<Notification> >& ) ;
        void print_users_list( User& , map<string,User>& , map<int,string>& ) ;
};

#endif
