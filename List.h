/*
 * List.h
 *
 *  Created on: Dec 5, 2016
 *      Author: snysn7
 */

#ifndef LIST_H_
#define LIST_H_


#include <cstddef> //for NULL
#include <assert.h>
#include <iostream>

using namespace std;

template <class listitem>
class List
{
    private:
             struct Node
             {
            	listitem data;
                Node* next;
                Node* previous;

                Node(listitem data): next(NULL), previous(NULL), data(data){}
             };

             typedef struct Node* NodePtr;

             NodePtr start;
             NodePtr end;
             NodePtr cursor;

             int length;

             void reverse(NodePtr node);
             //Helper function for the public printReverse() function.
             //Recursively prints the data in a List in reverse.


    public:

        /**Constructors and Destructors*/

        List();
        //Default constructor; initializes and empty list
        //Postcondition: initializes the list and get it ready to use

        ~List();
        //Destructor. Frees memory allocated to the list
        //Postcondition:delete all the data and pointers of the list

        List(const List &list);
        //Copy construcor. Initializes list to have the same elements as another list
        //Postcondition: copy the data from the list to a new list

        /**Accessors*/


        listitem get_start();
        //Returns the first element in the list
        //Precondition: the list must not be empty


        listitem get_end();
        //Returns the last element in the list
        //Precondition: the list must not be empty


        listitem get_cursor();
        //Returns the element pointed to by the iterator
        //Precondition: the list must not be empty


        bool is_empty();
        //Determines whether a list is empty.



        bool off_end();
        //Determines if the iterator is off the end of the list (i.e. whether cursor is NULL)


        int get_length();
        //Returns the length of the list


        /**Manipulation Procedures*/

        void begin_cursor();
        //Moves the iterator to point to the first element in the list
        //If the list is empty, the iterator remains NULL
        //Postcondition: move the cursor to the first element on the list


        void add_cursor(listitem data);
        //Inserts a new element into the list in the position after the iterator
        //Precondition: the list must not be empty
        //Postcondition: add a pointer which can move around the list

        void remove_end();
        //Removes the value of the last element in the list
        //Precondition: the list must not be empty
        //Postcondition: remove the last value of the list

        void remove_start();
        //Removes the value of the first element in the list
        //Precondition: the list must not be empty
        //Postcondition: remove the first value of the list

        void add_end(listitem data);
        //Inserts a new element at the end of the list
        //If the list is empty, the new element becomes both start and end
        //Postcondition: add one value in the end of the list, and it become last value

        void add_start(listitem data);
        //Inserts a new element at the start of the list
        //If the list is empty, the new element becomes both start and end
        //Postcondition: add one value in the beginning of the list, and it become first value


        void remove_cursor();
        //Removes the element pointed at by the iterator
        //Precondition: the list must not be empty
        //Postcondition: delete the cursor

        void move_cursor();
        //Moves the iterator forward by one element in the list
        //Precondition: the list must not be empty
        //Postcondition: the output value is the next value in the list of the iterator pointed to


        /**Additional List Operations*/

        void print();
        //Prints to the console the value of each element in the list sequentially
        //and separated by a blank space
        //Prints nothing if the list is empty

        bool operator== (const List &list);

        void print_reverse();
        //Wrapper function that calls the reverse helper function to print a list in reverse
        //prints nothing if the List is empty

        int get_index();
        //Indicates the index of the Node where the iterator is currently pointing
        //Nodes are numbered from 1 to length of the list
        //Pre: length != 0
        //Pre: !off_end()

        void scroll_to_index(int index);
        //Moves the iterator to the node whose index is specified by the user
        //Pre: length != 0

        int linear_search(listitem item);
        //Searchs the list, element by element, from the start of the List to the end of the List
        //Returns the index of the element, if it is found in the List
        //Returns -1 if the element is not in the List
        //Pre: length != 0

        int binary_search(int low, int high, listitem item);
        //Recursively searchs the list by dividing the search space in half
        //Returns the index of the element, if it is found in the List
        //Returns -1 if the element is not in the List
        //Pre: length != 0
        //Pre: List is sorted (must test on a sorted list)


};



template <class listitem> //Step 1: template the function
List<listitem>::List(): start(NULL), end(NULL), cursor(NULL), length(0) {}

//Define Destructor

template <class listitem>
List<listitem>::~List()
{
    cursor = start;
    NodePtr temp;
    while(cursor != NULL)
    {
        temp = cursor->next;

        delete cursor;

        cursor = temp;

    }
}

//Define Copy Constructor

template <class listitem>
List<listitem>::List(const List &list): length(list.length)
{
    if(list.start == NULL) //If the original list is empty, make an empty list for this list
    {
        start = end = cursor = NULL;
    }
    else
    {
        start = new Node(list.start->data); //using second Node constructor
        NodePtr temp = list.start; //set a temporary node pointer to point at the start of the original list
        cursor = start; //set iterator to point to start of the new list

        while(temp->next != NULL)
        {

        	temp = temp->next; //advance up to the next node in the original list
            cursor->next = new Node(temp->data); //using node constructor to create a new node with copy of data
            NodePtr N = cursor->next;
            N->previous = cursor;
            cursor = cursor->next; //advance to this new node


        }

        end = cursor;
        cursor = NULL;

    }
}

//Define Print Function

template <class listitem>
void List<listitem>::print()
{
    NodePtr temp = start;
    while (temp != NULL)
    {

        //What two lines of code go here?

        //Hint: One statement should contain a cout

        cout << temp->data << " ";

        temp = temp->next;

    }
    cout << endl;
    //What does this do?
    //It make output going to a new line
}

//Define Remove_start Function

