#ifndef ADDEMPLOYEE_HPP
#define ADDEMPLOYEE_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct employee
{
    string name;
    string email;
    string birthday;
};

int addAnEmployee(employee array[], string name, string birthday, string emailid, int count);

#endif
