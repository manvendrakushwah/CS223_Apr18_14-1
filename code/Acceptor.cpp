#include <bits/stdc++.h>

#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <dos.h>
#include <windows.h>

#include "Acceptor.h"
#include "Seeker.h"

#define pb push_back
#define mp make_pair

using namespace std ;

void Acceptor::set_notifications_vector( vector<Notification>& given_notifications ){
    for(int i=0 ; i < given_notifications.size() ; i++){
        if( binary_search( user_notifications.begin() , user_notifications.end() , given_notifications[i] ) == 0 ){
            user_notifications.pb( given_notifications[i] ) ;
        }
    }
    given_notifications.clear() ;
}

vector<Notification> Acceptor::get_notifications_vector(){
    return user_notifications ;
}

void Acceptor::process_notifications( User& current_user , map< string , User > &users_data ,
map< string , vector<Notification> > &app_notifications ){
    Validate_Input validator ;

    // Cancel Appointment provision for user , if he/she wants to make any time slots vacant ( begins here ) .
    if( current_user.get_seeker_vector().size() > 0 ){
        cout<<"\n\n\t BEFORE PROCEEDING TO YOUR NOTIFICATIONS , WE WOULD LIKE TO KNOW IF YOU WANT TO CANCEL ANY UNDESIRED " ;
        cout<<"APPOINTMENTS TO MAKE THOSE TIME SLOTS VACANT .\n\n" ;

        string verdict = "xxx" ;
        while( validator.validate_number(verdict,1,2) == 0 ){
            cout<<"\n\t SELECT ANY OF THE FOLLOWING OPTION TO PERFORM THE CORRESPONDING ACTIVITY :\n\n" ;
            cout<<"\t1 -> CANCEL APPOINTMENT\n\n" ;
            cout<<"\t2 -> PROCEED TO NOTIFICATIONS\n\n" ;
            cout<<"\t ENTERED OPTION = " ;
            cin>>ws ;
            getline(cin,verdict) ;
            if( validator.validate_number(verdict,1,2) == 0 ){
                cout<<"\tPlease enter an appropriate option number .\n" ;
            }
        }

        int option_number = validator.validate_number( verdict , 1 , 2 ) ;

        if( option_number == 1 ){
            LOOP :
            Seeker user_as_seeker ;
            user_as_seeker.cancel_appointment( current_user , users_data , 0 );
        }
        else if( option_number == 2 ){
            goto JUMP ;
        }

        cout<<"\n\n\t DO YOU WISH TO CANCEL ANOTHER APPOINTMENT ?\n\n" ;
        string verdict1 = "xxx" ;
        while( validator.validate_number(verdict1,1,2) == 0 ){
            cout<<"\t SELECT ANY OF THE FOLLOWING OPTION TO ANSWER THE ABOVE QUESTION :\n\n" ;
            cout<<"\t1 -> YES\n\n" ;
            cout<<"\t2 -> NO\n\n" ;
            cout<<"\t ENTERED OPTION = " ;
            cin>>ws ;
            getline(cin,verdict1) ;
            if( validator.validate_number(verdict1,1,2) == 0 ){
                cout<<"\tPlease enter an appropriate option number .\n" ;
            }
        }

        int option_number1 = validator.validate_number( verdict1 , 1 , 2 ) ;

        if( option_number1 == 1 ){
            goto LOOP ;
        }
    }

//  cout<<"\nIn process notifications function cancel provision is over now .\n\n" ;
    // Cancel Appointment provision for user , if he/she wants to make any time slots vacant ( ends here ) .

    JUMP :

    // Making notifications distinct (begins here) .
    set_notifications_vector( app_notifications[ current_user.get_username() ] ) ;
    // Making notifications distinct (ends here) .


    // Making sure to automatically reject the appt. requests where at-least on the users does not
    // have that slot vacant ( begins here ) .

//  cout<<"\nIn process notifications function next1 and final notifications are among = "<<user_notifications.size()<<"\n\n" ;
        // Criteria (1) : Old Notifications .
        // Criteria (2) : The Acceptor is busy in that certain Slot  .
        // Criteria (3) : The Seeker is busy in that certain Slot  .
    vector<Notification> final_notifications ;

    for( int i=0 ; i<user_notifications.size() ; i++ ){
        bool should_include = 1 ;
        Date cur_date = validator.get_todays_date() ;
        Date appt_date = user_notifications[i].get_appointment_notification().get_date_of_appt() ;
        Slot appt_slot = user_notifications[i].get_appointment_notification().get_slot_of_appt() ;
        User seeker_of_appt = users_data[ user_notifications[i].get_appointment_notification().get_user_name() ] ;

        // Criteria (1) .
        if( appt_date < cur_date ){
            should_include = 0 ;
///         cout<<"\nAppointment Date has gone by \n\n" ;
            continue ;
        }

        // Criteria (2) .
        vector<Appointment> temp_appts = current_user.get_seeker_vector() ;
        for(int j=0 ; j<temp_appts.size() ; j++){
            if( ( temp_appts[j].get_date_of_appt() == appt_date ) &&
               ( temp_appts[j].get_slot_of_appt().is_slot_equal( appt_slot ) ) ){
                should_include = 0 ;
            }
        }

        temp_appts = current_user.get_acceptor_vector() ;
        for(int j=0 ; j<temp_appts.size() ; j++){
            if( ( temp_appts[j].get_date_of_appt() == appt_date ) &&
               ( temp_appts[j].get_slot_of_appt().is_slot_equal( appt_slot ) ) ){
                should_include = 0 ;
            }
        }

        if( should_include == 0 ){
//          cout<<"\nAcceptor is busy in this slot\n\n" ;
            continue ;
        }

        // Criteria (3) .
        temp_appts = users_data[ user_notifications[i].get_appointment_notification().get_user_name() ].get_seeker_vector() ;
        for(int j=0 ; j<temp_appts.size() ; j++){
            if( ( temp_appts[j].get_date_of_appt() == appt_date ) &&
               ( temp_appts[j].get_slot_of_appt().is_slot_equal( appt_slot ) ) ){
                should_include = 0 ;
            }
        }

        temp_appts = users_data[ user_notifications[i].get_appointment_notification().get_user_name() ].get_acceptor_vector() ;
        for(int j=0 ; j<temp_appts.size() ; j++){
            if( ( temp_appts[j].get_date_of_appt() == appt_date ) &&
               ( temp_appts[j].get_slot_of_appt().is_slot_equal( appt_slot ) ) ){
                should_include = 0 ;
            }
        }

        if( should_include == 0 ){
//          cout<<"\nSeeker is busy in this slot\n\n" ;
            continue ;
        }

        if( should_include == 1 ){
            final_notifications.pb( user_notifications[i] ) ;
        }
    }

//  cout<<"\nIn process notifications function next2 and final notifications = "<<final_notifications.size()<<"\n\n" ;
    // Making sure to automatically reject the appt. requests where at-least on the users does not
    // have that slot vacant ( ends here ) .

    // We finally have the Appointments which need to be given a verdict by the acceptor .

    // Verdict Process ( begins here ) .

    if( final_notifications.size() > 0 ){
        cout<<"\n\n\t BEFORE PROCEEDING TO YOUR ACCOUNT HOMEPAGE , WE WOULD REQUEST YOU TO GIVE A VERDICT ON THE APPOINTMENT " ;
        cout<<"REQUESTS YOU HAVE RECEIVED .\n" ;

        for(int i=0 ; i<final_notifications.size() ; i++){
            cout<<"\n\n\t PROCESSING REQUEST NO. : "<<(i+1)<<" / "<<final_notifications.size()<<"\n\n" ;
            string verdict2 = "xxx" ;
            cout<<"\t APPOINTMENT DETAILS ARE AS FOLLOWS :- \n\n" ;
            cout<<"\t SEEKER USERNAME : "<<final_notifications[i].get_appointment_notification().get_user_name()<<"\n\n" ;
            cout<<"\t DATE OF APPOINTMENT (dd-mm-yyyy) : " ;
            final_notifications[i].get_appointment_notification().get_date_of_appt().show_date() ;
            cout<<"\n\n" ;
            Slot temp_slot =final_notifications[i].get_appointment_notification().get_slot_of_appt() ;
            cout<<"\t TIME SLOT : "<<temp_slot.get_start_time().get_hour()<<":00 "<<temp_slot.get_start_time().get_am_pm() ;
            cout<<"  to  "<<temp_slot.get_end_time().get_hour()<<":00 "<<temp_slot.get_end_time().get_am_pm() ;
            cout<<"\n\n" ;

            while( validator.validate_number(verdict2,1,2) == 0 ){
                cout<<"\n\t SELECT ANY OF THE FOLLOWING OPTION TO PERFORM THE CORRESPONDING ACTIVITY :\n\n" ;
                cout<<"\t1 -> ACCEPT APPOINTMENT\n\n" ;
                cout<<"\t2 -> DECLINE APPOINTMENT\n\n" ;
                cout<<"\t ENTERED OPTION = " ;
                cin>>ws ;
                getline(cin,verdict2) ;
                if( validator.validate_number(verdict2,1,2) == 0 ){
                    cout<<"\tPlease enter an appropriate option number .\n" ;
                }
            }

            int option_number2 = validator.validate_number( verdict2 , 1 , 2 ) ;

            if( option_number2 == 1 ){
                User &us2 = users_data[ final_notifications[i].get_appointment_notification().get_user_name() ] ;
                accept_appointment( current_user , us2 , users_data , app_notifications ,
                final_notifications[i].get_appointment_notification() ) ;
                cout<<"\n\n\t\t\t\t\t\t\t !!!  THIS APPOINTMENT HAS BEEN CONFIRMED SUCCESSFULLY  !!! "<<endl ;
            }
            else if( option_number2 == 2 ){
                cout<<"\n\n\t\t\t\t\t\t\t !!!  THIS APPOINTMENT HAS BEEN REJECTED SUCCESSFULLY  !!! "<<endl ;
            }
        }

    }
    else{
        cout<<"\n\n\tYOU HAVE NO NOTIFICATIONS OF REQUESTS FOR APPOINTMENTS AT THIS POINT OF TIME , DIRECTING YOU TO YOUR ACCOUNT ";
        cout<<"HOMEPAGE NOW .\n\n" ;
        Sleep(3000) ;
    }

    // Verdict Process ( ends here ) .
    cout<<"End of pre-processing . \n" ;

}

