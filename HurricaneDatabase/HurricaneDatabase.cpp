/*
 * File: HuricaneDatabase.cpp
 * Code: Stores the csv data of hurricanes within a linked list
 * Name: Nicholas Campola
 * Date: 11/9/2018
 * CPSC 340
 */

#ifndef HurricaneData_cpp
#define HurricaneData_cpp
#include <vector>
#include <iostream>
#include <string>
#include "HurricaneEntry.h"
#include "linked_list.h"
#include "HurricaneDataBase.h"
using namespace std;
    
HurricaneDataBase::HurricaneDataBase(string filename){
    ifstream file;
    file.open(filename);
    string temp;
    if(!(file.is_open())){
        exit(0);
    }
    while(!(file.eof())){
        getline(file, temp);
        HurricaneEntry line(temp);
        database.InsertInOrder(line);
    }
}
void HurricaneDataBase::PrintStormsByYear(){
    HurricaneEntry h;
    h.setKey(YEAR);
    if(database.Search(h)){
        database.PrintAll();
    }
    else{
        linked_list<HurricaneEntry> tempList;
        HurricaneEntry temp;
        while(!(database.IsEmpty())){
            database.RemoveRear(temp);
            temp.setKey(YEAR);
            tempList.InsertInOrder(temp);
        }
        database = tempList;
        database.PrintAll();
    }
    
}
void HurricaneDataBase::SortsPrintsByNumberofTropicalStorms(){
    HurricaneEntry h;
    h.setKey(STORM);
    if(database.Search(h)){
        database.PrintAll();
    }
    else{
        linked_list<HurricaneEntry> tempList;
        HurricaneEntry temp;
        while(!(database.IsEmpty())){
            database.RemoveRear(temp);
            temp.setKey(STORM);
            tempList.InsertInOrder(temp);
        }
        database = tempList;
        database.PrintAll();
    }
}

void HurricaneDataBase::SortsPrintsByNumberofHurricanes(){
    HurricaneEntry h;
    h.setKey(HURRICANE);
    if(database.Search(h)){
        database.PrintAll();
    }
    else{
        linked_list<HurricaneEntry> tempList;
        HurricaneEntry temp;
        while(!(database.IsEmpty())){
            database.RemoveRear(temp);
            temp.setKey(HURRICANE);
            tempList.InsertInOrder(temp);
        }
        database = tempList;
        database.PrintAll();
    }
}

void HurricaneDataBase::SortsPrintsByNumberofMajorStorms(){
    HurricaneEntry h;
    h.setKey(MAJOR);
    if(database.Search(h)){
        database.PrintAll();
    }
    else{
        linked_list<HurricaneEntry> tempList;
        HurricaneEntry temp;
        while(!(database.IsEmpty())){
            database.RemoveRear(temp);
            temp.setKey(MAJOR);
            tempList.InsertInOrder(temp);
        }
        database = tempList;
        database.PrintAll();
    }
}

void HurricaneDataBase::SortsPrintsByNumberofDeaths(){
    HurricaneEntry h;
    h.setKey(DEATHS);
    if(database.Search(h)){
        database.PrintAll();
    }
    else{
        linked_list<HurricaneEntry> tempList;
        HurricaneEntry temp;
        while(!(database.IsEmpty())){
            database.RemoveRear(temp);
            temp.setKey(DEATHS);
            tempList.InsertInOrder(temp);
        }
        database = tempList;
        database.PrintAll();
    }
}
    
#endif