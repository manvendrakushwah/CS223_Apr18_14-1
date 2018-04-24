#include <bits/stdc++.h>

#include "Date.h"
#include "Time.h"
#include "Slot.h"
#include "Calendar.h"
#include "User.h"
#include "Interface.h"
#include "Calendar_Data.h"
#include "Appointment.h"
#include "Normal_Appointment.h"
#include "Priority_Appointment.h"
#include "Notification.h"
#include "Acceptor.h"
#include "Seeker.h"
#include "Validate_Input.h"
#include "File_Handling.h"

#define pb push_back
#define mp make_pair

using namespace std ;


int main(){
    // Process of initializing slot_index map (begins here) .
    Validate_Input validator ;
    Date current_date = validator.get_todays_date() ;
    vector< pair<Slot,bool> > slot_index ;
    File_Handling file_handler ;
    file_handler.set_slot_index( slot_index ) ;
    // Process of initializing slot_index map (ends here) .

        // --------------------

    // Process of retrieving data from the .csv files begins here .
    Interface app ;

    file_handler.set_application_data_part1( app , slot_index ) ;
    file_handler.set_application_data_part2( app ) ;
    // Process of retrieving data from the .csv files ends here .

        // --------------------

    // Application is opened as follows .
	app.open_application() ;
    // Application is closed now .

        // --------------------

    // Process of overwriting data to the .csv files begins here .
    file_handler.get_application_data_part1( app ) ;
    file_handler.get_application_data_part2( app ) ;
    // Process of overwriting data to the .csv files ends here .


    return 0 ;
}
