
#ifndef SRC_TRIP_H_
#define SRC_TRIP_H_

#include <iostream>
#include <vector>
#include "Date.h"
#include "Flight.h"


class Trip {
private:

	static int ID;
	Date departureDate;
	vector<Flight*> flights;
	Hotel hotel;
	Date arrivalDate;
	double cost;
	double distance;

public:
	Trip();
	Trip(Date d, Date a);
	Trip(Date d);
	virtual ~Trip();

	Date getDepartureDate();
	Date getArrivalDate();
	double getCost();
	double getDistance();
	vector<Flight*> getFlights();
	int getID();
	Hotel getHotel();

	void setID(int id);
	void setDepartureDate(Date d);
	void setArivalDate(Date a);
	void setCost(double c);
	void setDistance(double d);
	void setFlights(vector<Flight*> f);
	void setHotel(Hotel ht);
};

#endif /* SRC_TRIP_H_ */
