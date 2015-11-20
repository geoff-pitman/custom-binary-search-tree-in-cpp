//File:   bst.h
//Updated:Geoffrey Pitman
//Author: Linda Day
//Course: CSC 237
//Date:   April 30, 2015
//Purpose:Declaration of a binary search tree, class bst

#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

template <class T>
class bst;

template <class T>
class TreeNode
{
private:
    TreeNode() { rightChild = leftChild = NULL; }
    TreeNode(const T& nodeItem, TreeNode *left = NULL, TreeNode *right = NULL)
        : item(nodeItem), leftChild(left), rightChild(right) {}
    T item;
    TreeNode *leftChild, *rightChild;

    // friend class - can access private parts..............tehe
    friend class bst<T>;
}; // end TreeNode


template <class T>
class bst
{
public:
    // constructors and destructor:
    bst(){ root = NULL; }
    bst(const bst& tree) { _copyTree(tree.root, root); }
    ~bst() { _clearTree(root); }

    // overloaded operator:
    bst& operator=(const bst& rhs);

    //Name:isEmtpy
    //Description:checks the root to see if the tree is empty
    //Parameters: none
    //Return: true if empty, false otherwise
    bool isEmpty() const;

    //Name: insert
    //Description:  Inserts an item into a binary search tree. 
    //              duplicates are not allowed.
    //Parameters: newItem - IN - value to insert
    //Return:true if succeeds, false othewise
    bool insert(const T& newItem) { return _insert(root, newItem); }

    //Name: remove
    //Description: Deletes an item with a given search key 
    //Parameters: oldItem - IN - item to delete
    //Return:  true if found and false otherwise */
    bool remove(T oldItem) { return _remove(root, oldItem); }

    //Name: retrieve
    //Description: Retrieves an item with a given search key. Key value
    //             must be set in the item to be retrieved, if found it
    //             is filled in.
    //Paremeters: treeItem - IN/OUT - filled in if found
    //Return: true if found and false otherwise 
    bool retrieve(T& treeItem) const { return _retrieve(root, treeItem); }

    //Name: preorderTraverse
    //Description: Traverses a binary search tree in preorder, printing values out
    //              in the outlined form discussed in class**/
    //Paremters: none
    //Return: none
    void preorderTraverse() { _preorderTraversal(root, 1); }

    //Name: leafCount
    //Description: count the leaves in the tree
    //Parameters: none
    //Return: the number of leaves in the tree
    int leafCount() { return _leafCount(root); }
	
	//Name: nodeCount
    //Description: count the nodes in the tree
    //Parameters: none
    //Return: the number of nodes in the tree
	int nodeCount() { return _nodeCount(root); }

    //Name: height
    //Descriptions: calculates the height of the tree
    //Parameters: none
    //Returns the height of the tree as defined by the text
    int height() const { return _height(root); }

    //Name: clearTree
    //Description: Empties out all the nodes in the tree
    //Paremters: none
    //Return: none
    void clearTree() { _clearTree(root); }

private:
    /** Pointer to root of tree. */
    TreeNode<T> *root;

    //Name: _insert
    //Description:  Recursively inserts an item into a binary search tree. 
    //              duplicates are not allowed.
    //Parameters: treePtr - IN/OUT pointer of the root of the subtree
    //             newItem - IN - value to insert
    //Return:true if succeeds, false othewise
    bool _insert(TreeNode<T> *& treePtr, const T& newItem);

    //Name: _remove
    //Description: Recursively deletes an item with a given search key 
    //Parameters:  treePtr - IN/OUT pointer of the root of the subtree
    //             oldItem - IN - item to delete
    //Return:  true if found and false otherwise 
    bool _remove(TreeNode<T> *& treePtr, T oldItem);

    //Name: _deleteNode
    //Description: Deletes the item in pointed to by the nodePtr
    //Parameters: nodePtr - IN/OUT - pointer to node to be deleted
    //Return: none
    void _deleteNode(TreeNode<T> *& nodePtr);

    //Name: _removeLeftMostNode
    //Description: Uses recursion to remove the leftmost node in the right subtree
    //Parameters: ptr - IN/OUT - pointer to node
    //Return: the value at the leftmost node in the right subtree
    T _removeLeftMostNode(TreeNode<T> *& ptr);

    //Name: _retrieve
    //Description: Recursively retrieves an item with a given search key. Key value
    //   must be set in the item to be retrieved, if found it is filled in.
    //Paremeters: treeItem - IN/OUT - filled in if found
    //Return: true if found and false otherwise 
    bool _retrieve(TreeNode<T> *treePtr, T& treeItem) const;

    //Name: _copyTree
    //Description: Recursively copies the tree rooted at treePtr into a tree rooted at
    //             newTreePtr
    //Parameters:  treePtr - IN - Tree to copy from
    //             newTreePtr - OUT - Tree to copy to
    //Return: none
    void _copyTree(TreeNode<T> *treePtr, TreeNode<T> *& newTreePtr) const;


    //Name: _clearTree
    //Description: Recursively empties out all the nodes in the tree
    //Paremters: treeItem - IN/OUT - filled in if found
    //Return: none
    void _clearTree(TreeNode<T> *& treePtr);

    //Name: preorderTraverse
    //Description: Recursively traverses a binary search tree in preorder, printing values out
    //              in the outlined form discussed in class**/
    //Paremters: treeItem - IN/OUT - filled in if found
    //            level - IN - level of the current node at treePtr
    //Return: none
    void _preorderTraversal(TreeNode<T> *treePtr, int level);

    //Name: _leafCount
    //Description: Recursively counts the leaves in the tree
    //Parameters: treeItem - IN/OUT - filled in if found
    //Return: the number of leaves in the tree
    int _leafCount(TreeNode<T> *treePtr);
	
	//Name: _nodeCount
    //Description: Recursively counts the nodes in the tree
    //Parameters: treeItem - IN/OUT - filled in if found
    //Return: the number of nodes in the tree
    int _nodeCount(TreeNode<T> *treePtr);

    //Name: _height
    //Descriptions: Recursively calculates the height of the tree
    //Parameters: treeItem - IN/OUT - filled in if found
    //Returns the height of the tree as defined by the text
    int _height(TreeNode<T> *treePtr) const;

    //Name: _max
    //Description: Finds the max of two ints used in height**/
    //Parameters: one - IN - a number
    //            two - IN - a number
    //Return: the bigger of the two numbers
    int _max(int one, int two) const;

}; // end bst
// End of header file

#include "bst.cpp"

#endif
