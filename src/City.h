
#ifndef SRC_CITY_H_
#define SRC_CITY_H_

#include "Coordinates.h"
#include "Hotel.h"
#include <vector>
#include <iostream>


class City {
private:
	int id;
	string name;
	Coordinates coord;
	vector<Hotel*> hotels;
	vector<int> possibleDestinations;//{id1,cost1,flightDuration1,...}
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
	int getQueueIndex();

	void setID(int id);
	void setName(string n);
	void setCoordinates(Coordinates c);
	void setHotels(vector<Hotel*> h);
	void setDestinations(vector<int> pd);

	//friend bool operator==(City& lhs, City& rhs){ return lhs.getID() == rhs.getID();}
	//City operator=(City assignee);

	bool operator==(const City &other) { return id==other.id;}
};

#endif /* SRC_CITY_H_ */
