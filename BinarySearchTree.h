#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include <cstdlib>
#include <cstddef>
#include <string>
#include <iostream>
#include <iomanip>
#include <assert.h>
#include "Recipes.h"

using namespace std;

template <class bstitem>
class BinarySearchTree
{
    private:
        struct Node
        {
                bstitem data;
                Node* left;
                Node* right;

                Node(bstitem newdata): data(newdata), left(NULL), right(NULL) {}
        };

        typedef struct Node* NodePtr;
        NodePtr root;


        /**Private helper functions*/

        void insertTitleHelper(NodePtr root, bstitem value);
        //private helper function for insert
        //recursively inserts a value into the BST

        void insertChefHelper(NodePtr root, bstitem value);

        NodePtr removeTitleHelper(NodePtr root, bstitem value);

        NodePtr removeChefHelper(NodePtr root, bstitem value);

        int getSizeHelper(NodePtr root);

        int getHeightHelper(NodePtr root);

        bstitem getRootHelper(NodePtr root);

        void inOrderPrintHelper(NodePtr root);
        void inOrderPrintHelper1(NodePtr root, ofstream& outputFile);
        //private helper function for inOrderPrint
        //recursively prints tree values in order from smallest to largest

        void preOrderPrintHelper(NodePtr root);
        //private helper function for preOrderPrint
        //recursively prints tree values in preorder

        void postOrderPrintHelper1(NodePtr root);
        //private helper function for postOrderPrint
        //recursively prints tree values in postorder

        bstitem minimumHelper(NodePtr root);

        bstitem maximumHelper(NodePtr root);

        bool findTitleHelper(NodePtr root, string title);

        bool findChefHelper(NodePtr root, bstitem value);

        void destructorHelper(NodePtr root);

        void copyHelper(NodePtr &copy, NodePtr original);

        int getDiffHelper(NodePtr root);
        void findTitleHelper1(NodePtr root, string title);

        /**Public functions*/

        bool findTitle2Helper(NodePtr root, string title);

    public:
        BinarySearchTree();
        //Instantiates a new Binary Search Tree
        //post: a new Binary Search Tree object

        ~BinarySearchTree();

        BinarySearchTree(const BinarySearchTree<bstitem> &original);

        bool isEmpty();
        //determines whether the Binary Search Tree is empty

        void insertTitle(bstitem value);
        //inserts a new value into the Binary Search Tree
        //post: a new value inserted into the Binary Search Tree

        void insertChef(bstitem value);

        void removeTitle(bstitem value);
        //removes the specified value from the tree
        //Pre: !isEmpty()
        //Pre: The value is contained in the Binary Search Tree
        //If the value is not in the Binary Search Tree, the tree is left unchanged

        void removeChef(bstitem value);

        int getSize();
        //returns the size of the tree

        int getHeight();
        //recursively finds the height of the tree and returns it
        //Pre: !isEmpty()

        bstitem getRoot();
        //returns the value stored at the root of the Binary Search Tree
        //pre: the Binary Search Tree is not empty

        void inOrderPrint();
        void inOrderPrint1(ofstream& outputFile);
        //calls the inOrderPrintHelper function to print out the values
        //stored in the Binary Search Tree
        //If the tree is empty, prints nothing

        void preOrderPrint();
        //calls the preOrderPrintHelper function to print out the values
        //stored in the Binary Search Tree
        //If the tree is empty, prints nothing

        void postOrderPrint();
        //calls the postOrderPrintHelper function to print out the values
        //stored in the Binary Search Tree
        //If the tree is empty, prints nothing

        bstitem minimum();
        //finds the minimum value in the Binary Search Tree and returns it
        //pre: !isEmpty()

        bstitem maximum();
        //finds the maximum value in the Binary Search Tree and returns it
        //pre: !isEmpty()

        bool findTitle(string title);
        //returns whether the value is in the tree
        //Pre: !isEmpty()

        void findChef(bstitem value);

        void recipes_output(string, ofstream &outputFile);


        bool findTitle2(string title);


};

template<class bstitem>
BinarySearchTree<bstitem>::BinarySearchTree():root(NULL){}

template<class bstitem>
BinarySearchTree<bstitem>::~BinarySearchTree()
{
	destructorHelper(root);
}

