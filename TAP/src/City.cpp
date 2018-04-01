
#include "City.h"

	City::City(){

		this->id = 0;
		this->name = "";
		this->hotels = *(new vector<Hotel*>());
		this->coord = Coordinates();

	}

	City::City(int id, string n, Coordinates c, vector<Hotel*> ht, vector<bool> pd) {

		this->id = id;
		this->name = n;
		this->hotels = ht;
		this->coord = c;
		this->possibleDestinations = pd;

	}

	int City::getID(){

		return this->id;
	}

	string City::getName(){

		return this->name;
	}

	Coordinates City::getCoordinates(){

		return coord;
	}

	vector<Hotel*> City::getHotels(){

		return hotels;
	}
	vector<bool> City::getPossibleDestinations(){

		return possibleDestinations;
	}

	void City::setID(int id){

		this->id = id;
	}

	void City::setName(string n){

		this->name = n;
	}

	void City::setCoordinates(Coordinates c){

		this->coord = c;
	}

	void City::setHotels(vector<Hotel*> h){

		this->hotels = h;
	}

	void City::setDestinations(vector<bool> pd){

		this->possibleDestinations = pd;
	}

	City::~City() {}

