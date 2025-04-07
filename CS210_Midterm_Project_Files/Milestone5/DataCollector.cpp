#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "SchoolList.h"
#include "SchoolBST.h"
#include "SchoolHashTable.h"
#include "timer.h"

using namespace std;

vector<School> peoriaSchools(129);
vector<School> ilSchools(7423);
vector<School> usaSchools(164463);

SchoolList Plist;
SchoolList ILlist;
SchoolList USAlist;
SchoolBST Pbst;
SchoolBST ILbst;
SchoolBST USAbst;
SchoolHashTable Pht(100);
SchoolHashTable ILht(100);
SchoolHashTable USAht(100);

double timeCounter = 0;

vector<School> ReadDataFromCSV(string filename, bool hasHeader)
{
    ifstream file(filename);
    vector<School> data;
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

        if (row.size() > 4)
        {
            newSchool.county = row[4];
        }

        //add school to data
        data.push_back(newSchool);
    }

    file.close();

    return data;
}

void InsertPlist(vector<School> vec)
{
    //zint gap = vec.size() / 10;
    for (int i = 0; i < vec.size(); i += 1)
    {
        Plist.insertLast(vec[i]);
    }
}
void InsertILlist(vector<School> vec)
{
    //zint gap = vec.size() / 10;
    for (int i = 0; i < vec.size(); i += 1)
    {
        ILlist.insertLast(vec[i]);
    }
}
void InsertUSAlist(vector<School> vec)
{
    //zint gap = vec.size() / 10;
    for (int i = 0; i < vec.size(); i += 1)
    {
        USAlist.insertLast(vec[i]);
    }
}

void InsertPbst(vector<School> vec)
{
    //zint gap = vec.size() / 10;
    for (int i = 0; i < vec.size(); i += 1)
    {
        Pbst.insert(vec[i]);
    }
}
void InsertILbst(vector<School> vec)
{
    //zint gap = vec.size() / 10;
    for (int i = 0; i < vec.size(); i += 1)
    {
        ILbst.insert(vec[i]);
    }
}
void InsertUSAbst(vector<School> vec)
{
    //zint gap = vec.size() / 10;
    for (int i = 0; i < vec.size(); i += 1)
    {
        USAbst.insert(vec[i]);
    }
}

void InsertPht(vector<School> vec)
{
    //zint gap = vec.size() / 10;
    for (int i = 0; i < vec.size(); i += 1)
    {
        Pht.insert(vec[i]);
    }
}
void InsertILht(vector<School> vec)
{
    //zint gap = vec.size() / 10;
    for (int i = 0; i < vec.size(); i += 1)
    {
        ILht.insert(vec[i]);
    }
}
void InsertUSAht(vector<School> vec)
{
    //zint gap = vec.size() / 10;
    for (int i = 0; i < vec.size(); i += 1)
    {
        USAht.insert(vec[i]);
    }
}

void SearchPlist(vector<School> vec)
{
    int gap = vec.size() / 30;
    for (int i = 0; i < vec.size(); i += gap)
    {
        Plist.findByName(vec[i].name);
    }

}
void SearchILlist(vector<School> vec)
{
    int gap = vec.size() / 30;
    for (int i = 0; i < vec.size(); i += gap)
    {
        ILlist.findByName(vec[i].name);
    }

}
void SearchUSAlist(vector<School> vec)
{
    int gap = vec.size() / 30;
    for (int i = 0; i < vec.size(); i += gap)
    {
        USAlist.findByName(vec[i].name);
    }

}

void SearchPbst(vector<School> vec)
{
    int gap = vec.size() / 30;
    for (int i = 0; i < vec.size(); i += gap)
    {
        Pbst.findByName(vec[i].name);
    }
}
void SearchILbst(vector<School> vec)
{
    int gap = vec.size() / 30;
    for (int i = 0; i < vec.size(); i += gap)
    {
        ILbst.findByName(vec[i].name);
    }
}
void SearchUSAbst(vector<School> vec)
{
    int gap = vec.size() / 30;
    for (int i = 0; i < vec.size(); i += gap)
    {
        USAbst.findByName(vec[i].name);
    }
}

