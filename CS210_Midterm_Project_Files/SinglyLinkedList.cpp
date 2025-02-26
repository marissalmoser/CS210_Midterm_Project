#pragma once

#include <iostream>
#include <string>
#include <algorithm>

#include "SinglyLinkedList.h"

using namespace std;

bool SinglyLinkedList::compareStrings(string string1, string string2)
{
    string lower1 = string1;
    string lower2 = string2;
    transform(lower1.begin(), lower1.end(), lower1.begin(), ::tolower);
    transform(lower2.begin(), lower2.end(), lower2.begin(), ::tolower);

    return lower1 == lower2;
}

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
    Node* foundSchool = nullptr;

    //check if empty
    if (head == nullptr)
    {
        return foundSchool->data;
    }

    Node* temp = head;

    //head is target or only thing in list
    if (compareStrings(head->data.name, name))
    {
        cout << "deleting head node" << endl;

        head = head->next;
        return temp->data;
    }

    //traverse to find node
    while (!compareStrings(temp->next->data.name, name) && temp->next != nullptr)
    {
        temp = temp->next;
    }

    //Deleting a node that doesn’t exist in the list
    if (temp->next == nullptr)
    {
        cout << "input value not found in list" << endl;
        return foundSchool->data;
    }

    cout << "deleting other node" << endl;
    foundSchool = temp->next;
    temp->next = temp->next->next;
    return foundSchool->data;
}

School SinglyLinkedList::findByName(string name)
{
    School foundSchool;

    if (head == nullptr)
    {
        //is empty
        return foundSchool;
    }

    //traverse to find node
    Node* temp = head;
    while (temp != nullptr)
    {
        if (compareStrings(temp->data.name, name))
        {
            foundSchool = temp->data;
            return foundSchool;
        }

        temp = temp->next;
    }
    //node not found
    return foundSchool;
}

void SinglyLinkedList::display()
{
    Node* temp = head;
    while (temp != nullptr)
    {
        cout << temp->data.name << ", " <<
            temp->data.address << ", " <<
            temp->data.city << ", " <<
            temp->data.state << ", " <<
            temp->data.county << '\n';
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}
