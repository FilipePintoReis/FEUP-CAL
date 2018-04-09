
#ifndef USER_H_
#define USER_H_

#include <string>
#include "Trip.h"

using namespace std;

class Client {

	Trip trip;
	string name;
	static int id;
	int phoneNumber;

public:
	Client(string n, int pn);
	Client(string n,int pn, Trip t);
	virtual ~Client();

	int getID();
	int getPhoneNumber();
	string getName();
	Trip getTrip();

	void setID(int id);
	void setPhoneNumber(int pn);
	void setName(string n);
	void setTrip(Trip t);
};

#endif /* USER_H_ */
