#include <bits/stdc++.h>

#include "Calendar_Data.h"

#define pb push_back
#define mp make_pair

using namespace std ;

vector<Date> Calendar_Data::get_cal_dates(){
	return cal_dates ;
}

vector< bitset<8> > Calendar_Data::get_appts(){
	return appts ;
}

void Calendar_Data::add_in_date_vector( Date da ){
	cal_dates.pb( da ) ;
}

void Calendar_Data::add_in_appts_vector( bitset<8> apt ){
	appts.pb(apt) ;
}
