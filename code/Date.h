#include <bits/stdc++.h>
using namespace std ;

#pragma once
#ifndef UNTITLED_DATE_H
#define UNTITLED_DATE_H

// Declaration of Date Class are as follows .

class Date{
    private :
        int day ;
        int month ;
        int year ;

    public :
        Date() ;
        Date( const Date& ) ;
    	Date(int , int , int) ;
        bool is_equal( Date ) ;

        int get_day( )const ;
        int get_month( )const ;
        int get_year( )const ;

	    void set_day( int ) ;
        void set_month( int ) ;
        void set_year( int ) ;
        void set_date_data( int , int , int ) ;
        void set_date_data1( Date ) ;

        void show_date();
} ;

bool operator == ( Date a , Date b ) ;

#endif