template <class listitem>
void List<listitem>::remove_start()
{
    assert(length != 0);
    if (length==1)
    {
        delete start;
        start = end = cursor = NULL;
        length = 0;
    }
    else
    {
        NodePtr temp = start; //store original start node in a temporary variable
        start = start->next; //make the start pointer point to the second node in the List
        start->previous = NULL;
        delete temp; //delete the original start
        length--;
    }
}

//Define Remove_end Function

template <class listitem>
void List<listitem>::remove_end()
{
	assert (length != 0);
	if (length == 1)
	{
		delete end;
		start = end = cursor = NULL;
		length = 0;
	}
	else
	{

		NodePtr temp = end;
		end = end->previous;
		delete temp;
		end->next = NULL;
		length--;
	}
}

//Define Add_start Function

template <class listitem> //Step 1: template the function
void List<listitem>::add_start(listitem data) //step 2 & 3: List is templated and takes in a generic param
{
    if (length == 0)
    {
        start = new Node(data); //note that although data is of a generic type, we use it as before.
        end = start ;

    }
    else
    {
        NodePtr N = new Node(data);
        N->next = start;
        start->previous = N; //Need to update the previous pointer of start to point back at the new node
        start = N;
        start->previous = NULL;
    }

    length++;

}

//Define add_end Function

template <class listitem>
void List<listitem>::add_end(listitem data)
{
    if (length==0)
    {
    	end = new Node(data);
    	start = end;

    }
    else
    {
        NodePtr N = new Node(data);
        end->next = N;
        N-> previous = end;
        end = N;
        end->next = NULL;
    }

    length++;

}

//Define Begin_cursor Function

template <class listitem>
void List<listitem>::begin_cursor()
{
	cursor = start;
}

//Define Remove_cursor Function

template <class listitem>
void List<listitem>::remove_cursor()
{
	assert (length !=0);
	assert (!off_end());

	if ( cursor == start )
	{
		remove_start();
	}
	else if ( cursor == end )
	{
		remove_end();
	}
	else
	{
		NodePtr temp = cursor;
		cursor->previous->next = cursor->next;
		cursor->next->previous = cursor->previous;
		delete temp;
		length--;
	}
}

//Define Add_cursor Function

template <class listitem>
void List<listitem>::add_cursor(listitem data)
{

	assert (length !=0);
	assert (!off_end());

	if (length == 1)
	{
		NodePtr N = new Node(data);
		cursor->next = N;
		N->previous = cursor;
		length ++;
	}
	else
	{
		NodePtr N = new Node(data);
		N->next = cursor->next;
		N->previous = cursor;
		cursor->next->previous = N;
		cursor->next = N;
		length ++;
	}
}

//Define Move_cursor Function

template <class listitem>
void List<listitem>::move_cursor()
{
	assert (length !=0);
	assert (!off_end());

	cursor = cursor->next;

}

//Define Access Function

template <class listitem>
bool List<listitem>::is_empty()
{
    return (length==0);
}

//Define Get_length Function

template <class listitem>
int List<listitem>::get_length()
{
	return length;
}

//Define Get_start Function

template <class listitem>
listitem List<listitem>::get_start()
{
    assert (length != 0);

    return start-> data;
}

//Define Get_end Function

template <class listitem>
listitem List<listitem>::get_end()
{
	assert (length != 0);
	return end -> data;
}

//Define Off_end Function

template <class listitem>
bool List<listitem>::off_end()
{
	return cursor == NULL;
}

//Define Get_cursor Function

template <class listitem>
listitem List<listitem>::get_cursor()
{
	assert (length != 0);
	assert (!off_end());
	return cursor -> data;
}

//Define Overload Operator ==

template <class listitem>
bool List<listitem>::operator==(const List& list)
{
    if(length != list.length)
        return false;
    NodePtr temp1 = start;
    NodePtr temp2 = list.start;
    while(temp1 != NULL)
    {
        if(temp1->data != temp2->data)
            return false;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}

template <class listitem>
void List<listitem>::print_reverse()
{
	reverse(end);
}

template <class listitem>
void List<listitem>::reverse(NodePtr node)
{
	NodePtr temp = end;
	while (temp != NULL )
	{
		cout << temp->data << " ";
		temp = temp->previous;
	}
	cout << endl;
}

/**Accessor Functions*/


template <class listitem>
int List<listitem>::get_index()
{
	assert (length != 0);
	assert (!off_end());


	NodePtr count = start;

	int index = 1;

	if (index <= length)
	{
		while (count != cursor)
		{
			count = count->next;
			index++;
		}
		return index;
	}

}

/**Manipulation Procedures*/

template <class listitem>
void List<listitem>::scroll_to_index(int index)
{

	assert (length != 0);
	cursor = start;
	for (int i= 1; i < index; i++)
	{
		cursor = cursor->next;
	}

}

template <class listitem>
int List<listitem>::linear_search(listitem item)
{

    assert (length != 0);

    begin_cursor();

    int index = 1;

    for (int i =0; i < length; i++)
    {
    	if (cursor->data == item)
    	{
    		return index;

    	}
    	else
    	{
    		cursor = cursor->next;
    		index++;
    	}

    }
    return -1;

}

template <class listitem>
int List<listitem>::binary_search(int low, int high, listitem item)
{

	assert (length != 0);
	int mid = 0;

	if (low > high)
	{
		return -1;
	}

		mid =low + (high-low)/2;
		scroll_to_index(mid);

		if ( cursor->data == item)
		{
			return get_index();
		}

		if ( item < cursor->data)
		{
			return binary_search(low, mid-1, item);
		}
		else
		{
			return binary_search(mid+1, high, item);
		}

}


#endif /* LIST_H_ */
