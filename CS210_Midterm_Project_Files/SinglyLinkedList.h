#pragma once

#include "School.cpp"

struct Node
{
    School data;
    Node* next;
    Node(School val) : data(val), next(nullptr) {}
};

class SinglyLinkedList
{
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    void insertFirst(School data);
    void insertLast(School data);
    School deleteByName(std::string name);
    School findByName(std::string name);
    void display();

};
