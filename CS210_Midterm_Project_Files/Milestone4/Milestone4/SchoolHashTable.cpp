#pragma once

#include "SchoolHashTable.h"
#include <iostream>
#include <algorithm>

using namespace std;

void SchoolHashTable::insert(School school)
{
    //add school to the vector at the hash index
    table[hashFunction(school.name)].push_back(school);

    cout << school.name + ", " + school.address + ", " +
        school.city + ", " + school.state + ", " +
        school.county << "\n";
}

School SchoolHashTable::deleteByName(std::string name)
{
    transform(name.begin(), name.end(), name.begin(), ::toupper);
    School toDelete;
    int hash = hashFunction(name);

    //loop thru Schools in chain
    for (int i = 0; i < table[hash].size() ; i++)
    {
        if (table[hash][i].name == name)
        {
            toDelete = table[hash][i];
            table[hash].erase(table[hash].begin() + i);
        }
    }

	return toDelete;
}

School SchoolHashTable::findByName(std::string name)
{
    transform(name.begin(), name.end(), name.begin(), ::toupper);
    School toFind;
    int hash = hashFunction(name);

    //loop thru Schools in chain
    for (int i = 0; i < table[hash].size() ; i++)
    {
        if (table[hash][i].name == name)
        {
            toFind = table[hash][i];
        }
    }

    return toFind;
}

void SchoolHashTable::display()
{
    for (vector<School> vec : table)
    {
        for (School school : vec)
        {
            cout << school.name + ", " + school.address + ", " +
                school.city + ", " + school.state + ", " +
                school.county << "\n";
        }
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
    cout << hash % tableSize << endl;
    return hash % tableSize;
}
