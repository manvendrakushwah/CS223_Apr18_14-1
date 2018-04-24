#include <bits/stdc++.h>
#include "Appointment.h"
#include "Interface.h"
#include "Calendar_Data.h"

using namespace std ;

#ifndef UNTITLED_FILE_HANDLING_H
#define UNTITLED_FILE_HANDLING_H

class File_Handling{
    private :

    public :
        void set_slot_index( vector< pair<Slot,bool> > & ) ;
        void set_application_data_part1( Interface& , vector< pair<Slot,bool> > & ) ;
        void set_application_data_part2( Interface & ) ;

        void get_application_data_part1( Interface & ) ;
        void get_application_data_part2( Interface & ) ;
};

#endif
