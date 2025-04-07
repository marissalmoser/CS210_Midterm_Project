#pragma once

#include <iostream>
#include <string>
#include <algorithm>

#include "SchoolList.h"

using namespace std;

/// <summary>
/// compares 2 strings, case in-sensitive. Returns true if there is a match.
/// </summary>
/// <returns></returns>
bool SchoolList::compareStrings(string string1, string string2)
{
    string lower1 = string1;
    string lower2 = string2;
    transform(lower1.begin(), lower1.end(), lower1.begin(), ::tolower);
    transform(lower2.begin(), lower2.end(), lower2.begin(), ::tolower);

    return lower1 == lower2;
}

/// <summary>
/// inserts a new school at the beginning of the list.
/// </summary>
/// <param name="data">School to add</param>
void SchoolList::insertFirst(School data)
{
    Node* newNode = new Node(data);
    if (head != nullptr)
    {
        newNode->next = head;
    }
    head = newNode;
}

/// <summary>
/// inserts a new school at the end of the list.
/// </summary>
/// <param name="data">School to add</param>
void SchoolList::insertLast(School data)
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

/// <summary>
/// deletes a school in the list from the parameter
/// </summary>
/// <param name="name">of the school to delete</param>
/// <returns></returns>
School SchoolList::deleteByName(string name)
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

    foundSchool = temp->next;
    temp->next = temp->next->next;
    return foundSchool->data;
}

/// <summary>
/// finds a school in the list from the parameter
/// </summary>
/// <param name="name">of the school to find</param>
/// <returns></returns>
School SchoolList::findByName(string name)
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

/// <summary>
/// displays every school in the list
/// </summary>
void SchoolList::display()
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
    cout << "end of list" << endl;
}
