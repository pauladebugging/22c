/*
 * wordID.cpp
 *
 *  Created on: Dec 7, 2016
 *      Author: fycai21
 */

#include <string>
#include <iostream>
#include <cstddef>
#include "wordID.h"
using namespace std;

wordID::wordID():id(0), data(" "){};

wordID::wordID(string d, int i){
	data = d;
	id = i;
}


int wordID::get_id()
{
	return id;
}

string wordID::get_data()
{
	return data;
}

