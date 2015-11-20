//File:   bst.cpp
//Author: Geoffrey Pitman
//Course: CSC 237
//Date:   April 30, 2015
//Purpose:Implementation of a binary search tree, class bst

#ifndef BST_CPP
#define BST_CPP

#include <iostream>
#include "bst.h"

using namespace std;

//Description: overloaded assignment operator
template <class T>
bst<T>& bst<T>::operator =(const bst<T>& rhs)
{
    if (this != &rhs)
    {
        clearTree();
        root = copy(rhs);
    }
    return *this;
}

//Description: checks the root to see if the tree is empty
template <class T>
bool bst<T>::isEmpty() const
{
    if (root == NULL)
        return true;
    return false;
}

//Description:  Recursively inserts an item into a binary search tree. 
//              duplicates are not allowed.
template <class T>
bool bst<T>::_insert(TreeNode<T> *& treePtr, const T& newItem)
{
    if (treePtr == NULL)
    {
        treePtr = new TreeNode<T>(newItem);
        return true;
    }
    if (treePtr->item == newItem)
        return false;
    else if (newItem < treePtr->item)
        return _insert(treePtr->leftChild, newItem);
    else
        return _insert(treePtr->rightChild, newItem);
}

//Description: Recursively deletes an item with a given search key 
template <class T>
bool bst<T>::_remove(TreeNode<T> *& treePtr, T oldItem)
{
    if (treePtr == NULL)
	{	
		return false;
	}
    if (oldItem < treePtr->item)
    {  
		return _remove(treePtr->leftChild, oldItem);
    }
	else if (oldItem > treePtr->item)
	{      
		return _remove(treePtr->rightChild, oldItem);
	}
    else
    {
        _deleteNode(treePtr);
        return true;
    } 
}

//Description: Deletes the item in pointed to by the nodePtr
template <class T>
void bst<T> ::_deleteNode(TreeNode<T> *& nodePtr)
{
    TreeNode<T> *temp;
    if (nodePtr->leftChild == NULL && nodePtr->rightChild == NULL)
    {
        delete nodePtr;
        nodePtr = NULL;
    }
    else if (nodePtr->leftChild == NULL)
    {
        temp = nodePtr;
        nodePtr = nodePtr->rightChild;
        delete temp;
    }
    else if (nodePtr->rightChild == NULL)
    {
        temp = nodePtr;
        nodePtr = nodePtr->leftChild;
        delete temp;
    }
    else
	{
        nodePtr->item = _removeLeftMostNode(nodePtr->rightChild);
	}
}

//Description: Uses recursion to remove the leftmost node in the right subtree
template <class T>
T bst<T>::_removeLeftMostNode(TreeNode<T> *& ptr)
{
    TreeNode<T> *temp, *value;

    if (ptr->leftChild != NULL)
	{
        return _removeLeftMostNode(ptr->leftChild);
	}
    else
    {
        temp = ptr;
        value->item = ptr->item;
		ptr = ptr->rightChild;
		delete temp;
		return value->item;
    }
}

//Description: Recursively retrieves an item with a given search key. Key value
//            must be set in the item to be retrieved, if found it is filled in.
template <class T>
bool bst<T>::_retrieve(TreeNode<T> *treePtr, T& treeItem) const
{
    if (treePtr == NULL)
        return false;
    if (treePtr->item == treeItem)
    {
        treeItem = treePtr->item;
        return true;
    }
    else if (treeItem < treePtr->item)
        return _retrieve(treePtr->leftChild, treeItem);
    else
        return _retrieve(treePtr->rightChild, treeItem);
}

//Description: Recursively copies the tree rooted at treePtr into a tree rooted at
//             newTreePtr
template <class T>
void bst<T>::_copyTree(TreeNode<T> *treePtr, TreeNode<T> *& newTreePtr) const
{
    if (treePtr == NULL)
        newTreePtr = NULL;
    else
    {
        newTreePtr = new TreeNode<T>(treePtr->item);
        _copyTree(treePtr->leftChild, newTreePtr->leftChild);
        _copyTree(treePtr->rightChild, newTreePtr->rightChild);
    }
}

//Description: Recursively empties out all the nodes in the tree
template <class T>
void bst<T>::_clearTree(TreeNode<T> *& treePtr)
{
    if (treePtr != NULL)
    {
        _clearTree(treePtr->leftChild);
        _clearTree(treePtr->rightChild);
        delete treePtr;
        treePtr = NULL;
    }
}

//Description: Recursively traverses a binary search tree in preorder, printing values out
//              in the outlined form discussed in class**/
template <class T>
void bst<T>::_preorderTraversal(TreeNode<T> *treePtr, int level)
{
    if (treePtr != NULL)
    {
        cout << level << ".";
		for(int idx = 0; idx < level; idx++)
	    {
			cout << "  ";
		}
        cout << treePtr->item << endl;
        level += 1;
        _preorderTraversal(treePtr->leftChild, level);
        _preorderTraversal(treePtr->rightChild, level);
    }
}

//Description: Recursively counts the leaves in the tree
template <class T>
int bst<T>::_leafCount(TreeNode<T> *treePtr)
{
	if (treePtr == NULL)
    {
        return 0;
    }
	else if(treePtr->leftChild == NULL && treePtr->rightChild==NULL)      
		return 1;
    else
        return     _leafCount(treePtr->leftChild) +
                   _leafCount(treePtr->rightChild);
}

//Description: Recursively counts the nodes in the tree
template <class T>
int bst<T>::_nodeCount(TreeNode<T> *treePtr)
{
    if (treePtr == NULL)
    {
        return 0;
    }
    else
        return (1 + _nodeCount(treePtr->leftChild) +
                   _nodeCount(treePtr->rightChild));
    return 0;
}

//Descriptions: Recursively calculates the height of the tree
template <class T>
int bst<T>::_height(TreeNode<T> *treePtr) const
{
    if (treePtr == NULL)
        return 0;
    return 1 + _max(_height(treePtr->leftChild), _height(treePtr->rightChild));
}

//Description: Finds the max of two ints used in height**/
template <class T>
int bst<T>::_max(int one, int two) const
{
    if (one > two)
        return one;
    return two;
}


#endif
