#ifndef SRC_FLIGHT_H_
#define SRC_FLIGHT_H_

#include <iostream>
#include "Date.h"
#include "City.h"

using namespace std;

class Flight {
private:

	City org;
	City dest;
	Date date;
	int flightDuration; //in minutes?
	float price;

public :

	Flight(City o, City d, Date dt, int fd, float p);

	City getOrigin() const;
	City getDestination() const;
	Date getDate() const;
	int getFlightDuration() const;
	float getPrice() const;

	void setOrigin(City o);
	void setDestination(City o);
	void setDate(Date d);
	void setFlightDuration(int fd);
	void setPrice(float p);

};

#endif /* SRC_FLIGHT_H_ */
