#include <bits/stdc++.h>

#include "Interface.h"

#define pb push_back
#define mp make_pair

using namespace std ;

// Functions of Interface Class are defined as follows .
map<string,User> Interface::get_users_data(){
	return users_data ;
}

map< string , vector<Notification> > Interface::get_app_notifications(){
    return app_notifications ;
}

void Interface::set_users_data( vector<User> &user_profiles ){
	for(int i=0 ; i<user_profiles.size() ; i++){
		users_data[ user_profiles[i].get_username() ] = user_profiles[i] ;
	}
}

void Interface::set_app_notifications( map< string , vector<Notification> > &given_notifications ){
    app_notifications = given_notifications ;
}

void Interface::set_appointment_data( map<string,User>&temp_users_data ){
    for( auto it = temp_users_data.begin() ; it != temp_users_data.end() ; it++ ){
        users_data[ it->first ].set_seeker_vector( temp_users_data[ it->first ].get_seeker_vector()  ) ;
        users_data[ it->first ].set_acceptor_vector( temp_users_data[ it->first ].get_acceptor_vector()  ) ;
    }
}

void Interface::open_application(){
    Validate_Input validator ;
    string a ;
    int option_number = 0 ;
    do{
        system("cls") ;
        cout<<"\n\n     ****************************************************  WELCOME TO MEETING APPOINTMENT SCHEDULER SOFTWARE  **************************************************** ";
    	cout<<"\n\n\n\t  SELECT AMONG THE FOLLOWING OPTIONS TO PERFORM THE CORRESPONDING ACTIVITY : " ;

    	cout<<"\n\n\t1 -> REGISTER" ;
		cout<<"\n\n\t2 -> LOG IN " ;
    	cout<<"\n\n\t3 -> EXIT " ;
    	cout<<"\n\n\t  ENTERED OPTION = " ;

        cin>>ws ;
        getline(cin,a) ;

        if( validator.validate_number(a,1,3) == 0 ){
            cout<<"\n\n\t Please enter an appropriate option number ." ;
            continue ;
        }
        option_number = validator.validate_number(a,1,3) ;

        switch(option_number){
            case 1 :{
                create_account();
//              cout<<"\nIn branch for 'create account' i.e. 1 -> REGISTER";
//              cout<<"\n\nOut of create_account function now .\n" ;
                break ;
            }
            case 2 :{
                User cur_user = enter_login_credentials() ;
                Acceptor user_as_acceptor ;
                user_as_acceptor.process_notifications( cur_user , users_data , app_notifications ) ;
                cur_user.select_features( users_data , app_notifications , 0 ) ;
//              cout<<"\nIn branch for 'login credentials' i.e. 2 -> LOG IN" ;
                break ;
            }
            case 3 :{
                // No need for log-out function here .
//              cout<<"\nIn branch for 'exit option' i.e. 3 -> EXIT" ;
                cout<<"\n\n\t\t\t\t\t\t\tExiting the application now .........................\n\n" ;
//                Sleep(3000) ;
                break ;
            }
            default:{
                cout<<"\n\n\t Please enter an appropriate option number .";
//              open_application();
                break ;
            }
        }

    }
	while( option_number != 3 ) ;
}

