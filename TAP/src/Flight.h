#ifndef SRC_FLIGHT_H_
#define SRC_FLIGHT_H_

#include <iostream>
#include "Date.h"

using namespace std;

class Flight {
private:

	string org;
	string dest;
	Date date;
	int flightDuration; //in minutes?
	float price;

public :

	Flight(string o, string d, Date dt, int fd, float p);

	string getOrigin() const;
	string getDestination() const;
	Date getDate() const;
	int getFlightDuration() const;
	float getPrice() const;

	void setOrigin(string o);
	void setDestination(string o);
	void setDate(Date d);
	void setFlightDuration(int fd);
	void setPrice(float p);

};

#endif /* SRC_FLIGHT_H_ */
