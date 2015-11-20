
#include <iostream>
#include <fstream>
#include <string>
#include <istream>
#include "bst.h"
#include "userInfo.h"

using namespace std;

int menu();
void initUsers(bst<userInfo> &users);
void login(bst<userInfo> &users);
void display(bst<userInfo> users);
void addUser(bst<userInfo> &users);
void removeUser(bst<userInfo> &users);

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


int menu()
{
    int choice;
    cout << endl;
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


void initUsers(bst<userInfo> &users)
{
    ifstream inFile;
    string fileName;
    cout << "\n\n\nEnter file name: ";
    cin >> fileName;
    inFile.open(fileName.c_str());
    if (!inFile.is_open())
    {
        cout << "ERROR: Unable to open file." << endl;
    }
    else
    {
        cout << "File opened successfully." << endl;
    }
    userInfo* add = new userInfo();
    string info = "";
    while (inFile >> info)
    {
        
        add->setId(info);
        inFile >> info;
        add->setPassword(info);
        users.insert(*add);
    }
    if (users.isEmpty())
    {
        cout << "No data could be retrieved\n";
    }
    else
    {
        cout << "Data retrived successfully.\n";
    }
}


void display(bst<userInfo> users)
{
    users.preorderTraverse();
    cout << "\nLeaves: " << users.leafCount() << endl;
    cout << "Height: " << users.height() << endl;
}


void removeUser(bst<userInfo> &users)
{
    string id, pass;
    userInfo* person = new userInfo();
    cout << "Enter ID of user you wish to remove: " << endl;
    cin >> id;
    cout << "Enter Password of user you wish to remove: " << endl;
    cin >> pass;
    person->setId(id);
    cout << "fine" << endl;
    person->setPassword(pass); 
    if (users.remove(*person))
    {
        cout << "User was removed successfully" << endl;
    }
    else
       cout << "ERROR: Unable to remove user, or the user did not exist" << endl;
}

void login(bst<userInfo> &info)
{
	string id, pass;
	userInfo *data = new userInfo();
	
	cout << "Enter user Id: ";
	cin >> id;
	cout << "Enter password: ";
	cin >> pass;
	data -> setId(id);
	data -> setPassword(pass);
	
	if(info.retrieve(*data) == true)
	{
		if(data->login(pass) == true)
		{
			cout << "Login Successful" << endl;
		}
		if(data->login(pass) == false)
		{
			cout << "Login Failed" << endl;
		}
	}
	else
		cout << " Login Failed" << endl;
}

void addUser(bst<userInfo> &info)
{
	string id, pass;
	userInfo *data = new userInfo();
	
	cout << "Enter user Id: ";
	cin >> id;
	cout << "Enter password: ";
	cin >> pass;
	
	data->setId(id);
	data->setPassword(pass);
	info.insert(*data);
}
