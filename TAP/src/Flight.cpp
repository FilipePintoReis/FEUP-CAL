
#include "Flight.h"

Flight::Flight(City o, City d, Date dt, int fd) {

	this->org = o;
	this->dest = d;
	this->date = dt;
	this->flightDuration = fd;
	this->calcPrice(o, d);
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

	void Flight::calcPrice(City o, City d){
		double x, y;
		x = ((double) o.getCoordinates().getX() - (double) d.getCoordinates().getX());
		y = ((double) o.getCoordinates().getY() - (double) d.getCoordinates().getY());
		this->price = sqrt( pow(x,2) + pow(y,2) ) / 100;
	}


