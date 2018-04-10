#include "Trip.h"


	int Trip::ID = 1;

	Trip::Trip() {


		this->hotelName = "";
		this->departureDate = Date();
		this->arrivalDate = Date();
		this->cost = 0;
		this->distance = 0;
		this->ID++;
	}

	Trip::Trip(Date d, Date a){

		this->departureDate = d;
		this->arrivalDate = a;
		this->hotelName = "";
		this->cost = 0; //not sure abt this
		this->distance = 0;
		this->ID++;
	}

	Trip::Trip(Date d, Date a, string hn, double c, double dc){

		this->departureDate = d;
		this->arrivalDate = a;
		this->hotelName = hn;
		this->cost = c;
		this->distance = dc;

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

	string Trip::getHotel(){

		return hotelName;
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

	int Trip::getID(){

		return this->ID;
	}

	void Trip::setID(int id){

			this->ID = id;
		}

	void Trip::setHotel(string ht){

		hotelName = ht;
	}

	Trip::~Trip(){}

