/*
 * Hash_Table.h
 *
 *  Created on: Dec 5, 2016
 *      Author: snysn7
 */

#ifndef HASH_TABLE_H_
#define HASH_TABLE_H_

#include <string>
#include "List.h"
#include "wordID.h"
#include "Recipes.h"
#include "ht2.h"
using namespace std;

class Hash_Table {
public:
    /**Constructors*/

    Hash_Table();
    //constructor

    ~Hash_Table();
    //destructor

    /**Access Functions*/

    int count_bucket(int index);
    //counts the number of Books at this index
    //returns the count
    //pre: 0<= index < SIZE

    void findInt(int index);
    //Searches for b in the table
    //returns the index at which b is located
    //returns -1 if b is not in the table

    /**Manipulation Procedures*/

    void insert(wordID d, Recipes b);
    //inserts a new book into the table
    //calls the hash function on the key to determine
    //the correct bucket

    void remove(int index, Recipes b);
    //removes b from the table
    //calls the hash function on the key to determine
    //the correct bucket

    /**Additional Functions*/


    void print_table();
    //Prints the first book at each index
    //along with a count of the total books
    //at each index by calling count_bucket

    bool find_dupli(int index, string keyword);


private:
    static const int SIZE = 1500;
    List<Recipes> Table[SIZE];
};

#endif /* HASH_TABLE_H_ */
