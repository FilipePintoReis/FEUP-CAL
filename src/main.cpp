#include <iostream>
#include "Agency.h"

using namespace std;

int main(){
	Agency *agency = new Agency();
	agency->readFromClientFile();
	agency->readFromCityFiles();
	agency->readToClientFile();
	agency->readFromTripFiles();
	agency->readToTripsFile();
	agency->introMenu();

}
