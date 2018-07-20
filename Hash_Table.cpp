/*
 * Hash_Table.cpp
 *
 *  Created on: Dec 5, 2016
 *      Author: snysn7
 */

#include "Hash_Table.h"
#include <iostream>
#include <string>


using namespace std;

Hash_Table::Hash_Table(){}

Hash_Table::~Hash_Table(){}

void Hash_Table::findInt(int index)
{
	Table[index].begin_cursor();

	while (!Table[index].off_end())
	{
		cout << "Title: " <<Table[index].get_cursor().get_title() << endl;
		//cout << "Chef: " << Table[index].get_cursor().get_chef() << endl;
		//cout << "Difficulty: " << Table[index].get_cursor().get_difficulty()<< endl;
		//cout << "Ingredients: " << Table[index].get_cursor().get_ingredients() << endl;
		//cout << "Direction: " << Table[index].get_cursor().get_direction() << endl;
		//cout << endl;
		Table[index].move_cursor();
	}
}


int Hash_Table::count_bucket(int index)
{
	return Table[index].get_length();
}


void Hash_Table::insert(wordID d,Recipes b)
{
	if ( Table[d.get_id()].is_empty() )
	{

		Table[d.get_id()].add_start(b);
	}
	else
	{
		Table[d.get_id()].add_end(b);
	}
}


void Hash_Table::remove(int index, Recipes b)
{
	Table[index].begin_cursor();
	while (!Table[index].off_end())
		{
			if (Table[index].get_cursor().get_title() == b.get_title())
			{
				Table[index].remove_cursor();
			}
			Table[index].move_cursor();
		}

}

void Hash_Table::print_table()
{
	for (int i =0;i<SIZE;i++)
	{

		if (!Table[i].is_empty())
		{
			cout << "<----------------------->" << endl;

			cout << "Bucket: " << i << endl;
			cout << "Title: " << Table[i].get_start().get_title() << endl;
			cout << "Chef: " << Table[i].get_start().get_chef() << endl;
			cout << "Difficulty: " << Table[i].get_start().get_difficulty()<< endl;
			cout << "Ingredients: " << Table[i].get_start().get_ingredients() << endl;
			cout << "Direction: " << Table[i].get_start().get_direction() << endl;
			cout << "<----------------------->" << endl;
		}
	}
}

bool Hash_Table::find_dupli(int index, string keyword)
{
	Table[index].begin_cursor();

	while (!Table[index].off_end())
	{

		if ( Table[index].get_cursor().get_title() == keyword)
		{
			//cout << keyword << " found" << endl;
			return true;


		}
		else Table[index].move_cursor();
	}
	//cout << keyword << " not found" << endl;
	return false;
}


