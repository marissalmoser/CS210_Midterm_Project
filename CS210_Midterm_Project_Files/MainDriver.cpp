#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "SinglyLinkedList.h"

using namespace std;

SinglyLinkedList ReadFromCSV(string filename, bool hasHeader = false);

int main()
{
    //load data and put into list and display
    SinglyLinkedList list = ReadFromCSV("Illinois_Peoria_Schools.csv", true);

}

SinglyLinkedList ReadFromCSV(string filename, bool hasHeader)
{
    ifstream file(filename);
    SinglyLinkedList data;
    string line, word;
    fstream fout;

    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return data;
    }

    //chech if skip first line
    if (hasHeader)
    {
        getline(file, line);
    }

    while (getline(file, line)) 
    {
        stringstream ss(line);

        //make new school and vector to hold its values
        School newSchool;
        vector<string> row;

        //read line from file
        while (getline(ss, word, ','))
        {
            row.push_back(word);
        }

        //assign fields to school
        newSchool.name = row[0];
        newSchool.address = row[1];
        newSchool.city = row[2];
        newSchool.state = row[3];
        newSchool.county = row[4];

        //add school to data
        data.insertLast(newSchool);
    }

    file.close();
    data.display();

    return data;
}