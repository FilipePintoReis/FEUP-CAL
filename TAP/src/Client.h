
#ifndef USER_H_
#define USER_H_

#include <string>
#include "Trip.h"

using namespace std;

class Client {

	Trip t;
	string name;
	static int id;
	int phoneNumber;
public:
	Client(string n, int pn);
	virtual ~Client();

	int getID();
	int getPhoneNumber();
	string getName();

	void setID(int id);
	void setPhoneNumber(int pn);
	void setName(string n);
};

#endif /* USER_H_ */
