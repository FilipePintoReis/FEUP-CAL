
#ifndef SRC_AGENCY_H_
#define SRC_AGENCY_H_

#include "City.h"
#include "Client.h"
#include "Coordinates.h"
#include "Date.h"
#include "Graph.h"
#include "Hotel.h"
#include "Trip.h"
#include <fstream>
#include <sstream>
#include <vector>


class Agency {
private:
	Graph<City> graph;
public:
	Agency();
	virtual ~Agency();
	void readFromFiles();
	Graph<City> getGraph();
	void printShortestPath(const City origin, const City destiny);
};

#endif /* SRC_AGENCY_H_ */