void Acceptor::accept_appointment( User &current_acceptor , User &current_seeker , map<string,User> &users_data ,
map< string , vector<Notification> > &app_notifications , Appointment current_appt  ){
    // Adding the appointment in the respective vectors .
    vector<Appointment> acceptor_appts = current_acceptor.get_acceptor_vector() ;
    current_appt.set_user_name( current_seeker.get_username() ) ;
    acceptor_appts.pb( current_appt ) ;
    current_acceptor.set_acceptor_vector( acceptor_appts ) ;

    vector<Appointment> seeker_appts = current_seeker.get_seeker_vector() ;
    current_appt.set_user_name( current_acceptor.get_username() ) ;
    seeker_appts.pb( current_appt ) ;
    current_seeker.set_seeker_vector( seeker_appts ) ;

    // Setting the calenders of the two users .
    map<int,int> slot_index ;
    slot_index[9] = 0 , slot_index[10] = 1 , slot_index[11] = 2 , slot_index[12] = 3 ;
    slot_index[1] = 4 , slot_index[2] = 5 , slot_index[3] = 6 , slot_index[4] = 7 ;


    Calendar time_line1 = current_acceptor.get_timeline() ;
    map< Date , vector< pair<Slot,bool> > > cal1 = time_line1.get_cal() ;
    vector< pair<Slot,bool> > day_slots1 = cal1[ current_appt.get_date_of_appt() ] ;
    day_slots1[ slot_index[ current_appt.get_slot_of_appt().get_start_time().get_hour() ] ].second = 1 ;
    cal1[ current_appt.get_date_of_appt() ] = day_slots1 ;
    time_line1.set_cal1( cal1 ) ;
    current_acceptor.set_timeline( time_line1 ) ;

    Calendar time_line2 = current_seeker.get_timeline() ;
    map< Date , vector< pair<Slot,bool> > > cal2 = time_line2.get_cal() ;
    vector< pair<Slot,bool> > day_slots2 = cal2[ current_appt.get_date_of_appt() ] ;
    day_slots2[ slot_index[ current_appt.get_slot_of_appt().get_start_time().get_hour() ] ].second = 1 ;
    cal2[ current_appt.get_date_of_appt() ] = day_slots2 ;
    time_line2.set_cal1( cal2 ) ;
    current_seeker.set_timeline( time_line2 ) ;

    // Updating final changes for both users in the first map .
    users_data[ current_acceptor.get_username() ] = current_acceptor ;
    users_data[ current_seeker.get_username() ] = current_seeker ;
}

