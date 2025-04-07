#pragma once

#include "SchoolHashTable.h"
#include <iostream>
#include <algorithm>

using namespace std;

void SchoolHashTable::insert(School school)
{
    //add school to the vector at the hash index
    table[hashFunction(school.name)].push_back(school);
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
    cout << "Hash:" << '\t' << "Chain:" << '\t' <<
        "School Data:" << "\n";

    for (int i = 0; i < table.size(); ++i)
    {
        for (int j = 0; j < table[i].size(); ++j)
        {
            School school = table[i][j];

            cout << i << '\t' << j << '\t' << 
                school.name + ", " + school.address + ", " + school.city + ", " +
                school.state + ", " + school.county << "\n";
        }
    }

    cout << endl;
}

/// <summary>
/// Modulo Hashing Function to Calculate Index
/// </summary>
/// <param name="key"></param>
/// <returns></returns>
int SchoolHashTable::hashFunction(std::string key) const
{
    int hash = 0;
    for (char ch : key)
    {
        hash += ch;
    }

    return hash % tableSize;
}
