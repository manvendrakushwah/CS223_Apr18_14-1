#include <bits/stdc++.h>

#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <dos.h>
#include <windows.h>

#include "File_Handling.h"

#define pb push_back
#define mp make_pair

using namespace std ;

void File_Handling::set_slot_index( vector< pair<Slot,bool> > &slot_index ){
    Time temp_start , temp_end ;
    Slot temp_slot ;
    pair<Slot,bool> temp_pair ;

    temp_start.set_time_data(9,0,"am") , temp_end.set_time_data(10,0,"am") , temp_slot.set_slot(temp_start,temp_end) ;
    temp_pair.first = temp_slot , temp_pair.second = 0 , slot_index.pb( temp_pair ) ;

    temp_start.set_time_data(10,0,"am") , temp_end.set_time_data(11,0,"am") , temp_slot.set_slot(temp_start,temp_end) ;
    temp_pair.first = temp_slot , temp_pair.second = 0 , slot_index.pb( temp_pair ) ;

    temp_start.set_time_data(11,0,"am") , temp_end.set_time_data(12,0,"pm") , temp_slot.set_slot(temp_start,temp_end) ;
    temp_pair.first = temp_slot , temp_pair.second = 0 , slot_index.pb( temp_pair ) ;

    temp_start.set_time_data(12,0,"pm") , temp_end.set_time_data(1,0,"pm") , temp_slot.set_slot(temp_start,temp_end) ;
    temp_pair.first = temp_slot , temp_pair.second = 0 , slot_index.pb( temp_pair ) ;

    temp_start.set_time_data(1,0,"pm") , temp_end.set_time_data(2,0,"pm") , temp_slot.set_slot(temp_start,temp_end) ;
    temp_pair.first = temp_slot , temp_pair.second = 0 , slot_index.pb( temp_pair ) ;

    temp_start.set_time_data(2,0,"pm") , temp_end.set_time_data(3,0,"pm") , temp_slot.set_slot(temp_start,temp_end) ;
    temp_pair.first = temp_slot , temp_pair.second = 0 , slot_index.pb( temp_pair ) ;

    temp_start.set_time_data(3,0,"pm") , temp_end.set_time_data(4,0,"pm") , temp_slot.set_slot(temp_start,temp_end) ;
    temp_pair.first = temp_slot , temp_pair.second = 0 , slot_index.pb( temp_pair ) ;

    temp_start.set_time_data(4,0,"pm") , temp_end.set_time_data(5,0,"pm") , temp_slot.set_slot(temp_start,temp_end) ;
    temp_pair.first = temp_slot , temp_pair.second = 0 , slot_index.pb( temp_pair ) ;
}

void File_Handling::set_application_data_part1( Interface &app , vector< pair<Slot,bool> > &slot_index ){
    Validate_Input validator ;
    Date current_date = validator.get_todays_date() ;
    ifstream ip1("Users_Data_final.csv") ;
    vector< User > user_profiles ;
    vector< Calendar_Data > user_prof_Calendar ;
    Calendar_Data cd , empty_cd ;
    int z=0 ;

    while( ip1.good() ){
    	string temp1 ;
    	getline(ip1,temp1,',') ;
		if( isdigit(temp1[0]) == 0 ){
        	string name_s = temp1 , username_s , password_s ;
        	getline(ip1,username_s,',') ;
            getline(ip1,password_s,'\n');

        	if( name_s.empty() ){
				break ;
        	}

			User us1 ;
        	us1.set_profile_data( name_s , username_s , password_s ) ;
        	user_profiles.pb(us1) ;

			if( z==0 ){
				z++ ;
        	}
        	else{
//              cout<<"gone here.\n" ;
				user_prof_Calendar.pb( cd ) ;
				cd = empty_cd ;
			}
        }
        else{
			string mms , yys , bits ;
        	getline(ip1,mms,',') , getline(ip1,yys,',') , getline(ip1,bits,'\n') ;
			int ddi = atoi( temp1.c_str() ) ;
            int mmi = atoi( mms.c_str() ) ;
            int yyi = atoi( yys.c_str() ) ;
			bitset<8> bt( bits ) ;
			Date d11(ddi,mmi,yyi) ;
			cd.add_in_date_vector(d11) , cd.add_in_appts_vector(bt) ;
		}
    }

	user_prof_Calendar.pb( cd ) ;
	cd = empty_cd ;

    // Data retrieval from Users_Data_final.csv (ends here) .

//	cout<<"size1 = "<<user_profiles.size()<<"\n" ;
//	cout<<"size2 = "<<user_prof_Calendar.size()<<"\n" ;

    // Filling data in map1 of Interface object (begins here) .

	for(int i=0 ; i<user_profiles.size() ; i++){
		Calendar temp_cal = user_profiles[i].get_timeline() ;
		temp_cal.set_cal( user_prof_Calendar[i].get_cal_dates( ) , user_prof_Calendar[i].get_appts() ) ;
        // Automate Calendar (begins here) ;
        map< Date , vector< pair <Slot,bool> > > temp_map = temp_cal.get_cal() ;

            // Erasing older dates than today (begins here) .
        vector< map< Date , vector< pair <Slot,bool> > >::iterator > map_iterators ;
        for( auto it = temp_map.begin() ; it != temp_map.end() ; it++ ){
            if( it->first < current_date ){
                map_iterators.pb( it ) ;
            }
        }

        for( int j=0 ; j<map_iterators.size() ; j++ ){
            temp_map.erase( map_iterators[j] ) ;
        }
            // Erasing older dates than today (ends here) .

            // Initializing the next 120 working days for each user (begins here) .
        for( int j=0 ; j<=120 ; j++ ){
            Date temp_date = validator.date_of_nth_working_day( current_date , j ) ;
            if( temp_map.find( temp_date ) == temp_map.end() ){
                temp_map[ temp_date ] = slot_index ;
            }
        }
            // Initializing the next 120 working days for each user (ends here) .

        temp_cal.set_cal1( temp_map ) ;
        // Automate Calendar (ends here) ;
		user_profiles[i].set_timeline( temp_cal ) ;
	}

//  print_vector( user_profiles ) ;

    app ;
    app.set_users_data( user_profiles ) ;
}

