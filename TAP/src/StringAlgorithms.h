/*
 * StringAlgorithms.h
 *
 *  Created on: 19 May 2018
 *      Author: Jo�o �lvaro Ferreira
 */

#ifndef STRINGALGORITHMS_H_
#define STRINGALGORITHMS_H_

#include <string>
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;



class StringAlgorithms{

public:
	StringAlgorithms();


	//Exact String Matching
	void ExactStringMatchingNaive(string pattern, string text);

	void ExactStringMatchingFiniteAutomaton(string pattern, string text); //n�o est� feito porque d� mais trabalho que os outros e pode n�o ser util

	void ExactStringMatchingKMP(string pattern, string text);

	void auxKMP(string pattern, int *lps);


	//Aproximate String Matching
	int ApproximateStringMatchingEditDistance(string string1, string string2); //usar isto para ver o qu�o proximo uma string � de outra e depois ordenar destinos a partir da�
};


#endif /* STRINGALGORITHMS_H_ */
