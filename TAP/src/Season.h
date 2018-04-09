#ifndef SEASON_H
#define SEASON_H

#include <iostream>
#include "Date.h"

#define HIGH_S_M 1.40

using namespace std;

class Season {
private:
	float multiplier = 1;
public:
	Season();
	~Season();
	float getMultiplier() { return multiplier;};
	void setMultiplier(float value) {this->multiplier = value;};
	void calculateMul(Date date){
		if( (date.getMonth() == 12 && date.getDay() > 3) || (date.getMonth() == 1 && date.getDay() < 10) ){
			setMultiplier(HIGH_S_M);
		}
	};
};

#endif /* SEASON_H */
