#include <bits/stdc++.h>
#include "Date.h"
#include "Slot.h"

using namespace std ;

#ifndef UNTITLED_CALENDAR_H
#define UNTITLED_CALENDAR_H

class Calendar{
    private:
        map<Date, vector< pair<Slot,bool> > > cal ;

    public:
        map<Date, vector< pair<Slot,bool> > > get_cal() ;
        void set_cal( vector<Date> , vector< bitset<8> > ) ;
        void show_cal() ;
        void set_cal1( map< Date , vector< pair< Slot , bool > > > ) ;
};

bool operator < ( const Date&a , const Date&b ) ;

#endif
