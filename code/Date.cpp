#include <bits/stdc++.h>

#include "Date.h"

#define pb push_back
#define mp make_pair

using namespace std ;

// Functions  .
Date::Date(){
    day = 0 , month = 0 , year = 0 ;
}

Date::Date( int dd , int mm , int yy ){
	day = dd , month = mm , year = yy ;
}

Date::Date(const Date& given_date ){
    day = given_date.get_day() , month = given_date.get_month() , year = given_date.get_year() ;
}

bool Date::is_equal( Date d1 ){
    if( day == d1.get_day() && month == d1.get_month() && year == d1.get_year() ){
        return 1 ;
    }
    return 0 ;
}

int Date::get_day( )const{
	return day ;
}

int Date::get_month( )const{
	return month ;
}

int Date::get_year( )const{
	return year ;
}

void Date::set_day( int dd ){
	day = dd ;
}

void Date::set_month( int mm ){
	month = mm ;
}

void Date::set_year( int yy ){
	year = yy ;
}

void Date::set_date_data( int dd , int mm , int yy ){
	day = dd , month = mm , year = yy ;
}

void Date::set_date_data1( Date given_date ){
	day = given_date.get_day() , month = given_date.get_month() , year = given_date.get_year() ;
}

void Date::show_date(){
	cout<<day<<" - "<<month<<" - "<<year<<" " ;
}

bool operator == ( Date a , Date b ){
    if( ( a.get_day() == b.get_day() ) && ( a.get_month() == b.get_month() ) && ( a.get_year() == b.get_year() ) ){
        return 1 ;
    }
    else{
        return 0 ;
    }
}
