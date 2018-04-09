/*
 * Agency.cpp
 *
 *  Created on: Mar 26, 2018
 *      Author: Alexandra
 */

#include "Agency.h"

#define NOFF 10 //number of files

vector<City> vec;


Agency::Agency() {


}

Agency::~Agency() {

}

void Agency::readFromFiles(){
	string assets = "./assets/"; //This is used to pre apend to rest of path
	ifstream in;

	for(int i = 0; i < NOFF; i ++){ //For each file --> cities

		//get attributes from file into stream with getline
		//for each attribute read put it in city attr

		//ID
		//Name
		//( list hotel
			//name
			//standart price
		//)
		//terminated by string "STOP" or wtv
		//List of cities ids

		// end of file, addVertex
	}

	//after all Vertex were created we start adding Edges

	for(int k = 0; k < NOFF; k++){ //For each Vertex goes through vector possibleDestinations
		//for each position in vector possibleDestinations
			//if(boolean n)
				//addEdge
			//else
				//don't
	}

}

void Agency::addClients(Client* cliente) {
	clientes.push_back(cliente);
}


void Agency::addTrips(Trip* viagem) {
	trips.push_back(viagem);
}

