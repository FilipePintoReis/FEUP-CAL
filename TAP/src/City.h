
#ifndef SRC_CITY_H_
#define SRC_CITY_H_

#include "Coordinates.h"
#include "Hotel.h"
#include <vector>
#include <iostream>

using namespace std;

class City {
private:
	int id;
	string name;
	Coordinates coord;
	vector<Hotel*> hotels;
	vector<int> possibleDestinations;
	int queueIndex;

public:
	City(int id, string n, Coordinates c, vector<Hotel*> ht, vector<int> pd);
	City();
	virtual ~City();

	int getID();
	string getName();
	Coordinates getCoordinates();
	vector<Hotel*> getHotels();
	vector<int> getPossibleDestinations();

	void setID(int id);
	void setName(string n);
	void setCoordinates(Coordinates c);
	void setHotels(vector<Hotel*> h);
	void setDestinations(vector<int> pd);

	friend bool operator==(City& lhs, City& rhs){ if(lhs.getID() == rhs.getID()) return true; else return false; }
};

#endif /* SRC_CITY_H_ */
