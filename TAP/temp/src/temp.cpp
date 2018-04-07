//============================================================================
// Name        : temp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {

	for(int i = 1; i <= 150 ; i++){
		std::ofstream outfile ("City" + to_string(i) + ".txt");

		outfile << "Id" << endl;
		outfile << "Name" << endl;
		outfile << "x coord" << endl;
		outfile << "y coord" << endl;
		outfile << "List Hotel" << endl;
		outfile << "STOP" << endl;
		outfile << "adj city list" << endl;
		outfile << "STOP" << endl;
		outfile << "queueIndex" << endl;

		outfile.close();
	}

	return 0;
}
