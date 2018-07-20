/*
 * ht2.cpp
 *
 *  Created on: Dec 7, 2016
 *      Author: fycai21
 */

#include "ht2.h"
#include "wordID.h"
#include "list.h"
#include <iostream>
#include <string>

using namespace std;

htID::htID(){}

htID::~htID(){}

int htID::hash(string key)
{
    int index, sum = 0;
    for(int i = 0; i < key.length(); i++)
        sum += (int) key[i]; //summing the ASCII values for each character in the string
    index = sum % SIZE; //dividing the summed ASCII values by 35 && storing remainder as my index
    return index;
}

int htID::findID(string word)
{

	int i = hash(word);
	Table[i].begin_cursor();
	while (!Table[i].off_end())
	{
		if (Table[i].get_cursor().get_data() == word)
		{
			return Table[i].get_cursor().get_id();
		}
		Table[i].move_cursor();
	}
	return -1;
}

void htID::insertWord(wordID d)
{
	if (Table[hash(d.get_data())].is_empty())
	{
		Table[hash(d.get_data())].add_start(d);
	}
	else
	{
		Table[hash(d.get_data())].add_end(d);
	}
}


int htID::count_bucket(int index)
{
	return Table[index].get_length();
}

void htID::print_bucket(int index)
{
	Table[index].begin_cursor();

	while (!Table[index].off_end())
	{
		cout << "word" << Table[index].get_cursor().get_data() << endl;
		cout << "ID" << Table[index].get_cursor().get_id() << endl;
		Table[index].move_cursor();
	}
}


