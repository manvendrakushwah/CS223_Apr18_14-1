#include <bits/stdc++.h>
#include "Date.h"

using namespace std ;

#ifndef UNTITLED_CALENDAR_DATA_H
#define UNTITLED_CALENDAR_DATA_H

class Calendar_Data{
	private :
		vector<Date> cal_dates ;
		vector< bitset<8> > appts ;
	public :
		vector<Date> get_cal_dates() ;
		vector< bitset<8> > get_appts() ;
		void add_in_date_vector( Date ) ;
		void add_in_appts_vector( bitset<8> ) ;
};

#endif
