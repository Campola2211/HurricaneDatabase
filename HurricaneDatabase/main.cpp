/*
 * File: main.cpp
 * Code: Reads in csv data and prompts user to view it in different sorted formats
 * Name: Nicholas Campola
 * Date: 11/9/2018
 * CPSC 340
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <ios>
#include <iomanip>
using namespace std;

#include "HurricaneEntry.h"
#include "HurricaneDataBase.h"

ostream & operator<<(ostream &out, HurricaneEntry temp);


int main(){
    int choice = 0;
    HurricaneDataBase h("HurricaneData.csv");
    cout<<endl;
    while(choice != 6){
        cout<<"1:Print Yearly Hurricane Data."<<endl;
        cout<<"2:Print out Tropical Storms in order from least to most"<<endl;
        cout<<"3:Print out Hurricanes in order from least to most"<<endl;
        cout<<"4:Print out Major Hurricanes in order from least to most"<<endl;
        cout<<"5:Print out Number of Deaths in order from least to most"<<endl;
        cout<<"6:Exit"<<endl;
        cout<<"Enter a choice:";
        cin>>choice;
        if(choice == 1){
            cout<<"Prints out the numbers of storms per year"<<endl;
            cout<<"1 Hurricane = * "<<endl;
            cout<<"1 Tropical Storms = #"<<endl;
            h.PrintStormsByYear();
            cout<<endl;
        }
        if(choice == 2){
            cout<<"Tropical Storms Least to the Most over Time"<<endl;
            h.SortsPrintsByNumberofTropicalStorms();
            cout<<endl;
        }
        if(choice == 3){
            cout<<"Hurricanes Least to the Most over Time"<<endl;
            h.SortsPrintsByNumberofHurricanes();
            cout<<endl;
        }
        if(choice == 4){
            cout<<"Major Storms Least to the Most over Time"<<endl;
            h.SortsPrintsByNumberofMajorStorms();
            cout<<endl;
        }
        if(choice == 5){
            cout<<"Lost of Life Due to Storms Least to the Most over Time"<<endl;
            h.SortsPrintsByNumberofDeaths();
            cout<<endl;
        }
        if(choice > 5 || choice <1){
            cout<<"Invalid Input"<<endl;
        }
    }
}

ostream & operator<<(ostream &out, HurricaneEntry temp){
    if(temp.key == 0){
        cout<<temp.year<<endl;
        cout<<"Hurricanes -";
        for(int i =0; i < temp.numHurricanes; i++){
            cout<<"*";
        }
        cout<<endl;
        cout<<"Tropical St-";
        for(int i =0; i < temp.numTropicalStorms; i++){
            cout<<"#";
        }
        cout<<endl;

        if(temp.getNumberStrongestStorms() == 1){
            
            cout<<"Largest Storm -"<<temp.StrongestStorms.at(0)<<" ";
        }
        else{
            for(int i = 0; i < temp.StrongestStorms.at(0).size(); i++){
                if(temp.StrongestStorms.at(0).at(i) == '-'){
                    temp.StrongestStorms.at(0).at(i) = ' ';
            }
        }
            cout<<"Largest Storms-"<<temp.StrongestStorms.at(0)<<" ";
        }
    }
    else if(temp.key == 1){
        cout<<temp.year<<"-";
        for(int i =0; i < temp.numHurricanes; i++){
            cout<<"*";
        }
        cout<<"";
    }
    else if(temp.key == 2){
        cout<<temp.year<<"-";
        for(int i = 0; i < temp.numTropicalStorms; i++){
            cout<<"#";
        }
        cout<<"";
    }
    else if(temp.key == 3){
        cout<<temp.year<<"-";
        for(int i = 0; i < temp.numMajorHurricanes; i++){
            cout<<"X";
        }
        cout<<"";
    }
    else if(temp.key == 4){
        cout<<temp.year<<"-";
        if(temp.numDeaths == -99){
            cout<<"Unknown";
        }
        else{
            cout<<temp.numDeaths;
        }
    }
    else{
    cout<<temp.year<<" "<<temp.numTropicalStorms<<" "<<temp.numHurricanes<<" "<<temp.numMajorHurricanes<<" "<<temp.numDeaths<<" "<<temp.StrongestStorms.at(0)<<" "<<temp.key;
    }
}