template<class bstitem>
void BinarySearchTree<bstitem>::destructorHelper(NodePtr root)
{

	if ( root != NULL)
	{
		destructorHelper(root->left);
		destructorHelper(root->right);
		delete root;
	}

}

template<class bstitem>
BinarySearchTree<bstitem>::BinarySearchTree(const BinarySearchTree<bstitem> &original)
{
	copyHelper( root, original.root );
}

template<class bstitem>
void BinarySearchTree<bstitem>::copyHelper(NodePtr &copy, NodePtr original)
{
	if (original == NULL)
	{
		copy = NULL;
	}
	else
	{

		copy = new Node(original->data);
		copyHelper( copy->left, original->left );
		copyHelper( copy->right,original->right );
	}
}

template<class bstitem>
bool BinarySearchTree<bstitem>::isEmpty()
{
	if ( getSize() == 0 )
	{
		return true;
	}
	else return false;
}

template <class bstitem>
void BinarySearchTree<bstitem>::insertTitleHelper(NodePtr root, bstitem value)
{
	if (value.get_title() == root->data.get_title())
	    {
	        return;
	    }
	    else if(value.get_title() < root->data.get_title())
	    {

	        if(root->left == NULL)
	        {
	            root->left= new Node(value);
	        }
	        else
	        {
	            insertTitleHelper(root->left, value);
	        }

	    }
	    else
	    {
	        if(root->right == NULL)
	        {
	            root->right = new Node(value);
	        }
	        else
	        {
	            insertTitleHelper(root->right, value);
	        }

	    }

}

template <class bstitem>
void BinarySearchTree<bstitem>::insertTitle(bstitem value)
{
    if ( isEmpty() )
    {
        root = new Node(value); //if the tree is empty insert the value at the root
    }
    else
    {
        insertTitleHelper(root, value); //otherwise call the helper function, passing it the root
    }
}

template <class bstitem>
void BinarySearchTree<bstitem>::insertChefHelper(NodePtr root, bstitem value)
{
	if (value.get_chef() == root->data.get_chef())
	    {
	        return;
	    }
	    else if(value.get_chef() < root->data.get_chef())
	    {

	        if(root->left == NULL)
	        {
	            root->left= new Node(value);
	        }
	        else
	        {
	            insertChefHelper(root->left, value);
	        }

	    }
	    else
	    {
	        if(root->right == NULL)
	        {
	            root->right = new Node(value);
	        }
	        else
	        {
	            insertChefHelper(root->right, value);
	        }

	    }

}

template <class bstitem>
void BinarySearchTree<bstitem>::insertChef(bstitem value)
{
    if ( isEmpty() )
    {
        root = new Node(value); //if the tree is empty insert the value at the root
    }
    else
    {
        insertChefHelper(root, value); //otherwise call the helper function, passing it the root
    }
}

template <class bstitem>
typename BinarySearchTree<bstitem>::NodePtr BinarySearchTree<bstitem>::removeTitleHelper(NodePtr root, bstitem value)
{
	if ( root == NULL )
	{
		return root;
	}
	else if ( value.get_title() < root->data.get_title())
	{
		root->left = removeTitleHelper ( root->left, value );
	}
	else if ( value.get_title() > root->data.get_title() )
	{
		root->right = removeTitleHelper (root->right, value );
	}
	else
	{
		if ( root->right == NULL && root->left == NULL )
		{
			delete root;
			root = NULL;
		}
		else if ( root->right == NULL && root->left != NULL )
		{
			NodePtr temp = root;
			root = root->left;
			delete temp;
		}
		else if ( root->right != NULL && root->left == NULL)
		{
			NodePtr temp = root;
			root = root->right;
			delete temp;
		}
		else
		{
			bstitem min = minimumHelper ( root->right );
			root->data = min;
			root->right = removeTitleHelper(root->right, root-> data);
		}
	}

	return root;

}

template <class bstitem>
void BinarySearchTree<bstitem>::removeTitle(bstitem value)
{
	assert ( !isEmpty() );
	root = removeTitleHelper(root, value);
	getSize();
}

