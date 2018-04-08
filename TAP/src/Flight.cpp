
#include "Flight.h"

Flight::Flight(City o, City d, Date dt, int fd, float p) {

	this->org = o;
	this->dest = d;
	this->date = d;
	this->flightDuration = fd;
	this->price = price;

}

	City Flight::getOrigin() const {

		return this->org;
	}

	City Flight::getDestination() const {

		return this->dest;
	}

	Date Flight::getDate() const {

		return this->date;
	}

	int Flight::getFlightDuration() const {

		return this->flightDuration;
	}

	float Flight::getPrice() const {

		return this->price;
	}

	void Flight::setOrigin(City o) {

		this->org = o;
	}

	void Flight::setDestination(City d) {

		this->dest = d;
	}

	void Flight::setDate(Date d){

		this->date = d;
	}

	void Flight::setFlightDuration(int fd) {

		this->flightDuration = fd;
	}

	void Flight::setPrice(float p){

		this->price = p;
	}




