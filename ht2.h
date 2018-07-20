/*
 * ht2.h
 *
 *  Created on: Dec 7, 2016
 *      Author: fycai21
 */

#include <iostream>
#include <string>
#include "List.h"
#include "wordID.h"

class htID
{
public:
    /**Constructors*/

    htID();
    //constructor

    ~htID();
    //destructor

    /**Access Functions*/

    int hash(string key);
    //returns the hash value for the given key
    //the hash value is the sum of
    //of the ASCII values of each char in the key
    //% the size the of the table
    //Key for this table: title + author

    int findID(string word);

    void insertWord(wordID d);

    int count_bucket(int index);

    void print_bucket(int index);

    //bool is_empty(int index);

private:
    static const int SIZE = 1500;
    List<wordID> Table[SIZE];
};

