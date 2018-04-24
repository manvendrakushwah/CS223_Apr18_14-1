#include <bits/stdc++.h>
#include "User.h"
#include "Notification.h"

using namespace std ;

#ifndef UNTITLED_ACCEPTOR_H
#define UNTITLED_ACCEPTOR_H

class Acceptor : public User{
    private :
        vector<Notification> user_notifications ;

    public :
        void accept_appointment( User& , User& , map<string,User>& , map< string , vector<Notification> >& , Appointment ) ;

//      void add_appt_notification( Notification ) ;
//      void add_notification( Notification , string ) ; // Notification details , Username .

        vector<Notification> get_notifications_vector() ;
        void set_notifications_vector( vector<Notification>& ) ;

        void process_notifications( User& , map< string , User >& , map< string , vector <Notification> >& ) ;
};

#endif

