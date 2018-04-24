#include <bits/stdc++.h>

#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <dos.h>
#include <windows.h>

#include "Validate_Input.h"

#define pb push_back
#define mp make_pair

using namespace std ;

Validate_Input::Validate_Input(){
    slot_index[9] = 0 , slot_index[10] = 1 , slot_index[11] = 2 , slot_index[12] = 3 ;
    slot_index[1] = 4 , slot_index[2] = 5 , slot_index[3] = 6 , slot_index[4] = 7 ;
}

map<int,int> Validate_Input::get_slot_index(){
    return slot_index ;
}

Date Validate_Input::get_todays_date(){
    time_t now = time(0) ;
    tm *ltm = localtime(&now) ;

    int y=1900+(ltm->tm_year) ;
    int m=1+(ltm->tm_mon) ;
    int d=(ltm->tm_mday) ;
    Date ans_date( d , m , y ) ;
    return ans_date ;
}

int Validate_Input::return_week_day( Date d1 ){
	int d = d1.get_day() , m = d1.get_month() , y = d1.get_year() ;

    tm t = {} ;
	t.tm_year = y-1900 ;
	t.tm_mon  = m-1 ;
    t.tm_mday = d ;

    t.tm_mday += 0 ;
	mktime(&t) ;

	return t.tm_wday ;
}

Date Validate_Input::return_next_date( Date d1 ){
	int dx = d1.get_day() , mx = d1.get_month() , yx = d1.get_year() ;

    tm t = {} ;
	t.tm_year = yx-1900 ;
	t.tm_mon  = mx-1 ;
    t.tm_mday = dx ;

    t.tm_mday += 1 ;
	mktime(&t) ;

	int dayx = t.tm_mday , monthx = 1 + t.tm_mon , yearx = 1900 + t.tm_year ;
	Date ans_date( dayx , monthx , yearx ) ;

	return ans_date ;
}

string Validate_Input::compress_string( string str ){
    while(1){
        if( str[0] == ' ' ){ str.erase(0,1) ; }
        else{ break ; }
    }
    while(1){
        if( str[str.size()-1] == ' ' ){ str.erase(str.size()-1,1) ; }
        else{ break ; }
    }
    return str ;
}

bool Validate_Input::check_number( string str ){
	for(int i=0 ; i<str.size() ; i++){
		if( isdigit(str[i]) != 1 ){
			return 0 ;
		}
	}
	return 1 ;
}

bool Validate_Input::check_bound( string str , int low , int high ){
	int a = atoi( str.c_str() ) ;
	if( a>=low && a<=high ){
		return 1 ;
	}
	else{
		return 0 ;
	}
}

bool Validate_Input::check_gaps( string str ){
    for(int i=0 ; i<str.size() ; i++){
        if( str[i] == ' ' ){
            return 1 ;
        }
    }
    return 0 ;
}

bool Validate_Input::is_working_day( Date given_date ){
    int week_day = return_week_day( given_date ) ;
    if( week_day == 0 || week_day == 6 ){
        return 0 ;
    }
    else{
        return 1 ;
    }
}

int Validate_Input::validate_number( string str , int low , int high ){
	str = compress_string( str ) ;
    if( check_gaps( str ) == 1 ){
        return 0 ;
    }
	if( check_number( str ) == 0 ){
		return 0 ;
	}
	if( check_bound( str , low , high ) == 0 ){
		return 0 ;
	}
	return atoi( str.c_str() ) ;
}

Date Validate_Input::date_of_nth_working_day( Date current_date , int n ){
    Date ans_date( current_date ) ;

    while( is_working_day( ans_date ) == 0 ){
    	ans_date = return_next_date( ans_date ) ;
	}

    while( n ){
        ans_date = return_next_date( ans_date ) ;
        if( is_working_day( ans_date ) ){
            n-- ;
        }
    }
    return ans_date ;
}

int Validate_Input::get_days_in_month( int month , int year ){
	if( month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12 ){
		return 31 ;
	}
	else if( month == 4 || month == 6 || month == 9 || month == 11 ){
		return 30 ;
	}
	else{ // February .
		if( year%100 == 0 ){
			if( year%400 == 0 ){
				return 29 ;
			}
			else{
				return 28 ;
			}
		}
		else{
			if( year%4 == 0 ){
				return 29 ;
			}
			else{
				return 28 ;
			}
		}
	}
}