template <class bstitem>
typename BinarySearchTree<bstitem>::NodePtr BinarySearchTree<bstitem>::removeChefHelper(NodePtr root, bstitem value)
{
	if ( root == NULL )
	{
		return root;
	}
	else if ( value.get_chef() < root->data.get_chef())
	{
		root->left = removeChefHelper ( root->left, value );
	}
	else if ( value.get_chef() > root->data.get_chef() )
	{
		root->right = removeChefHelper (root->right, value );
	}
	else
	{
		if ( root->right == NULL && root->left == NULL )
		{
			delete root;
			root = NULL;
		}
		else if ( root->right == NULL && root->left != NULL )
		{
			NodePtr temp = root;
			root = root->left;
			delete temp;
		}
		else if ( root->right != NULL && root->left == NULL)
		{
			NodePtr temp = root;
			root = root->right;
			delete temp;
		}
		else
		{
			bstitem min = minimumHelper ( root->right );
			root->data = min;
			root->right = removeChefHelper(root->right, root-> data);
		}
	}

	return root;

}

template <class bstitem>
void BinarySearchTree<bstitem>::removeChef(bstitem value)
{
	assert ( !isEmpty() );
	root = removeChefHelper(root, value);
	getSize();

}


template<class bstitem>
int BinarySearchTree<bstitem>::getSizeHelper(NodePtr root)
{
    int size = 0;
	if (root == NULL)
	    {
	        return size;
	    }
	    else
	    {
	        size = getSizeHelper( root->left ) + 1 + getSizeHelper(root -> right);
	        return size;
	    }

}

template <class bstitem>
int BinarySearchTree<bstitem>::getSize()
{
	return getSizeHelper(root);
}


template <class bstitem>
int BinarySearchTree<bstitem>::getHeight()
{
	assert ( !isEmpty() );

	return getHeightHelper(root);
}

template <class bstitem>
int BinarySearchTree<bstitem>::getHeightHelper(NodePtr root)
{

	if(root != NULL && root->left ==NULL && root->right == NULL)
	{
		return 0;
	}
	else
	{
		int Lheight = 0;
		int Rheight = 0;

		Rheight = getHeightHelper(root->right);
		Lheight = getHeightHelper(root->left);

		if(Lheight < Rheight)
		{
			return Rheight+1;
		}
		else
		{
			return Lheight+1;
		}
	}

}

template <class bstitem>
bstitem BinarySearchTree<bstitem>::getRoot()
{
	assert ( !isEmpty() );

	return getRootHelper(root);
}

template <class bstitem>
bstitem BinarySearchTree<bstitem>::getRootHelper(NodePtr root)
{

	return root->data;

}

template <class bstitem>
void BinarySearchTree<bstitem>::inOrderPrint()
{
	inOrderPrintHelper(root);
	 cout << endl;
}

template <class bstitem>
void BinarySearchTree<bstitem>::inOrderPrintHelper(NodePtr root)
{

	if (root == NULL)
	{
		return;
	}

	inOrderPrintHelper(root->left);
	root->data.print_recipes();
	cout << endl;
	inOrderPrintHelper(root->right);

}

/*
template <class bstitem>
void BinarySearchTree<bstitem>::preOrderPrint()
{
	preOrderPrintHelper(root);
	cout << endl;
}

template <class bstitem>
void BinarySearchTree<bstitem>::preOrderPrintHelper(NodePtr root)
{

	if (root == NULL)
	{
		return;
	}

	root->data.print_recipes();
	cout << endl;
	preOrderPrintHelper(root->left);
	preOrderPrintHelper(root->right);

}

template <class bstitem>
void BinarySearchTree<bstitem>::postOrderPrint()
{
	postOrderPrintHelper(root);
	cout << endl;
}

template <class bstitem>
void BinarySearchTree<bstitem>::postOrderPrintHelper(NodePtr root)
{

	if (root == NULL)
	{
		return;
	}

	postOrderPrintHelper(root->left);
	postOrderPrintHelper(root->right);
	root->data.print_recipes();
	cout << endl;

}
*/

template <class bstitem>
bstitem BinarySearchTree<bstitem>::minimum()
{
	assert ( !isEmpty() );
	return minimumHelper(root);
}

template <class bstitem>
bstitem BinarySearchTree<bstitem>::minimumHelper(NodePtr root)
{

	if ( root-> left == NULL)
	{
		return root->data;
	}
	else
	{
		return minimumHelper(root->left);
	}

}