void SearchPht(vector<School> vec)
{
    int gap = vec.size() / 30;
    for (int i = 0; i < vec.size(); i += gap)
    {
        Pht.findByName(vec[i].name);
    }
}
void SearchILht(vector<School> vec)
{
    int gap = vec.size() / 30;
    for (int i = 0; i < vec.size(); i += gap)
    {
        ILht.findByName(vec[i].name);
    }
}
void SearchUSAht(vector<School> vec)
{
    int gap = vec.size() / 30;
    for (int i = 0; i < vec.size(); i += gap)
    {
        USAht.findByName(vec[i].name);
    }
}


void DeletePlist(vector<School> vec)
{
    int gap = vec.size() / 30;
    for (int i = 0; i < vec.size(); i += gap)
    {
        Plist.deleteByName(vec[i].name);
    }

}
void DeleteILlist(vector<School> vec)
{
    int gap = vec.size() / 30;
    for (int i = 0; i < vec.size(); i += gap)
    {
        ILlist.deleteByName(vec[i].name);
    }

}
void DeleteUSAlist(vector<School> vec)
{
    int gap = vec.size() / 30;
    for (int i = 0; i < vec.size(); i += gap)
    {
        USAlist.deleteByName(vec[i].name);
    }

}

void DeletePbst(vector<School> vec)
{
    int gap = vec.size() / 30;
    for (int i = 0; i < vec.size(); i += gap)
    {
        Pbst.deleteByName(vec[i].name);
    }
}
void DeleteILbst(vector<School> vec)
{
    int gap = vec.size() / 30;
    for (int i = 0; i < vec.size(); i += gap)
    {
        ILbst.deleteByName(vec[i].name);
    }
}
void DeleteUSAbst(vector<School> vec)
{
    int gap = vec.size() / 30;
    for (int i = 0; i < vec.size(); i += gap)
    {
        USAbst.deleteByName(vec[i].name);
    }
}

void DeletePht(vector<School> vec)
{
    int gap = vec.size() / 30;
    for (int i = 0; i < vec.size(); i += gap)
    {
        Pht.deleteByName(vec[i].name);
    }
}
void DeleteILht(vector<School> vec)
{
    int gap = vec.size() / 30;
    for (int i = 0; i < vec.size(); i += gap)
    {
        ILht.deleteByName(vec[i].name);
    }
}
void DeleteUSAht(vector<School> vec)
{
    int gap = vec.size() / 30;
    for (int i = 0; i < vec.size(); i += gap)
    {
        USAht.deleteByName(vec[i].name);
    }
}


