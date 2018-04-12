
#include "City.h"

	City::City(){

		this->id = 0;
		this->name = "";
		this->hotels = *(new vector<Hotel*>());
		this->coord = Coordinates();

	}

	City::City(int id, string n, Coordinates c, vector<Hotel*> ht, vector<int> pd) {

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

		return this->hotels;
	}
	vector<int> City::getPossibleDestinations(){

		return this->possibleDestinations;
	}

	int City::getQueueIndex(){

		return this->queueIndex;
	}

	int City::getIDDestinies(int n){

		return possibleDestinations[n*2];
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

	void City::setDestinations(vector<int> pd){

		this->possibleDestinations = pd;
	}

	/*City City::operator=(City assignee)  {

		this->id = assignee.getID();
		this->name = assignee.getName();
		this->coord.setX(assignee.getCoordinates().getX());
		this->coord.setY(assignee.getCoordinates().getY());
		this->setHotels(assignee.getHotels());
		this->setDestinations(assignee.getPossibleDestinations());
		this->queueIndex = assignee.getQueueIndex();
	}*/



	City::~City() {}