template <class bstitem>
bstitem BinarySearchTree<bstitem>::maximum()
{
	assert ( !isEmpty() );
	return maximumHelper(root);
}

template <class bstitem>
bstitem BinarySearchTree<bstitem>::maximumHelper(NodePtr root)
{

	if ( root-> right == NULL)
	{
		return root->data;
	}
	else
	{
		return maximumHelper(root->right);
	}
}

template <class bstitem>
bool BinarySearchTree<bstitem>::findTitle(string title)
{
	assert ( !isEmpty() );
	if ( title == root->data.get_title())
	{
		root->data.print_recipes();
		return true;
	}
	else
	{
		return findTitleHelper(root, title);
	}
	return false;
}

template <class bstitem>
bool BinarySearchTree<bstitem>::findTitleHelper(NodePtr root, string title)
{

	if ( title == root->data.get_title() )
	{

		root->data.print_recipes();
		return true;

	}
	else if ( title < root->data.get_title() )
	{
		if ( root->left == NULL)
		{
			return false;
		}
		else
		{
			return findTitleHelper(root->left, title);
		}
	}
	else if ( title > root->data.get_title() )
	{
		if ( root->right == NULL)
		{
			return false;
		}
		else
		{
			return findTitleHelper(root->right, title);
		}
	}
	return false;
}

template <class bstitem>
void BinarySearchTree<bstitem>::findChef(bstitem value)
{
	assert ( !isEmpty() );
	findChefHelper(root, value);

}

template <class bstitem>
bool BinarySearchTree<bstitem>::findChefHelper(NodePtr root, bstitem value)
{
	if ( value == root->data.get_chef() )
	{
		return true;
	}
	else if ( value < root->data.get_chef() )
	{
		if ( root->left == NULL)
		{
			return false;
		}
		else
		{
			return findChefHelper(root->left, value);
		}
	}
	else
	{
		if ( root->right == NULL)
		{
			return false;
		}
		else
		{
			return findChefHelper(root->right, value);
		}
	}
	return false;
}


template <class bstitem>
void BinarySearchTree<bstitem>::recipes_output(string title, ofstream &outputFile)
{
	outputFile << findTitle(title);
}


/*
template <class bstitem>
int BinarySearchTree<bstitem>::getDiffHelper(NodePtr root)
{
	int e = 0, i = 0, c = 0;
	if (root == NULL)
	{
		return e;
	}
	else
	{
		if (root->data.get_difficulty() == "Easy")
		{
			e = getDiffHelper(root->left) + 1 +  getDiffHelper(root->right);
		}
	}
	//getDiffHelper(root->left);
	//getDiffHelper(root->right);

	/*
	else if (root->data.get_diffcluty() == "Intermediate")
	{
		i++;
	}
	else if (root->data.get_diffcluty() == "Complicate")
	{
		c++;
	}


	return e, i, c;
	*/

template <class bstitem>
void BinarySearchTree<bstitem>::inOrderPrint1(ofstream& outputFile)
{
	inOrderPrintHelper1(root,outputFile);
}

template <class bstitem>
void BinarySearchTree<bstitem>::inOrderPrintHelper1(NodePtr root, ofstream& outputFile)
{

	if (root == NULL)
		{
			return;
		}

		inOrderPrintHelper1(root->left,outputFile);
		root->data.print_recipesOutput(outputFile);

		inOrderPrintHelper1(root->right,outputFile);
}

template <class bstitem>
bool BinarySearchTree<bstitem>::findTitle2(string title)
{
	assert (!isEmpty());

	if (title == root->data.get_title())
	{
		return true;
	}
	else
	{
		return findTitle2Helper(root, title);
	}
	return false;
}

template <class bstitem>
bool BinarySearchTree<bstitem>::findTitle2Helper(NodePtr root, string title)
{

	if (title == root->data.get_title())
	{

		return true;

	}
	else if (title < root->data.get_title())
	{
		if ( root->left == NULL)
		{
			return false;
		}
		else
		{
			return findTitle2Helper(root->left, title);
		}
	}
	else if (title > root->data.get_title())
	{
		if (root->right == NULL)
		{
			return false;
		}
		else
		{
			return findTitle2Helper(root->right, title);
		}
	}
}

#endif /* SRC_BINARYSEARCHTREE_H_ */
