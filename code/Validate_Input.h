#include <bits/stdc++.h>
#include "Date.h"

using namespace std ;

#ifndef UNTITLED_VALIDATE_INPUT_H
#define UNTITLED_VALIDATE_INPUT_H

class Validate_Input{
    private :
        map<int,int> slot_index ;

    public :
        Validate_Input() ;
        map<int,int> get_slot_index() ;

        Date get_todays_date() ;
        int return_week_day( Date ) ;
        Date return_next_date( Date ) ;
        string compress_string( string ) ;
        bool check_gaps( string ) ;
        bool check_number( string ) ;
        bool check_bound( string , int , int ) ;
        int validate_number( string , int , int ) ;
        Date date_of_nth_working_day( Date , int ) ;
        bool is_working_day( Date ) ;
        int get_days_in_month( int , int ) ;
};

#endif