void File_Handling::set_application_data_part2( Interface &app ){
    Validate_Input validator ;
    ifstream ip2("Users_Appointment_Data_final.csv") ;
    map<string,User> temp_users_data = app.get_users_data() ;
    map<string, vector<Notification> > temp_app_notifications ;

    while( ip2.good() ){
        string temp_username ;
        getline( ip2 , temp_username , '\n' ) ;
        User temp_user = temp_users_data[ temp_username ] ;
        // Order of Data per User .
          //  (1) As_Seeker Appointments .
          //  (2) As_Acceptor Appointments .
          //  (3) User Notifications .
        if( temp_username.empty() ){
            break ;
        }

        // (1) As_Seeker Appointments .
        string cnt1 ;
        getline( ip2 , cnt1 , '\n' ) ;
        int count1 = atoi( cnt1.c_str() ) ;
        for(int i=0 ; i<count1 ; i++){
            string temp_appt_username , temp_appt_type , dd , mm , yy , t_hour , t_minutes , t_am_pm ;
            Time temp_start_time , temp_end_time ;
            getline(ip2,temp_appt_username,',') , getline(ip2,temp_appt_type,',') ;
            getline(ip2,dd,',') , getline(ip2,mm,',') , getline(ip2,yy,',') ;
            Date temp_appt_date( atoi(dd.c_str()) , atoi(mm.c_str()) , atoi(yy.c_str()) ) ;
            getline(ip2,t_hour,',') , getline(ip2,t_minutes,',') , getline(ip2,t_am_pm,',') ;
            temp_start_time.set_time_data( atoi( t_hour.c_str() ) , atoi( t_minutes.c_str() ) , t_am_pm ) ;
            getline(ip2,t_hour,',') , getline(ip2,t_minutes,',') , getline(ip2,t_am_pm,'\n') ;
            temp_end_time.set_time_data( atoi( t_hour.c_str() ) , atoi( t_minutes.c_str() ) , t_am_pm ) ;
            Slot temp_appt_slot ;
            temp_appt_slot.set_slot( temp_start_time , temp_end_time ) ;
            Appointment temp_appt( temp_appt_username , temp_appt_type , temp_appt_date , temp_appt_slot ) ;
            if( ( validator.get_todays_date() < temp_appt.get_date_of_appt()  ) ||
                ( temp_appt.get_date_of_appt() == validator.get_todays_date() ) ){
                temp_user.add_appt_to_seeker_vector( temp_appt ) ;
            }
        }

        // (2) As_Acceptor Appointments .
        string cnt2 ;
        getline( ip2 , cnt2 , '\n' ) ;
        int count2 = atoi( cnt2.c_str() ) ;
        for(int i=0 ; i<count2 ; i++){
            string temp_appt_username , temp_appt_type , dd , mm , yy , t_hour , t_minutes , t_am_pm ;
            Time temp_start_time , temp_end_time ;
            getline(ip2,temp_appt_username,',') , getline(ip2,temp_appt_type,',') ;
            getline(ip2,dd,',') , getline(ip2,mm,',') , getline(ip2,yy,',') ;
            Date temp_appt_date( atoi(dd.c_str()) , atoi(mm.c_str()) , atoi(yy.c_str()) ) ;
            getline(ip2,t_hour,',') , getline(ip2,t_minutes,',') , getline(ip2,t_am_pm,',') ;
            temp_start_time.set_time_data( atoi( t_hour.c_str() ) , atoi( t_minutes.c_str() ) , t_am_pm ) ;
            getline(ip2,t_hour,',') , getline(ip2,t_minutes,',') , getline(ip2,t_am_pm,'\n') ;
            temp_end_time.set_time_data( atoi( t_hour.c_str() ) , atoi( t_minutes.c_str() ) , t_am_pm ) ;
            Slot temp_appt_slot ;
            temp_appt_slot.set_slot( temp_start_time , temp_end_time ) ;
            Appointment temp_appt( temp_appt_username , temp_appt_type , temp_appt_date , temp_appt_slot ) ;
            if( ( validator.get_todays_date() < temp_appt.get_date_of_appt() ) ||
                ( temp_appt.get_date_of_appt() == validator.get_todays_date() ) ){
                temp_user.add_appt_to_acceptor_vector( temp_appt ) ;
            }
        }

        // (3) User Notifications .
        vector<Notification> temp_notifications_vector ;
        string cnt3 ;
        getline( ip2 , cnt3 , '\n' ) ;
        int count3 = atoi( cnt3.c_str() ) ;
        for(int i=0 ; i<count3 ; i++){
            string temp_appt_username , temp_appt_type , dd , mm , yy , t_hour , t_minutes , t_am_pm ;
            Time temp_start_time , temp_end_time ;
            getline(ip2,temp_appt_username,',') , getline(ip2,temp_appt_type,',') ;
            getline(ip2,dd,',') , getline(ip2,mm,',') , getline(ip2,yy,',') ;
            Date temp_appt_date( atoi(dd.c_str()) , atoi(mm.c_str()) , atoi(yy.c_str()) ) ;
            getline(ip2,t_hour,',') , getline(ip2,t_minutes,',') , getline(ip2,t_am_pm,',') ;
            temp_start_time.set_time_data( atoi( t_hour.c_str() ) , atoi( t_minutes.c_str() ) , t_am_pm ) ;
            getline(ip2,t_hour,',') , getline(ip2,t_minutes,',') , getline(ip2,t_am_pm,'\n') ;
            temp_end_time.set_time_data( atoi( t_hour.c_str() ) , atoi( t_minutes.c_str() ) , t_am_pm ) ;
            Slot temp_appt_slot ;
            temp_appt_slot.set_slot( temp_start_time , temp_end_time ) ;
            Appointment temp_appt( temp_appt_username , temp_appt_type , temp_appt_date , temp_appt_slot ) ;
            Notification temp_N ;
            if( ( validator.get_todays_date() < temp_appt.get_date_of_appt()  ) ||
               ( temp_appt.get_date_of_appt() == validator.get_todays_date() ) ){
                temp_N.set_notification_by_appointment( temp_appt ) , temp_notifications_vector.pb( temp_N ) ;
            }
        }

        // Inserting Data in containers .
        temp_users_data[ temp_username ] = temp_user , temp_app_notifications[ temp_username ] = temp_notifications_vector ;
        temp_notifications_vector.clear() ;
    }

    app.set_app_notifications( temp_app_notifications ) ;
    app.set_appointment_data( temp_users_data ) ;
}

