#pragma once

#include "SchoolHashTable.h"
#include <iostream>

using namespace std;

void SchoolHashTable::insert(School school)
{
    table[hashFunction(school.name)] = school;

    cout << school.name + ", " + school.address + ", " +
        school.city + ", " + school.state + ", " +
        school.county << "\n";
}

School SchoolHashTable::deleteByName(std::string name)
{
    School toDelete = table[hashFunction(name)];
    table[hashFunction(name)] = School();
	return toDelete;
}

School SchoolHashTable::findByName(std::string name)
{
    School toFind = table[hashFunction(name)];
    if (toFind.name == name)
        return toFind;
    else
        return School();
}

void SchoolHashTable::display()
{
    for (School school : table)
    {
        cout << school.name + ", " +  school.address + ", " +
            school.city + ", " + school.state + ", " +
            school.county << "\n";
    }
    cout << endl;
}

int SchoolHashTable::hashFunction(std::string key)
{
    int hash = 0;
    for (char ch : key)
    {
        hash += ch;
    }
    return hash % tableSize;
}