void Interface::create_account(){
    system("cls") ;
	cout<<"\n\n\t\t\t\t\t\t\t\t\t!!!  REGISTRATION BEGINS  !!!\n" ;
	cout<<"\n\t  THE PROCESS FOR ACCOUNT CREATION CONSISTS OF 3 STEPS WHICH ARE AS FOLLOWS :\n" ;
    Validate_Input validator ;
    string name , username , password ;
    int low = 0 , up = 0 , num = 0 , mistake = 0 ;
    int z1 = 0 , z2 = 0  ;

    cout<<"\n\n\t INSTRUCTIONS FOR STEP 1 -> The constraints on the format of the 'Name' are as follows :\n\n" ;
    cout<<"\t(1) It should contain only upper-case and lower-case English letters .\n\n" ;
    cout<<"\t(2) Blank spaces are allowed .\n\n" ;

    // Do-While loop for appropriate name .
    mistake = 0 ;
    do{
    	if( mistake == 0 ){
	    	cout<<"\n\n\tSTEP 1 -> Please enter your name : " ;
		}
		else{
        	cout<<"\n\n\tPlease enter a valid name : " ;
		}
		cin>>ws ;
    	getline(cin,name) ;

		int flag = 0 ;
		for(int i=0 ; i<name.size() ; i++){
			if( (int)name[i] == 32 || ( (int)name[i] >= 65 && (int)name[i] <= 90 )
			|| ( (int)name[i] >= 97 && (int)name[i] <= 122 )  ){
				// it is ok .
			}
			else{
                mistake ++ ;
				flag++ ;
				break ;
			}
		}

		if( flag == 0 ){
			z1 ++ ;
		}

    }
	while(z1!=1) ;


/*  // Testing cout line .
    cout<<"Name = "<<name<<"\n\n" ;
*/

    cout<<"\n\n\n\t INSTRUCTIONS FOR STEP 2 -> The constraints on the format of the 'Username' are as follows :\n\n" ;
    cout<<"\t(1) It should contain atleast 8 characters and atmost 15 characters .\n\n" ;
    cout<<"\t(2) It should not contain any blank spaces in between .\n\n" ;
	cout<<"\t(3) It should contain atleast 1 upper-case letter, 1 lower-case letter and 1 numeric digit .\n\n" ;
	cout<<"\t(4) It should not contain any other special character .\n\n" ;
    cout<<"\t(5) It should not match with any of the usernames of the existing users .\n\n" ;

    // Do-While loop for appropriate username .
    mistake = 0 ;
    do{
    	if( mistake == 0 ){
	    	cout<<"\n\n\tSTEP 2 -> Please enter your username : " ;
		}
		else{
        	cout<<"\n\n\tPlease enter a valid username : " ;
		}
		cin>>ws ;
    	getline(cin,username) ;

    	if( username.size() < 8 ){
			cout<<"\t Length of username is too short .\n";
			mistake ++ ;
        	continue ;
    	}
    	else if( username.size() > 15 ){
			cout<<"\t Length of username is too long .\n";
			mistake ++ ;
        	continue ;
    	}
        else if( users_data.find( username ) != users_data.end() ){
            cout<<"\t The entered username already exists. Please choose another username .\n" ;
            mistake ++ ;
            continue ;
        }
    	else{
    		int break_flag = 0 ;
            up = 0 , low = 0 , num = 0 ;
        	for(int i=0; i<username.length(); i++){
        		if( (int)username[i] >= 48 && (int)username[i] <= 57){
            		num++;
        		}
        		else if( (int)username[i] >= 65 && (int)username[i] <= 90){
					up++;
        		}
        		else if( (int)username[i] >= 97 && (int)username[i] <= 122){
            		low++;
        		}
        		else{
//					cout<<"wrong2\n";
					num = 0 , low = 0 , up = 0 , break_flag ++ ;
					break ;
        		}
        	}
        	if( (break_flag != 0) || ( num == 0 ) || ( low == 0 ) || ( up == 0 ) ){
                cout<<"\t Entered username doesn't comply with the format specified above . \n" ;
//              cout<<"Gone in break_flag condition .\n" ;
        		mistake ++ ;
        		continue ;
			}
    	}

    }
	while(num == 0 || up == 0 || low == 0) ;

    cout<<"\n\n\n\t INSTRUCTIONS FOR STEP 3 -> The constraints on the format of the 'Password' are as follows :\n\n" ;
    cout<<"\t(1) It should contain atleast 8 characters .\n\n" ;

    // Do-While loop for appropriate password .
    mistake = 0 ;
    do{
    	if( mistake == 0 ){
	    	cout<<"\n\n\tSTEP 3 -> Please enter your password : " ;
		}
		else{
        	cout<<"\n\n\tPlease enter a valid password : " ;
		}
		cin>>ws ;
    	getline(cin,password) ;

    	if( password.size() < 8){
            cout<<"\t Entered Password is too short .\n" ;
			mistake ++ ;
			continue ;
    	}
    	else{
        	cout<<"\n\n\t\t\t\t\t\t\t !!!  YOUR ACCOUNT HAS BEEN CREATED SUCCESSFULLY  !!! "<<endl ;
            cout<<"\n\n\t\t\t\t\t\tDirecting you to the application homepage now .....................\n\n" ;
 //           Sleep(3000) ;
        	z2++;
    	}
    }
	while(z2!=1) ;

	// Initializing Calendar for the user as follows .
    Date start_date = validator.get_todays_date() ;
    map< Date , vector< pair<Slot,bool> > > temp_map ;

    Time temp_start , temp_end ;
    vector< pair<Slot,bool> > slot_index ;
    Slot temp_slot ;
    pair<Slot,int> temp_pair ;

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

    for(int i=0 ; i<=120 ; i++){
        Date temp_date = validator.date_of_nth_working_day( start_date , i ) ;
        temp_map[ temp_date ] = slot_index ;
    }

	// Final Touch .
	Calendar computed_cal ;
    computed_cal.set_cal1( temp_map ) ;
	User temp_user ;
	temp_user.set_profile_data( name , username , password ) ;
	temp_user.set_timeline( computed_cal ) ;

	// Adding this entry in 'users_data' map i.e. map1 of the interface (Assuming the Calendar).
	users_data[ temp_user.get_username() ] = temp_user ;
}