void File_Handling::get_application_data_part1( Interface &app ){
	ofstream op1 ;
	op1.open("Users_Data_final.csv") ;
	map<string,User> users_data_copy = app.get_users_data();
    map< string , vector<Notification> > app_notifications_copy = app.get_app_notifications() ;

	for( auto it1 = users_data_copy.begin() ; it1 != users_data_copy.end() ; it1++ ){
		User temp_user = it1->second ;
        if( temp_user.get_username().empty() ){
            continue ;
        }
		op1<<temp_user.get_name()<<","<<temp_user.get_username()<<","<<temp_user.get_password()<<"\n";
		Calendar t_cal = temp_user.get_timeline() ;
		map< Date , vector<pair<Slot,bool> > > temp_cal = t_cal.get_cal() ;
		for( auto it2 = temp_cal.begin() ; it2 != temp_cal.end() ; it2++ ){
			Date temp_date = it2->first ;
			op1<<temp_date.get_day()<<","<<temp_date.get_month()<<","<<temp_date.get_year()<<",";
			vector< pair<Slot,bool> > temp_vector = it2->second ;
			for(int i=0 ; i<temp_vector.size() ; i++){
				op1<<temp_vector[i].second ;
			}
			op1<<"\n" ;
		}
	}

	op1.close() ;
}

