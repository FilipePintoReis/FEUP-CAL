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

	string assets = "./assets/Cities"; //This is used to pre append to rest of path
	string cityName, hotelName;
	string ID, temp;
	unsigned int x, y, hotelNumber, price, numberDestinies, cityID;


	ifstream in;

	for(int i = 0; i < NOFF; i ++){ //For each file --> cities

		//get attributes from file into stream with getline
		//for each attribute read put it in city attr


		string fich = assets + to_string(i) + ".txt";
		const char *nomeFich;
		nomeFich = fich.c_str();

		in.open(nomeFich);

		if(!in.fail()){

			vector<Hotel*> hotels;
			vector<int> destinations;
			getline(in,cityName);
			getline(in, ID);
			getline(in, temp, ',');
			x = atoi(temp.c_str());
			getline(in, temp);
			y = atoi(temp.c_str());

			Coordinates c = Coordinates(x,y);

			getline(in, temp);
			hotelNumber = atoi(temp.c_str());

			for(unsigned int i = 0; i < hotelNumber; i++){

				getline(in, hotelName);
				getline(in, temp);
				price = atoi(temp.c_str());

				Hotel* hotel(hotelName, price);

				hotels.push_back(hotel);

			}

			getline(in, temp);
			numberDestinies = atoi(temp.c_str());

			for(unsigned int i = 0; i < numberDestinies; i++){

				getline(in, temp);
				cityID = atoi(temp.c_str());

				destinations.push_back(cityID);

			}

			City city(stoi(ID), cityName, c, hotels, destinations);
			graph.addVertex(city);
			in.close();
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

	cout << " Finished loading! :D\n";
}

void Agency::addClients(Client* cliente) {
	clientes.push_back(cliente);
}


void Agency::addTrips(Trip* viagem) {
	trips.push_back(viagem);
}

