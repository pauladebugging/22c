/*
 * Recipes.h
 *
 *  Created on: Dec 5, 2016
 *      Author: snysn7
 */

#ifndef RECIPES_H_
#define RECIPES_H_

#include <cstdlib>
#include <cstddef>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Recipes {
private:
    string title;
    string chef;
    string difficulty;
    string ingredients;
    string direction;


public:
    Recipes();
    Recipes(string t, string c, string dif, string i, string dir);

    /**Access Functions*/
    string get_title();
    string get_chef();
    //string get_time();
    //int get_servings();
    string get_difficulty();
    string get_ingredients();
    string get_direction();


    /**Manipulation Procedures*/
    void set_title(string t);
    void set_chef(string c);
    //void set_time(string tm);
    //void set_servings(int s);
    void set_difficulty(string dif);
    void set_ingredients(string i);
    void set_direction(string dir);

    /**Additional Functions*/
    void print_recipes();
    bool operator==(Recipes& recipes);
    //void setDiff(string diff);
    //int getDiff();

    void print_recipesOutput(ofstream &outputFile);


};



#endif /* RECIPES_H_ */
