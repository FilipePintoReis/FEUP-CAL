
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

	Date Flight::getDate() const {

		return this->date;
	}

	int Flight::getFlightDuration() const {

		return this->flightDuration;
	}

	float Flight::getPrice() const {

		return this->price;
	}

	void Flight::setOrigin(string o) {

		this->org = o;
	}

	void Flight::setDestination(string d) {

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