int main()
{
    //read data set into vectors and debug.
    peoriaSchools = ReadDataFromCSV("Illinois_Peoria_Schools.csv", true);
    cout << "Peoria Schools Read: " << peoriaSchools.size() << endl;
    ilSchools = ReadDataFromCSV("Illinois_Schools.csv", true);
    cout << "IL Schools Read: " << ilSchools.size() << endl;
    usaSchools = ReadDataFromCSV("USA_Schools.csv", true);
    cout << "USA Schools Read: " << usaSchools.size() << endl;

    //time insert and debug list
    timeCounter = Timer::time_function([&]() { InsertPlist(peoriaSchools);}) / 127;
    cout << "Peoria Schools List Insert: " << timeCounter << endl;
    timeCounter = Timer::time_function([&]() { InsertILlist(ilSchools);}) / 7423;
    cout << "IL Schools List Insert: " << timeCounter << endl;
    timeCounter = Timer::time_function([&]() { InsertUSAlist(usaSchools);}) / 164463;
    cout << "USA Schools List Insert: " << timeCounter << endl;

    //time insert and debug bst
    timeCounter = Timer::time_function([&]() { InsertPbst(peoriaSchools);}) / 127;
    cout << "Peoria Schools BST Insert: " << timeCounter << endl;
    timeCounter = Timer::time_function([&]() { InsertILbst(ilSchools);}) / 7423;
    cout << "IL Schools BST Insert: " << timeCounter << endl;
    timeCounter = Timer::time_function([&]() { InsertUSAbst(usaSchools);}) / 164463;
    cout << "USA Schools BST Insert: " << timeCounter << endl;

    //time insert and debug hash table
    timeCounter = Timer::time_function([&]() { InsertPht(peoriaSchools);}) / 127;
    cout << "Peoria Schools hash table Insert: " << timeCounter << endl;
    timeCounter = Timer::time_function([&]() { InsertILht(ilSchools);}) / 7423;
    cout << "IL Schools hash table Insert: " << timeCounter << endl;
    timeCounter = Timer::time_function([&]() { InsertUSAht(usaSchools);}) / 164463;
    cout << "USA Schools hash table Insert: " << timeCounter << endl;



    //average time to search for an element in list
    timeCounter = Timer::time_function([&]() { SearchPlist(peoriaSchools);}) / 30;
    cout << "Peoria Schools List Search: " << timeCounter << endl;
    timeCounter = Timer::time_function([&]() { SearchILlist(ilSchools);}) / 30;
    cout << "IL Schools List Search: " << timeCounter << endl;
    timeCounter = Timer::time_function([&]() { SearchUSAlist(usaSchools);}) / 30;
    cout << "USA Schools List Search: " << timeCounter << endl;

    //average time to search for an element in bst
    timeCounter = Timer::time_function([&]() { SearchPbst(peoriaSchools);}) / 30;
    cout << "Peoria Schools BST Search: " << timeCounter << endl;
    timeCounter = Timer::time_function([&]() { SearchILbst(ilSchools);}) / 30;
    cout << "IL Schools BST Search: " << timeCounter << endl;
    timeCounter = Timer::time_function([&]() { SearchUSAbst(usaSchools);}) / 30;
    cout << "USA Schools BST Search: " << timeCounter << endl;

    //average time to search for an element in ht
    timeCounter = Timer::time_function([&]() { SearchPht(peoriaSchools);}) / 30;
    cout << "Peoria Schools Hash Table Search: " << timeCounter << endl;
    timeCounter = Timer::time_function([&]() { SearchILht(ilSchools);}) / 30;
    cout << "IL Schools Hash Table Search: " << timeCounter << endl;
    timeCounter = Timer::time_function([&]() { SearchUSAht(usaSchools);}) / 30;
    cout << "USA Schools Hash Table Search: " << timeCounter << endl;



    //average time to delete an element in list
    timeCounter = Timer::time_function([&]() { DeletePlist(peoriaSchools);}) / 30;
    cout << "Peoria Schools List Delete: " << timeCounter << endl;
    timeCounter = Timer::time_function([&]() { DeleteILlist(ilSchools);}) / 30;
    cout << "IL Schools List Delete: " << timeCounter << endl;
    timeCounter = Timer::time_function([&]() { DeleteUSAlist(usaSchools);}) / 30;
    cout << "USA Schools List Delete: " << timeCounter << endl;

    //average time to delete an element in bst
    timeCounter = Timer::time_function([&]() { DeletePbst(peoriaSchools);}) / 30;
    cout << "Peoria Schools BST Delete: " << timeCounter << endl;
    timeCounter = Timer::time_function([&]() { DeleteILbst(ilSchools);}) / 30;
    cout << "IL Schools BST Delete: " << timeCounter << endl;
    timeCounter = Timer::time_function([&]() { DeleteUSAbst(usaSchools);}) / 30;
    cout << "USA Schools BST Delete: " << timeCounter << endl;

    //average time to delete an element in ht
    timeCounter = Timer::time_function([&]() { DeletePht(peoriaSchools);}) / 30;
    cout << "Peoria Schools Hash Table Delete: " << timeCounter << endl;
    timeCounter = Timer::time_function([&]() { DeleteILht(ilSchools);}) / 30;
    cout << "IL Schools Hash Table Delete: " << timeCounter << endl;
    timeCounter = Timer::time_function([&]() { DeleteUSAht(usaSchools);}) / 30;
    cout << "USA Schools Hash Table Delete: " << timeCounter << endl;
}




