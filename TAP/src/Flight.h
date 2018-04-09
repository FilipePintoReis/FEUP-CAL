#ifndef SRC_FLIGHT_H_
#define SRC_FLIGHT_H_

#include <iostream>
#include "Date.h"
#include "City.h"
#include <math.h>

using namespace std;

class Flight {
private:

	City org;
	City dest;
	Date date;
	int flightDuration; //in minutes?
	double price;

public :

	Flight(City o, City d, Date dt, int fd);

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

	float calcPrice(City o, City d);

};

#endif /* SRC_FLIGHT_H_ */
