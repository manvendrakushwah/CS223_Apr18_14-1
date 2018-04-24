#include <bits/stdc++.h>
#include "User.h"
#include "Notification.h"
#include "Validate_Input.h"
#include "Acceptor.h"
#include "Seeker.h"

using namespace std ;

#ifndef UNTITLED_INTERFACE_H
#define UNTITLED_INTERFACE_H

// Declarations .
class Interface{
    private:
        map<string,User> users_data ;
        map<string, vector<Notification> > app_notifications ;

    public:
        void create_account() ;
        void open_application() ;
        map<string,User> get_users_data() ;
        map< string , vector<Notification> > get_app_notifications() ;
        void update_database() ;
        User enter_login_credentials() ;
        bool verify_login_credentials( string , string ) ;

        void set_users_data( vector<User>& ) ;
        void set_app_notifications( map< string , vector<Notification> >& ) ;
        void set_appointment_data( map<string,User>& ) ;
};

#endif
