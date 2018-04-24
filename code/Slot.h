#include <bits/stdc++.h>
#include "Time.h"

using namespace std ;

#ifndef UNTITLED_SLOT_H
#define UNTITLED_SLOT_H

// Declaration .
class Slot{
	private :
		Time start_time ;
		Time end_time ;

	public :
        Slot() ;
		void set_slot(Time,Time) ;
        void set_start_time( Time ) ;
        void set_end_time( Time ) ;

        Time get_start_time()const ;
        Time get_end_time()const ;
        bool is_slot_equal( Slot ) ;
};

#endif
