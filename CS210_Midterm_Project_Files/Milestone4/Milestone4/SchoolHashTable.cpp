#pragma once

#include "SchoolHashTable.h"
#include <iostream>

using namespace std;

void SchoolHashTable::insert(School school)
{
}

School SchoolHashTable::deleteByName(std::string name)
{
	return School();
}

School SchoolHashTable::findByName(std::string name)
{
	return School();
}

void SchoolHashTable::display()
{
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
