cmake_minimum_required(VERSION 3.1)
project(MAS)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(MAS
	Acceptor.h
	Acceptor.cpp
	Appointment.h
	Appointment.cpp
	Calendar.h
	Calendar.cpp
	Calendar_Data.h
	Calendar_Data.cpp
	Date.h
	Date.cpp
	File_Handling.h
	File_Handling.cpp
	Interface.h
	Interface.cpp
	main.cpp
	Normal_Appointment.h
	Normal_Appointment.cpp
	Notification.h
	Notification.cpp
	Priority_Appointment.h
	Priority_Appointment.cpp
	Seeker.h
	Seeker.cpp
	Slot.h
	Slot.cpp
	Time.h
	Time.cpp
	User.h
	User.cpp
	Validate_Input.h
	Validate_Input.cpp
	)
