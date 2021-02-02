#include "TimedEvents.h"

namespace sdds 
{
	TimedEvents::TimedEvents()
	{
		te_current_records = { 0 };
		te_start = {};
		te_end = {};
		events->te_name = {};
		events->te_time = {};
		events->te_duration = {};
	}

	void TimedEvents::startClock()
	{
		te_start = chrono::steady_clock::now();
	}

	void TimedEvents::stopClock()
	{
		te_end = chrono::steady_clock::now();
	}

	void TimedEvents::addEvent(const char* name)
	{
		auto duration = std::chrono::duration_cast<chrono::nanoseconds>(te_end - te_start);
		if (te_current_records < MAX_EVENTS)
		{
			events[te_current_records].te_name = name;  // stores into the name attribute the C-style string at the pointed to address
			events[te_current_records].te_time = "nanoseconds";	// stores "nanoseconds" as the units of time
			events[te_current_records].te_duration = duration;	// calculates and stores the duration of the event.
			te_current_records++;	// increment current record of events!
		}
	}

	ostream& operator<<(ostream& os, const TimedEvents& te)
	{
		os << "Execution Times:\n";
		os << "--------------------------\n";

		for (int i = 0; i < te.te_current_records; i++)
			os << setw(20) << left << te.events[i].te_name << " "
			<< setw(12) << right << te.events[i].te_duration.count() << " "
			<< te.events[i].te_time << '\n';
		os << "--------------------------\n";

		return os;
	}
}