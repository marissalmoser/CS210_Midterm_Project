#pragma once

#include <iostream>

#include "SinglyLinkedList.h"

using namespace std;

void SinglyLinkedList::insertFirst(School data)
{
    Node* newNode = new Node(data);
    if (head != nullptr)
    {
        newNode->next = head;
    }
    head = newNode;
}

void SinglyLinkedList::insertLast(School data)
{
    Node* newNode = new Node(data);
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node* temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

School SinglyLinkedList::deleteByName(string name)
{
    if (head == nullptr)
    {
        //is empty
        School nullSchool;
        return nullSchool;
    }

    //traverse to find node
    Node* temp = head;
    Node* tempPrev = nullptr;
    while (temp != nullptr)
    {
        if (temp->data.name == name)
        {
            tempPrev->next = temp->next;
            return temp->data;
        }

        tempPrev = temp;
        temp = temp->next;
    }

    //node not found
    School nullSchool;
    return nullSchool;
}

School SinglyLinkedList::findByName(string name)
{
    if (head == nullptr)
    {
        //is empty
        School nullSchool;
        return nullSchool;
    }

    //traverse to find node
    Node* temp = head;
    while (temp != nullptr)
    {
        if (temp->data.name == name)
        {
            return temp->data;
        }

        temp = temp->next;
    }

    //node not found
    School nullSchool;
    return nullSchool;
}

void SinglyLinkedList::display()
{
    Node* temp = head;
    while (temp != nullptr)
    {
        cout << temp->data.name << 
            temp->data.address << ", " <<
            temp->data.city << ", " <<
            temp->data.state << ", " <<
            temp->data.county << '\n';
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

int main()
{
    SinglyLinkedList list;

    School* Washington = new School;
    Washington->name = "Washington";
    Washington->address = "1506. W Kingsway Dr.";

    list.insertFirst(*Washington);

    list.display();
}
