#include <bits/stdc++.h>
#include "Calendar.h"
#include "Appointment.h"
#include "Notification.h"
#include "Validate_Input.h"

using namespace std ;

#ifndef UNTITLED_USER_H
#define UNTITLED_USER_H

class User{
    protected:
        string name ;
        string username ;
        string password ;
    	Calendar timeline ;
        // Additional required attributes .
        vector<Appointment> as_seeker ;
        vector<Appointment> as_acceptor ;

    public:
        void view_schedule( map<string,User>& ) ;
        void view_all_appointments( map<string,User>& , map< string , vector<Notification> >& ) ;
        void print_appointments( User& , vector<Appointment>& ) ;

        void view_profile( map<string,User>& , map< string , vector<Notification> >& ) ;
        void edit_profile( map<string,User>& , map< string , vector<Notification> >& ) ;
        void update_name( map<string,User>& ) ;
        void update_username( map<string,User>& , map< string , vector<Notification> > & ) ;
        void update_password( map<string,User>& ) ;
        void logout( int& ) ;

        string get_name() ;
        string get_username() ;
        string get_password() ;
        Calendar get_timeline() ;

        void select_features( map<string,User>& , map< string , vector<Notification> >& , bool ) ; // equivalent to homepage .
        void set_name(string) ;
        void set_username(string) ;
        void set_password(string) ;
        void set_profile_data( string , string , string ) ;
        void set_timeline( Calendar ) ;

        // Functions for additional attributes .
        void set_seeker_vector( vector<Appointment> ) ;
        void add_appt_to_seeker_vector( Appointment ) ;
        vector<Appointment> get_seeker_vector() ;

        void set_acceptor_vector( vector<Appointment> ) ;
        void add_appt_to_acceptor_vector( Appointment ) ;
        vector<Appointment> get_acceptor_vector() ;

        // Additional features to the user .

};

#endif