bool Interface::verify_login_credentials( string username , string password ){
//	cout<<"Control Flow in verify function .\n" ;
	map<string,User>::iterator it = users_data.find(username) ;

	if( it != users_data.end() ){
		User temp_user = it->second ;
		string pwd = temp_user.get_password() ;
//		cout<<"pwd = "<<pwd<<"\n" ;
		if( pwd == password ){
			return 1 ;
		}
//		cout<<"Password is wrong .\n" ;
		return 0 ;
	}
//	cout<<"Username not found .\n" ;
	return 0 ;
}

User Interface::enter_login_credentials(){
    system("cls") ;
	User temp_user ;
	string username , password ;
    cout<<"\n\n\t\t\t\t\t\t\t\t!!!  LOGIN PROCESS BEGINS  !!!\n\n" ;
	cout<<"\n\n\t  PLEASE ENTER YOUR USERNAME AND PASSWORD AS FOLLOWS : \n\n\n" ;

	bool verdict = 0 ;
	int mistake = 0 ;

	while( verdict == 0 ){
		if( mistake != 0 ){
			cout<<"\n\n\t  PLEASE ENTER YOUR USERNAME AND PASSWORD AGAIN : \n\n\n" ;
		}

		cout<<"\tUSERNAME = " ;
		cin>>ws ;
		getline( cin , username ) ;
		cout<<"\n" ;

        // Erasing blank spaces at the start and end of the given username .
        while(1){
            if( username[0] == ' ' ){ username.erase(0,1) ; }
            else{ break ; }
        }
        while(1){
            if( username[username.size()-1] == ' ' ){ username.erase(username.size()-1,1) ; }
            else{ break ; }
        }

		cout<<"\tPASSWORD = " ;
		cin>>ws ;
		getline( cin , password ) ;
		cout<<"\n" ;

		verdict = verify_login_credentials( username , password ) ;

		if( verdict ){ // Credentials are right .
        	cout<<"\n\n\t\t\t\t\t\t\t\t   !!!  LOGIN SUCCESSFUL  !!! "<<endl ;
    //        Sleep(3000) ;

			temp_user = users_data[ username ] ;
			return temp_user ;
		}
		else{ // Credentials are wrong .
			cout<<"\n\tGiven Credentials do not match for any existing account .\n" ;
            mistake ++ ;
		}
	}
	// Now we valid user's username and password .
}
