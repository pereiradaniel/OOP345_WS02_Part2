#ifndef SDDS_STRINGSET_H
#define SDDS_STRINGSET_H

#include <string>
#include <iomanip>
#include <iostream>
#include <ctime>
#include <chrono>
#include <fstream>

using namespace std;

namespace sdds {
	class StringSet
	{
	public:
		string *ss_strings;		// strings
		size_t ss_string_count;	// string counter

		StringSet();	// A no argument default constructor.
		~StringSet();
		StringSet(char* new_string);	// 1-argument constructor that receives the address of a c-style null terminated string containing the name of a file from which this member function populates the current object.
		StringSet(const StringSet &input_string);
		StringSet& operator=(const StringSet &input_string);
		size_t size();
		std::string operator[](size_t index) const;
	};
}
#endif
