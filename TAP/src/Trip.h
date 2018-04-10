
#ifndef SRC_TRIP_H_
#define SRC_TRIP_H_

#include <iostream>
#include <vector>
#include "Date.h"



class Trip {
private:

	static int ID;
	Date departureDate;
	string hotelName;
	Date arrivalDate;
	double cost;
	double distance;

public:
	Trip();
	Trip(Date d, Date a);
	Trip(Date d, Date a, string hn, double c, double dc);
	virtual ~Trip();

	Date getDepartureDate();
	Date getArrivalDate();
	double getCost();
	double getDistance();
	int getID();
	string getHotel();

	void setID(int id);
	void setDepartureDate(Date d);
	void setArivalDate(Date a);
	void setCost(double c);
	void setDistance(double d);
	void setHotel(string ht);
};

#endif /* SRC_TRIP_H_ */
