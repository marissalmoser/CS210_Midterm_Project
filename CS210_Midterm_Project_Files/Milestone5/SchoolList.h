#pragma once

#include "School.cpp"

struct Node
{
    School data;
    Node* next;
    Node(School val) : data(val), next(nullptr) {}
};

class SchoolList
{
    Node* head;
    bool compareStrings(std::string string1, std::string string2);

public:
    SchoolList() : head(nullptr) {}

    void insertFirst(School data);
    void insertLast(School data);
    School deleteByName(std::string name);
    School findByName(std::string name);
    void display();
};
