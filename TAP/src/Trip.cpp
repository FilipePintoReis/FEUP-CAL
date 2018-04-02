#include "Trip.h"

	Trip::Trip() {

		this->departureDate = Date();
		this->arrivalDate = Date();
		this->cost = 0;
		this->distance = 0;
	}

	Trip::Trip(Date d, Date a){

		this->departureDate = d;
		this->arrivalDate = a;
	}

	Trip::Trip(Date d){

		this->departureDate = d;
		this->arrivalDate = Date();

	}


	Date Trip::getDepartureDate(){

		return this->departureDate;
	}

	Date Trip::getArrivalDate(){

		return this->arrivalDate;
	}

	double Trip::getCost(){

		return this->cost;
	}


	double Trip::getDistance(){

		return this->distance;
	}

	void Trip::setDepartureDate(Date d){

		this->departureDate = d;
	}

	void Trip::setArivalDate(Date a){

		this->arrivalDate = a;
	}

	void Trip::setCost(double c){

		this->cost = c;
	}

	void Trip::setDistance(double d){

		this->distance = d;
	}

	Trip::~Trip(){}

