/*
 * wordID.h
 *
 *  Created on: Dec 7, 2016
 *      Author: fycai21
 */

#ifndef SRC_WORDID_H_
#define SRC_WORDID_H_

#include <string>
#include <iostream>
#include <cstddef>

using namespace std;

class wordID
{
private:

	int id;
	string data;
public:
	wordID();
	wordID(string d, int i);


	int get_id();
	string get_data();

};


#endif /* SRC_WORDID_H_ */
