
#include "Hotel.h"

	Hotel::Hotel() {}

	Hotel::Hotel(string n, float p){

		this->name = n;
		this->price = p;
	}

	Hotel::~Hotel() {}

	string Hotel::getName(){

		return this->name;
	}

	float Hotel::getPrice(){

		return this->price;
	}

	void Hotel::setName(string n){

		this->name = n;
	}

	void Hotel::setPrice(float p){

		this->price = p;
	}
