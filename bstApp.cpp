//File:   bstApp.cpp
//Author: Geoffrey Pitman
//Course: CSC 237
//Date:   April 30, 2015
//Purpose: To test the functionality of our bst class with an application 
//        program that will keep track of userInfo in a binary search tree.
#include <iostream>
#include <fstream>
#include <string>
#include <istream>
#include "bst.h"
#include "userInfo.h"

using namespace std;


//Name: menu
//Description: menu prompt
//Paremeters: none
//Return: the user's choice as an integer
int menu();

//Name: initUsers
//Description: fill in a bst with data retrieved from a file
//Paremeters: users - IN/OUT - the bst
//Return: none
void initUsers(bst<userInfo> &users);


//Name: login
//Description: login a user
//Paremeters: users - IN - the bst
//Return: none
void login(const bst<userInfo>& users);


//Name: addUser
//Description: add a user
//Paremeters: users - IN/OUT - the bst
//Return: none
void addUser(bst<userInfo> &users);

//Name: removeUser
//Description: remove a user
//Paremeters: users - IN/OUT - the bst
//Return: none
void removeUser(bst<userInfo> &users);

//Name: display
//Description: RNL preorder traversal printout of bst
//Paremeters: users - IN - the bst
//Return: none
void display(bst<userInfo> users);

int main()
{
    int option;
    bst<userInfo> * users = new bst<userInfo>();

    while ((option = menu()) != 6)
    {
        switch (option)
        {
            case 1: initUsers(*users); break;
            case 2: login(*users); break;
            case 3: addUser(*users); break;
            case 4: removeUser(*users); break;
            case 5: display(*users); break;
        }
    }
    return 0;
}

//Description: menu prompt
int menu()
{
    int choice;
    cout << endl << endl;
    cout << "1. Get initial users from file" << endl;
    cout << "2. Login" << endl;
    cout << "3. Add a user" << endl;
    cout << "4. Remove a user" << endl;
    cout << "5. Display" << endl;
    cout << "6. Quit" << endl;
    cout << "Choice: ";
    cin >> choice;
    return choice;
}

//Description: fill in a bst with data retrieved from a file
void initUsers(bst<userInfo> &users)
{
	// get file
    ifstream inFile;
    string fileName;
    cout << "\nEnter file name: ";
    cin >> fileName;
    inFile.open(fileName.c_str());
    if (!inFile.is_open())
    {
        cout << "\nERROR: Unable to open file." << endl;
    }
    else
    {
        cout << "\nFile opened successfully." << endl;
    }
	
	// get data
	int pre = users.nodeCount();
	int error = 0;
	int count = 0;
    userInfo* person = new userInfo();
    string id, pass;
    while (inFile >> id)
    { 
		inFile >> pass;
        count++;
        
    	person->setId(id);
        person->setPassword(pass);
        
		if(!(users.insert(*person)))
		{
			cout << "\nERROR: ID '" + id + "' unavailable.";
			error++;
		}
    }
	
	// check after-state of bst
    if (pre == users.nodeCount())
        cout << "\nNo data retrieved";
    else if (error == 0)
        cout << "\nData retrieved successfully.";
    else
		cout << "\nUnable to initialize " << error << 
	            " of " << count << " total items.";
		
}

//Description: login a user
void login(const bst<userInfo>& users)
{
	string id, pass;
	userInfo *person = new userInfo();
	
	cout << "\nEnter user ID: ";
	cin >> id;
	cout << "Enter password: ";
	cin >> pass;
	
	person->setId(id);
	person->setPassword(pass);
	
	if(users.retrieve(*person))
	{
		if(person->login(pass))
			cout << "\nLogin successful.";
		else
			cout << "\nERROR: Incorrect password.";	
	}
	else
		cout << "\nERROR: Unable to locate ID.";
}

//Description: add a user
void addUser(bst<userInfo> &users)
{
	string id, pass;
	userInfo *person = new userInfo();
	
	cout << "\nEnter user ID: ";
	cin >> id;
	cout << "Enter password: ";
	cin >> pass;
	
	person->setId(id);
	person->setPassword(pass);
	
    if (users.insert(*person))
        cout << "\nUser added successfully.";
    else
       cout << "\nERROR: User ID unavailable.";
	
	
}

//Description: remove a user
void removeUser(bst<userInfo> &users)
{
    string id, pass;
    userInfo* person = new userInfo();
	
    cout << "\nEnter ID of user to remove: ";
    cin >> id;

    person->setId(id);
    if (users.remove(*person))
        cout << "\nUser removed successfully.";
    else
       cout << "\nERROR: Unable to locate ID.";
}

//Description: RNL preorder traversal printout of bst
void display(bst<userInfo> users)
{
	cout << endl;
    users.preorderTraverse();
	cout << "\nNodes: " << users.nodeCount();
    cout << "\nLeaves: " << users.leafCount();
    cout << "\nHeight: " << users.height();
}
