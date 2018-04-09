#include "Trip.h"


	int Trip::Trip ID = 1;

	Trip::Trip() {

		this->flights = vector<Flight*>();
		this->hotel = Hotel();
		this->departureDate = Date();
		this->arrivalDate = Date();
		this->cost = 0;
		this->distance = 0;
		this->ID++;
	}

	Trip::Trip(Date d, Date a){

		this->departureDate = d;
		this->arrivalDate = a;
		this->cost = 0; //not sure abt this
		this->distance = 0;
		this->ID++;
	}

	Trip::Trip(Date d){

		this->departureDate = d;
		this->arrivalDate = Date();
		this->cost = 0; //not sure abt this
		this->distance = 0;
		this->ID++;

	}

	vector<Flight*> Trip::getFlights() {

		return flights;
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

	Hotel Trip::getHotel(){

		return hotel;
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

	void Trip::setFlights(vector<Flight*> f){

		flights = f;
	}

	int Trip::getID(){

		return this->ID;
	}

	void Trip::setID(int id){

			this->ID = id;
		}

	void Trip::setHotel(Hotel ht){

		hotel = ht;
	}

	Trip::~Trip(){}

