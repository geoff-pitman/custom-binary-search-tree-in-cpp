//File:     userInfo.h
//Author:   Professor Day
//Course:   CSC 237
//Date:     Spring 2015
//Purpose:  Records id and passwords for computer users

#include <iostream>
#include <fstream>
using namespace std;

#ifndef USERINFO_H
#define USERINFO_H

class userInfo
{
public:
    //sets and gets
    void setId(string anId);
    void setPassword(string passwd);
    string getId();
    string getPassword();

    //login is passed a password and checks for a match on the instance
    //Parameters:  string passwd - INPUT
    //Return: true if passwd matches, false otherwise
    bool login(string passwd);

    //overloads for relational operators: compare by id
    bool operator==(const userInfo &info) const;
    bool operator<(const userInfo &info) const;
    bool operator>(const userInfo &info) const;
    bool operator!=(const userInfo &info) const;
    bool operator<=(const userInfo &info)const;
    bool operator>=(const userInfo &info)const;

private:
    string id;
    string password;
};


//input stream operator expects the id and password, no spaces on a line
ostream &operator<<(ostream &out, userInfo info);
istream &operator>>(istream &inn, userInfo &info);
#endif
