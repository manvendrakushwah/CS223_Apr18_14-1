#include <bits/stdc++.h>

#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <dos.h>
#include <windows.h>

#include "Calendar.h"

#define pb push_back
#define mp make_pair
#pragma once

using namespace std ;

// Utility functions are as follows .

bool operator < ( const Date&a , const Date&b ){
    if( a.get_year() == b.get_year() ){
       	if( a.get_month() == b.get_month() ){
       		return a.get_day() < b.get_day() ;
		}
		return a.get_month() < b.get_month() ;
	}
	return a.get_year() < b.get_year() ;
}

// Functions of Calendar Class are defined as follows .
map<Date, vector< pair<Slot,bool> > > Calendar::get_cal(){
    return cal ;
}

void Calendar::set_cal( vector<Date> dates , vector< bitset<8> > appts ){
    map< Date , vector< pair<Slot,bool> > > ans ;

    for(int i=0 ; i<dates.size() ; i++){
    	bitset<8> curr_appt = appts[i] ;
		vector< pair<Slot,bool> > tm_ln(8) ;
		Time st_time , ed_time ;

		st_time.set_time_data(9,0,"am") , ed_time.set_time_data(10,0,"am") ;
		tm_ln[0].first.set_slot( st_time , ed_time ) , tm_ln[0].second = curr_appt[7] ;

		st_time.set_time_data(10,0,"am") , ed_time.set_time_data(11,0,"am") ;
		tm_ln[1].first.set_slot( st_time , ed_time ) , tm_ln[1].second = curr_appt[6] ;

		st_time.set_time_data(11,0,"am") , ed_time.set_time_data(12,0,"pm") ;
		tm_ln[2].first.set_slot( st_time , ed_time ) , tm_ln[2].second = curr_appt[5] ;

		st_time.set_time_data(12,0,"pm") , ed_time.set_time_data(1,0,"pm") ;
		tm_ln[3].first.set_slot( st_time , ed_time ) , tm_ln[3].second = curr_appt[4] ;

		st_time.set_time_data(1,0,"pm") , ed_time.set_time_data(2,0,"pm") ;
		tm_ln[4].first.set_slot( st_time , ed_time ) , tm_ln[4].second = curr_appt[3] ;

		st_time.set_time_data(2,0,"pm") , ed_time.set_time_data(3,0,"pm") ;
		tm_ln[5].first.set_slot( st_time , ed_time ) , tm_ln[5].second = curr_appt[2] ;

		st_time.set_time_data(3,0,"pm") , ed_time.set_time_data(4,0,"pm") ;
		tm_ln[6].first.set_slot( st_time , ed_time ) , tm_ln[6].second = curr_appt[1] ;

		st_time.set_time_data(4,0,"pm") , ed_time.set_time_data(5,0,"pm") ;
		tm_ln[7].first.set_slot( st_time , ed_time ) , tm_ln[7].second = curr_appt[0] ;

        ans[dates[i]] = tm_ln ;
    }

	cal = ans ;
}

void Calendar::show_cal(){
	for( auto it=cal.begin() ; it!=cal.end() ; it++){
		Date t1 = it->first ;
		t1.show_date() ;
		cout<<"|| ";
		for(int i=0 ; i< it->second.size() ; i++){
			cout<<it->second[i].second;
		}
		cout<<"\n" ;
	}
}

void Calendar::set_cal1( map<Date, vector< pair<Slot,bool> > > given_cal ){
    cal = given_cal ;
}
