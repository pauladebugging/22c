/*
 * Recipes.cpp
 *
 *  Created on: Dec 5, 2016
 *      Author: snysn7
 */

#include "Recipes.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

Recipes::Recipes():title(" "), chef(" "), difficulty(" "), ingredients(" "), direction(" "){};

Recipes::Recipes(string t, string c,string dif, string i, string dir) {
    title = t;
    chef = c;
    difficulty = dif;
    ingredients = i;
    direction = dir;

}

/**Access Functions*/

string Recipes::get_title()
{
    return title;
}

string Recipes::get_chef()
{
	return chef;
}


string Recipes::get_difficulty()
{
	return difficulty;
}

string Recipes::get_ingredients()
{
    return ingredients;
}

string Recipes::get_direction()
{
    return direction;
}


/**Manipulation Procedures*/

void Recipes::set_title(string t){
    title = t;
}

void Recipes::set_chef(string c)
{
	chef = c;
}



void Recipes::set_difficulty(string dif)
{
	difficulty = dif;
}

void Recipes::set_ingredients(string i)
{
    ingredients = i;
}

void Recipes::set_direction(string dir)
{
	direction = dir;
}


/**Additional Functions*/
void Recipes::print_recipes() {

    cout << "Title:"<<get_title() << endl;
    cout << "Chef: " << get_chef() << endl;
    cout << "Difficulty: " << get_difficulty() << endl;
    cout << "Ingredients: " << get_ingredients() << endl;
    cout << "Direction: " << get_direction() << endl;

}

void Recipes::print_recipesOutput(ofstream &outputFile)
{
	outputFile << "Title:"<<get_title() << endl;
	outputFile << "Chef: " << get_chef() << endl;
	outputFile << "Difficulty: " << get_difficulty() << endl;
	outputFile << "Ingredients: " << get_ingredients() << endl;
	outputFile << "Direction: " << get_direction() << endl;
}


/*
void Recipes::setDiff(string difficlty)
{
	int e, i, c;
	if (get_difficulty() == "Easy")
	{
		e++;
	}
	else if (get_difficulty() == "Intermediate")
	{
		i++;
	}
	else if (get_difficulty() == "Complicate")
	{
		c++;
	}
}

int Recipes::getDiff()
{
	return e;
	//return i;
	//return c;

}
*/
bool Recipes::operator==(Recipes& recipes)
{
    return (title == recipes.title && chef == recipes.chef && difficulty == recipes.difficulty && ingredients == recipes.ingredients && direction == recipes.direction);
}



