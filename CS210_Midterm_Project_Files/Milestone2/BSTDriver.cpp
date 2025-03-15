#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "SchoolBST.h"

using namespace std;

//Prototypes
SchoolBST ReadFromCSV(string filename, bool hasHeader = false);
void promptUser();
void searchSchool();
void deleteSchool();
void displaySchool(int input);

SchoolBST bst;

int main()
{
    //load data, put into list, and display
    bst = ReadFromCSV("Illinois_Peoria_Schools.csv", true);

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
SchoolBST ReadFromCSV(string filename, bool hasHeader)
{
    ifstream file(filename);
    SchoolBST data;
    string line, word;
    fstream fout;

    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return data;
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
        data.insert(newSchool);
    }

    file.close();

    return data;
}

/// <summary>
/// prompts the user to search for, delete, or display the schools in the bst
/// </summary>
void promptUser()
{
    cout << "------------------------------------\n"
        "Select 1, 2, 3, or 4: \n" <<
        "1. Search for school by name\n" <<
        "2. Delete school by name\n" <<
        "3. Display List of Schools in PreOrder\n" <<
        "4. Display List of Schools in InOrder\n" <<
        "5. Display List of Schools in PostOrder\n" <<
        "6. Exit\n" <<
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
        displaySchool(1);
        break;
    case 4:
        cout << "You selected to display in InOrder." << endl;
        displaySchool(2);
        break;
    case 5:
        cout << "You selected to display in PostOrder." << endl;
        displaySchool(3);
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

    School inputSchool;// = bst.findByName(input);

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

    School inputSchool;// = bst.deleteByName(input);

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
/// displays schools in the list and then prompts the user again.
/// </summary>
void displaySchool(int input)
{ 
    cout << '\n';

    switch (input)
    {
    case 1:
        bst.displayPreOrder();
        break;
    case 2:
        bst.displayInOrder();
        break;
    case 3:
        bst.displayPostOrder();
        break;
    }

    promptUser();
}
