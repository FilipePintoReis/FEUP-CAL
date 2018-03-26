
#ifndef SRC_TRIP_H_
#define SRC_TRIP_H_

#include <iostream>
#include "Date.h"

class Trip {
private:

	Date departureDate;
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

	void setDepartureDate(Date d);
	void setArivalDate(Date a);
	void setCost(double c);
	void setDistance(double d);
};

#endif /* SRC_TRIP_H_ */
