#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "SchoolHashTable.h"

using namespace std;

//Prototypes
void ReadFromCSV(string filename, bool hasHeader = false);
void promptUser();
void searchSchool();
void deleteSchool();
void displaySchool();

SchoolHashTable ht(150);

int main()
{
    //load data, put into list, and display
    ReadFromCSV("Illinois_Peoria_Schools.csv", true);

    //prompt user to edit data
    promptUser();
}

/// <summary>
/// Reads a file of schools from a csv and saves the data to a linked list.
/// </summary>
/// <param name="filename">the name of the file to open and read</param>
/// <param name="hasHeader">will determine whether or not to skip the first
/// line when reading</param>
/// <returns></returns>
void ReadFromCSV(string filename, bool hasHeader)
{
    ifstream file(filename);
    string line, word;
    fstream fout;

    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }

    //check if first line should be skipped
    if (hasHeader)
    {
        getline(file, line);
    }

    //read file and save data
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
        ht.insert(newSchool);
    }

    file.close();
}

/// <summary>
/// prompts the user to search for, delete, or display the schools in the ht
/// </summary>
void promptUser()
{
    cout << "------------------------------------\n"
        "Select 1, 2, 3, or 4: \n" <<
        "1. Search for school by name\n" <<
        "2. Delete school by name\n" <<
        "3. Display Table of Schools\n" <<
        "4. Exit\n" <<
        "------------------------------------\n" << endl;

    int input;
    cin >> input;

    switch (input)
    {
    case 1:
        cout << "You selected to search." << endl;
        searchSchool();
        break;
    case 2:
        cout << "You selected to delete." << endl;
        deleteSchool();
        break;
    case 3:
        cout << "You selected to display in PreOrder." << endl;
        displaySchool();
        break;
    default:
        cout << "You selected to exit.\n" << endl;
        break;
    }
}

/// <summary>
/// locates a school based on user input. prints that school's data and then prompts
/// the user again.
/// </summary>
void searchSchool()
{
    cout << "Input name of school to find:\n";
    string input;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, input);

    School inputSchool = ht.findByName(input);

    if (inputSchool.name == "")
    {
        cout << "\nInput school is not found\n" << endl;
    }
    else
    {
        cout << "\nThe school by the name of " << input << " has been found. Here are it's details: \n" <<
            inputSchool.name << ", " <<
            inputSchool.address << ", " <<
            inputSchool.city << ", " <<
            inputSchool.state << ", " <<
            inputSchool.county << "\n" << endl;
    }

    promptUser();
}

/// <summary>
/// deletes a school based on user input. prints that school's data and then prompts
/// the user again.
/// </summary>
void deleteSchool()
{
    cout << "Input name of school to delete:\n";
    string input;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, input);

    School inputSchool = ht.deleteByName(input);

    if (inputSchool.name == "")
    {
        cout << "\nInput school is not found\n" << endl;
    }
    else
    {
        cout << "\nThe school by the name of " << input << " has been found and deleted. Here are it's details: \n" <<
            inputSchool.name << ", " <<
            inputSchool.address << ", " <<
            inputSchool.city << ", " <<
            inputSchool.state << ", " <<
            inputSchool.county << "\n" << endl;
    }

    promptUser();
}

/// <summary>
/// displays schools in the ht and then prompts the user again.
/// </summary>
void displaySchool()
{ 
    cout << '\n';

    ht.display();

    promptUser();
}
