/*
 * Menu.cpp
 *
 *  Created on: Dec 6, 2016
 *      Author: snysn7
 */

//============================================================================
// Name        : Menu.cpp
// Author      : Group 7
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include<stdio.h>
#include<stdlib.h>
#include <fstream>
#include "Hash_Table.h"
#include "Recipes.h"
#include "BinarySearchTree.h"
#include <sstream>
#include <locale>

using namespace std;

int main() {

	ifstream inputFile;
	ofstream outputFile;

	int menuOption;
	int searchSubMenu;
	int listSubMenu;
	int i=0,j=0;
	string title;
	string chef;
	string difficulty;
	string ingredients;
	string direction;


	Recipes r1;
	htID htnumber;
	Hash_Table ht;
	BinarySearchTree<Recipes> b;
	BinarySearchTree<Recipes> b2;

	int count = 0;

	inputFile.open("recipes.txt");
	outputFile.open("Output.txt");


    if (!inputFile)
    {
        cout << "Input file opening failed." << endl;
        return(-1);
    }
    else
    {
    	while(!inputFile.eof())
    	{

    		getline(inputFile,title);
    		getline(inputFile,chef);
    		getline(inputFile,difficulty);
    		getline(inputFile,ingredients);
    		getline(inputFile,direction);

    		r1.set_title(title);
    		r1.set_chef(chef);
    		r1.set_difficulty(difficulty);
    		r1.set_ingredients(ingredients);
    		r1.set_direction(direction);

    		if (r1.get_difficulty()== "Easy")
    		{
    			i++;
    		}
    		if(r1.get_difficulty()== "Intermediate")
    		{
    			j++;
    		}

    		stringstream ss(ingredients);
    		string keyword;

    		while(ss >> keyword)
    		{

    			//int count = 0;

    			if ( keyword != "1" && keyword != "2" && keyword != "teaspoon" && keyword !="1/2" && keyword != "cups"
    				&& keyword != "packed" && keyword != "teaspoons"  && keyword !=  "cup"  && keyword != "peeled"
    				&& keyword != "cored" && keyword !=  "chopped"  && keyword != "tablespoons"  && keyword != "4"
    				&& keyword != "softened"  && keyword != "3/4"  && keyword != "3"  && keyword != "to"  && keyword != "medium"
    				&& keyword != "30"  && keyword != "40"  && keyword != "1/4"  && keyword != "for"  && keyword != "more"
    				&& keyword != "and/or"  && keyword != "for"  && keyword != "serving"  && keyword != "9"  && keyword != "6"
    				&& keyword != "28" && keyword != "2/3"  && keyword != "ounces"  && keyword != "ounce"  && keyword != "percent"
    				&& keyword != "12" && keyword != "each" && keyword != "serving" && keyword != "5" && keyword != "(12-ounce)"
    				&& keyword != "(8-ounce)" && keyword != "store-bought" && keyword != "such" && keyword != "as" && keyword != "current")
    			{


    				if ( htnumber.findID(keyword) != -1 )
    				{
    					int tempID = htnumber.findID(keyword);
    					if ( !ht.find_dupli(tempID, r1.get_title()) )
    					{
    						wordID w (keyword, tempID);
    						ht.insert(w, r1);
    					}

    				}

    				else
    				{
    					int ID = count++;
    					wordID w(keyword, ID);
    					htnumber.insertWord(w);
    					ht.insert(w, r1);


    				}
    			}


    		}

    		//ht.insert(r1);
    		b.insertTitle(r1);
    		b2.insertChef(r1);


    	}


    	//ht.print_table();
    	//ht.print_bucket(22);

		//b.inOrderPrint();
    }

    inputFile.close();
    //outputFile.close();




	do
	{
		cout << "========== Recipes Menu ==========" << endl;
		cout << "* 1. Add a recipe to the list    *" << endl;
		cout << "* 2. Delete a recipe             *" << endl;
		cout << "* 3. Search for a recipe         *" << endl; //sub menu
		cout << "* 4. Print recipes                *" << endl; //sub menu
		cout << "* 5. Write a recipe to a file    *" << endl;
		cout << "* 6. Statistics about recipes    *" << endl;
		cout << "* 7. Quit                        *" << endl;
		cout << "==================================" << endl;
		cout << endl;
		cout << "Enter in a number from 1-7: ";
		cout << endl;
		cin >> menuOption;
		cin.clear(); //test
		cin.ignore(); // test
		cout << endl;


	if(menuOption < 1 || menuOption > 7||isalpha(menuOption))
		{
			cout << "Please enter in a valid option, press any key to continue. " << endl;

			cin.clear();
			cin.ignore(256,'\n');


		}


		else if(menuOption == 1)
		{
			cout << "Enter in the title of the recipe: ";
			getline(cin, title);

			if (b.findTitle2(title) == true)
			{
				cout << "Recipe already exists." << endl << endl;
			}
			else
			{

			cout << "Enter in the chef of the recipe: ";
			//cin.ignore();
			getline(cin, chef);
			cout << "Enter in the difficulty of the recipe: ";
			//cin.ignore();
			getline(cin, difficulty);
			cout << "Enter in the ingredients required for the recipe: ";
			//cin.ignore();
			getline(cin, ingredients);
			cout << "Enter in the directions for the recipe: ";
			//cin.ignore();
			getline(cin, direction);
			cout << endl;
			}

			r1.set_title(title);
			r1.set_chef(chef);
			r1.set_difficulty(difficulty);
			r1.set_ingredients(ingredients);
			r1.set_direction(direction);





			if (r1.get_difficulty()=="Easy")
				{
					i++;
				}
				if(r1.get_difficulty()=="Intermediate")
				{
					j++;
				}
			b.insertTitle(r1);
			b2.insertChef(r1);
			stringstream ss(ingredients);
			    		string keyword;

			while(ss >> keyword)
			{

				//int count = 0;

				if ( keyword != "1" && keyword != "2" && keyword != "teaspoon" && keyword !="1/2" && keyword != "cups"
					&& keyword != "packed" && keyword != "teaspoons"  && keyword !=  "cup"  && keyword != "peeled"
					&& keyword != "cored" && keyword !=  "chopped"  && keyword != "tablespoons"  && keyword != "4"
					&& keyword != "softened"  && keyword != "3/4"  && keyword != "3"  && keyword != "to"  && keyword != "medium"
					&& keyword != "30"  && keyword != "40"  && keyword != "1/4"  && keyword != "for"  && keyword != "more"
					&& keyword != "and/or"  && keyword != "for"  && keyword != "serving"  && keyword != "9"  && keyword != "6"
					&& keyword != "28" && keyword != "2/3"  && keyword != "ounces"  && keyword != "ounce"  && keyword != "percent"
					&& keyword != "12" && keyword != "each" && keyword != "serving" && keyword != "5" && keyword != "(12-ounce)"
					&& keyword != "(8-ounce)" && keyword != "store-bought" && keyword != "such" && keyword != "as" && keyword != "current")
				{


					if ( htnumber.findID(keyword) != -1 )
					{
						int tempID = htnumber.findID(keyword);
						if ( !ht.find_dupli(tempID, r1.get_title()) )
						{
							wordID w (keyword, tempID);
							ht.insert(w, r1);
						}

					}

					else
					{
						int ID = count++;
						wordID w (keyword, ID);
						htnumber.insertWord(w);
						ht.insert(w, r1);


					}
				}

		}
		}
		else if(menuOption == 2)
		{
			cout<<endl;
			cout << "Enter the title of the recipe to delete"<<endl;
//			cin.ignore();
			getline(cin,title);
			r1.set_title(title);
			b.removeTitle(r1);
			b2.removeTitle(r1);

			int index = htnumber.findID(title);
			ht.remove(index,r1);

			if (r1.get_difficulty()=="Easy")
				{
					i--;
				}
				if(r1.get_difficulty()=="Intermediate")
				{
					j--;
				}



			//call bst and hash table remove on del
		}
		else if(menuOption == 3)
		{
			//string titleBST;
			cout << "1. Search for recipe containing the title" << endl;
			cout << "2. Search for recipe containing key word" << endl;
			cout << "Enter in your option 1 or 2: ";
			cin >> searchSubMenu;
			cout << endl;
			if(searchSubMenu == 1)
			{
				//call bst find on title and print out
				cout<<"Please enter the recipe that you want"<<endl;
				cin.ignore();
				getline(cin,title);
				b.findTitle(title);
			}
			else if(searchSubMenu == 2)
			{
				string keyWord;
				int index;
				cout << "Enter in a key word: ";
				cin >> ws;
				getline(cin, keyWord);

				index = htnumber.findID(keyWord);
				if ( index != -1)
				{
					cout << "Here are the recipes include " << keyWord << endl << endl;
					ht.findInt(index);
				}
				else cout << "Recipes not found" << endl << endl;
			}
		}
		else if(menuOption == 4)
		{
			cout << "1. Print unsorted data (The input order)" << endl;
			cout << "2. Print sorted by chef name(alphabet order)" << endl;
			cout << "Enter in your option 1, 2: ";
			cin >> listSubMenu;
			cout << endl;
			if(listSubMenu == 1)
			{
				b.inOrderPrint();
			}
			else if(listSubMenu == 2)
			{

				b2.inOrderPrint();
			}



		}
		else if(menuOption == 5)
		{
			//string titleList;
			//cout <<"Enter in the title of the recipe you want to print out to a file: " << endl;
			//cin.ignore();
			//getline(cin, title);

			//b.findTitle(title);
			//r1.set_title(title);
			//outputFile<<b.findTitle(title);
			//outputFile <<"Title:"<<r1.get_title();
			//outputFile <<endl;
			b.inOrderPrint1(outputFile);


			/*
			r1.set_chef(chef);
			outputFile<<"chef:"<<outputFile<<r1.get_chef();
			outputFile <<endl;
			r1.set_difficulty(difficulty);
			outputFile<<"difficulty:"<<r1.get_difficulty();
			outputFile <<endl;
			r1.set_ingredients(ingredients);
			outputFile<<"ingredients:"<<r1.get_ingredients();
			outputFile <<endl;
			r1.set_direction(direction);
			outputFile<<"direction:"<<r1.get_direction();
			*/
			outputFile.close();


			//find the recipe they want to print
			//call bst print function on an output file
		}
		else if(menuOption == 6)
		{
			cout << "Total Recipes: " << b.getSize() << endl;

			cout<<"Easy:" << i << endl;
			cout<<"Intermediate:" <<j<<endl;;
			//cout<<"Complicate";
			//display difficulty, common ingredients, and something else
		}
		else if(menuOption == 7)
		{
			cout << "Good bye!" << endl;
		}

	//cin.clear();
	}while(menuOption != 7);


	return 0;
}