void File_Handling::get_application_data_part2( Interface &app ){
	map<string,User> users_data_copy = app.get_users_data();
    map< string , vector<Notification> > app_notifications_copy = app.get_app_notifications() ;
    ofstream op2 ;
    op2.open("Users_Appointment_Data_final.csv") ;

    auto it11 = users_data_copy.begin() ;
    auto it12 = app_notifications_copy.begin() ;

//    cout<<"\n" ;
//    cout<<"\nSize of map 1 = "<<users_data_copy.size() ;
//    cout<<"\nSize of map 2 = "<<app_notifications_copy.size() ;

	for(  ; it11 != users_data_copy.end() ; it11++ ){
//      cout<<"In Loop .\n" ;
		User temp_user = it11->second ;
        if( temp_user.get_username().empty() ){
            continue ;
        }
        cout<<"\n\n" ;
		op2<<temp_user.get_username()<<"\n" ;
//      cout<<"Username = "<<temp_user.get_username()<<"\n" ;
        vector< Appointment > temp_seeker_appts = temp_user.get_seeker_vector() ;
        vector< Appointment > temp_acceptor_appts = temp_user.get_acceptor_vector() ;
        vector< Notification > temp_user_notifications = app_notifications_copy[ temp_user.get_username() ] ;

//      cout<<"Seeker Appointments = "<<temp_seeker_appts.size()<<"\n" ;
//      cout<<"Acceptor Appointments = "<<temp_acceptor_appts.size()<<"\n" ;
//      cout<<"Appointment Notifications = "<<temp_user_notifications.size()<<"\n" ;

        // Seeker Appointments .
        op2<<temp_seeker_appts.size()<<"\n" ;
        for(int i=0 ; i<temp_seeker_appts.size() ; i++){
            op2<<temp_seeker_appts[i].get_user_name()<<","<<temp_seeker_appts[i].get_appt_type()<<",";
            Date td1 = temp_seeker_appts[i].get_date_of_appt() ;
            op2<<td1.get_day()<<","<<td1.get_month()<<","<<td1.get_year()<<",";
            Slot te_slot = temp_seeker_appts[i].get_slot_of_appt() ;
            Time s_time = te_slot.get_start_time() , e_time = te_slot.get_end_time() ;
            op2<<s_time.get_hour()<<","<<s_time.get_minutes()<<","<<s_time.get_am_pm()<<"," ;
            op2<<e_time.get_hour()<<","<<e_time.get_minutes()<<","<<e_time.get_am_pm()<<"\n" ;
        }

        // Acceptor Appointments .
        op2<<temp_acceptor_appts.size()<<"\n" ;
        for(int i=0 ; i<temp_acceptor_appts.size() ; i++){
            op2<<temp_acceptor_appts[i].get_user_name()<<","<<temp_acceptor_appts[i].get_appt_type()<<",";
            Date td1 = temp_acceptor_appts[i].get_date_of_appt() ;
            op2<<td1.get_day()<<","<<td1.get_month()<<","<<td1.get_year()<<",";
            Slot te_slot = temp_acceptor_appts[i].get_slot_of_appt() ;
            Time s_time = te_slot.get_start_time() , e_time = te_slot.get_end_time() ;
            op2<<s_time.get_hour()<<","<<s_time.get_minutes()<<","<<s_time.get_am_pm()<<"," ;
            op2<<e_time.get_hour()<<","<<e_time.get_minutes()<<","<<e_time.get_am_pm()<<"\n" ;
        }

        // Appointment Notifications .
        op2<<temp_user_notifications.size()<<"\n" ;
        for(int i=0 ; i<temp_user_notifications.size() ; i++){
            Appointment t_appt = temp_user_notifications[i].get_appointment_notification() ;
            op2<<t_appt.get_user_name()<<","<<t_appt.get_appt_type()<<",";
            Date td1 = t_appt.get_date_of_appt() ;
            op2<<td1.get_day()<<","<<td1.get_month()<<","<<td1.get_year()<<",";
            Slot te_slot = t_appt.get_slot_of_appt() ;
            Time s_time = te_slot.get_start_time() , e_time = te_slot.get_end_time() ;
            op2<<s_time.get_hour()<<","<<s_time.get_minutes()<<","<<s_time.get_am_pm()<<"," ;
            op2<<e_time.get_hour()<<","<<e_time.get_minutes()<<","<<e_time.get_am_pm()<<"\n" ;
        }

        temp_seeker_appts.clear() ;
        temp_acceptor_appts.clear() ;
        temp_user_notifications.clear() ;
	}

    op2.close() ;
}
