#include <bits/stdc++.h>

#include "Slot.h"

#define pb push_back
#define mp make_pair

using namespace std ;

// Functions of Slot Class are defined as follows .
Slot::Slot(){
    Time st_time , ed_time ;
    start_time = st_time , end_time = ed_time ;
}

void Slot::set_slot(Time st , Time et){
	start_time = st ;
	end_time = et ;
}

void Slot::set_start_time( Time given_start_time ){
    start_time = given_start_time ;
}

void Slot::set_end_time( Time given_end_time ){
    end_time = given_end_time ;
}

Time Slot::get_start_time()const{
    return start_time ;
}

Time Slot::get_end_time()const{
    return end_time ;
}

bool Slot::is_slot_equal( Slot given_slot ){
    int val = 0 ;
    if( ( given_slot.get_start_time().get_hour() == start_time.get_hour() ) &&
       ( given_slot.get_start_time().get_minutes() == start_time.get_minutes() ) &&
       ( given_slot.get_start_time().get_am_pm() == start_time.get_am_pm() ) ){
            val ++ ;
       }

    if( ( given_slot.get_end_time().get_hour() == end_time.get_hour() ) &&
       ( given_slot.get_end_time().get_minutes() == end_time.get_minutes() ) &&
       ( given_slot.get_end_time().get_am_pm() == end_time.get_am_pm() ) ){
            val ++ ;
       }

    if( val == 2 ){
        return 1 ;
    }
    else{
        return 0 ;
    }
}
