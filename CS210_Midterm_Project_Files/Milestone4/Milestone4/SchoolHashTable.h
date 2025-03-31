#pragma once

#include <vector>
#include <string>
#include "School.cpp"

class SchoolHashTable
{
public:
	SchoolHashTable(int size) : tableSize(size), table(size) {}
	void insert(School school);
	School deleteByName(std::string name);
	School findByName(std::string name);
	void display();

private:
	std::vector<School> table;
	int tableSize;
	int hashFunction(std::string key);
};

