#include <bits/stdc++.h>
using namespace std ;

#ifndef UNTITLED_TIME_H
#define UNTITLED_TIME_H

// Declaration .
class Time{
	private :
		int hour ;
		int minutes ;
		string am_pm ;

	public :
        Time() ;
        Time( int , int , string ) ;
		int get_hour()const ;
		int get_minutes()const ;
		string get_am_pm() ;

		void set_hour(int) ;
		void set_minutes(int) ;
		void set_am_pm(string) ;
		void set_time_data( int , int , string ) ;
        void show_time() ;
};


#endif
