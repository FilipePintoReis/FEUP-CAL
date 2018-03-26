
#ifndef DATA_H
#define DATA_H

#include <string>
#include <iostream>
#include <sstream>
#include <ctime>


	using namespace std;

class Date {
private:
	unsigned int day;
	unsigned int month;
	unsigned int year;

public:
	Date();
	Date(string dataStr);
	string getString() const;
	unsigned int getDay() const;
	unsigned int getMonth() const;
	unsigned int getYear() const;

};


#endif
