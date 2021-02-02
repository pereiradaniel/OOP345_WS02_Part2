#ifndef SDDS_TIMEDEVENTS_H
#define SDDS_TIMEDEVENTS_H

#include <chrono>
#include <ctime>
#include <iostream>
#include <iomanip>

using namespace std;

#define MAX_EVENTS 10	// Your class predefines the maximum number of event objects at 10.

namespace sdds
{
	class TimedEvents
	{
	public:
		int te_current_records;							// the number of records currently stored
		std::chrono::steady_clock::time_point te_start;		// the start time for the current event
		std::chrono::steady_clock::time_point te_end;		// the end time for the current event
		struct	// an array of Events of structure type
		{
			const char* te_name;	// a string with the event name
			const char* te_time;	// a string with the predefined units of time
			std::chrono::steady_clock::duration te_duration;	// the duration of the event
		} events[MAX_EVENTS];

		TimedEvents();		// a default constructor
		void startClock();	// a modifier that starts the timer for an event
		void stopClock();	// a modifier that stops the timer for an event
		void addEvent(const char *event_name);	// a modifier that receives the address of a c-style null-terminated string that holds the name of the event.

		friend ostream& operator<<(ostream& os, const TimedEvents& te);
	};
}

#endif
