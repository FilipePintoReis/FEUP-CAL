
#include "Flight.h"

Flight::Flight(string o, string d, Date dt, int fd, float p) {

	this->org = o;
	this->dest = d;
	this->date = d;
	this->flightDuration = fd;
	this->price = price;

}

string Flight::getOrigin() const {

		return this->org;
	}

	string Flight::getDestination() const {

		return this->dest;
	}

	Date getDate() const;
	int getFlightDuration() const;
	float getPrice() const;

	void setOrigin(string o);
	void setDestination(string o);
	void setDate(Date d);
	void setFlightDuration(int fd);
	void setPrice(float p);




