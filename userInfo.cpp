#include <iostream>
#include <string>
#include "userInfo.h"
using namespace std;

//sets and gets
void userInfo::setId(string anId) { id = anId; }
void userInfo::setPassword(string passwd) { password = passwd; }
string userInfo::getId() { return id; }
string userInfo::getPassword() { return password; }

//login is passed a password and checks for a match on the instance
//Parameters:  string passwd - INPUT
//Return: true if passwd matches, false otherwise
bool userInfo::login(string passwd) { return password == passwd; }

//overloads for relational operators: compare by id
bool userInfo::operator==(const userInfo &info) const { return id == info.id; }
bool userInfo::operator<(const userInfo &info) const { return id < info.id; }
bool userInfo::operator>(const userInfo &info)  const { return id > info.id; }
bool userInfo::operator!=(const userInfo &info)const { return id != info.id; }
bool userInfo::operator<=(const userInfo &info) const { return id <= info.id; }
bool userInfo::operator>=(const userInfo &info) const { return id >= info.id; }

ostream &operator<<(ostream &out, userInfo user)
{
    out << user.getId() << " " << user.getPassword();

    return out;
}

istream &operator>>(istream &inn, userInfo &user)
{
    string idd, passwd;
    inn >> idd >> passwd;
    user.setId(idd);
    user.setPassword(passwd);
    return inn;
}
