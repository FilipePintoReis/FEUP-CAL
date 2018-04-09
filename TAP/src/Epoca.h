#ifndef EPOCA_H
#define EPOCA_H

#include <iostream>
#include "Date.h"

#define HIGH_S_M 1.40

using namespace std;

class Epoca {
private:
	float multiplier = 1;
public:
	Epoca();
	float getMultiplier() { return multiplier;};
	void setMultiplier(float value) {this->multiplier = value;};
	void calculateMul(Date date){
		if( (date.getMonth() == 12 && date.getDay() > 3) || (date.getMonth() == 1 && date.getDay() < 10) ){
			setMultiplier(HIGH_S_M);
		}
	};
};

#endif /* EPOCA_H */
