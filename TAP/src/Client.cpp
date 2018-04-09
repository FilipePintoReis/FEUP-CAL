
#include "Client.h"

	int Client::id = 1;

	Client::Client(string n,int pn) {

	this->name = n;
	this->id++;
	this->phoneNumber = pn;


	}

	Client::Client(string n,int pn, Trip t) {

		this->name = n;
		this->id++;
		this->phoneNumber = pn;
		this->trip = t;


		}

	Client::~Client() {}

	int Client::getID(){

	return this->id;
	}

	Trip Client::getTrip(){

		return trip;
	}

	int Client::getPhoneNumber(){

	return this->phoneNumber;
	}

	string Client::getName(){

	return this->name;
	}

	void Client::setID(int id){

	this->id = id;
	}

	void Client::setPhoneNumber(int pn){

	this->phoneNumber = pn;
	}

	void Client::setName(string n){

	this->name = n;
	}

	void Client::setTrip(Trip t){

		trip = t;
	}
