#include <bits/stdc++.h>

#include "Time.h"

#define pb push_back
#define mp make_pair

using namespace std ;

// Functions .
Time::Time(){
    hour = 0 , minutes = 0 , am_pm = "am" ;
}

Time::Time( int given_hour , int given_minutes , string given_am_pm ){
    hour = given_hour , minutes = given_minutes , am_pm = given_am_pm ;
}

int Time::get_hour()const{
	return hour ;
}

int Time::get_minutes()const{
	return minutes ;
}

string Time::get_am_pm(){
	return am_pm ;
}

void Time::set_hour(int hh){
	hour = hh ;
}

void Time::set_minutes(int mins){
	minutes = mins ;
}

void Time::set_am_pm(string val){
	am_pm = val ;
}

void Time::set_time_data( int hh , int mins , string val ){
	hour = hh , minutes = mins , am_pm = val ;
}

void Time::show_time(){
    cout<<hour<<" : 00 "<<am_pm ;
}
