/*
 * File: HuricaneEntry.h
 * Code: Stores information about a hurricane
 * Name: Nicholas Campola
 * Date: 11/9/2018
 * CPSC 340
 */

#ifndef HurricaneEntry_cpp
#define HurricaneEntry_cpp
#include <vector>
#include <iostream>
#include <string>
#include "HurricaneEntry.h"
using namespace std;



HurricaneEntry::HurricaneEntry(){
    year = 1196;
    numTropicalStorms = 9;
    numHurricanes = 1;
    numMajorHurricanes = 5;
    numDeaths = 9;
    StrongestStorms.push_back("Glados One");
    key = 1;
}

HurricaneEntry::HurricaneEntry(string line){
        int index = -1;
        index = line.find(",");
        int length = 0;
        length = index+1; 
        
        if(index > -1 && index < line.size()){
            year = stoi(line.substr(0, index));
            line = line.erase(0,length);

            index = line.find(",");
            length = 0;
            length = index+1; 
            
            numTropicalStorms = stoi(line.substr(0, index));
            line = line.erase(0,length);
            
            index = line.find(",");
            length = 0;
            length = index+1; 
            
            numHurricanes = stoi(line.substr(0, index));
            line = line.erase(0,length);
            
            index = line.find(",");
            length = 0;
            length = index+1; 
            
            numMajorHurricanes = stoi(line.substr(0, index));
            line = line.erase(0,length);
            
            index = line.find(",");
            length = 0;
            length = index+1; 
            
            
            
            string Death = line.substr(0, index);
            if(Death.compare("Unknown")==0){
                numDeaths = -99;
            }
            else{
                numDeaths = stoi(line.substr(0, index));
            }
            line = line.erase(0,length);
            
            index = line.find(",");
            length = 0;
            length = index+1; 
            
            string storms = line.substr(0, index);
            
            StrongestStorms.push_back(storms);
            line = line.erase(0,length);
            
            key = 0;
        }
    
    }
    void HurricaneEntry::setYear(int year){
        this->year = year;
    }
    
    int HurricaneEntry::getYear(){
        return year;
    }
    
    void HurricaneEntry::setnumTropicalStorms(int numTropicalStorms){
        this->numTropicalStorms = numTropicalStorms;
    }
    int HurricaneEntry::getnumTropicalStorms(){
        return numTropicalStorms;
    }
    void HurricaneEntry::setnumHurricanes(int numHurricanes){
        this->numHurricanes;
    }
    int HurricaneEntry::getnumHurricanes(){
        return numHurricanes;
    }
    void HurricaneEntry::setnumMajorHurricanes(int numMajorHurricanes){
        this->numMajorHurricanes = numMajorHurricanes;
    }
    int HurricaneEntry::getnumMajorHurricanes(){
        return numMajorHurricanes;
    }
    void HurricaneEntry::setnumDeaths(int numDeaths){
        this->numDeaths = numDeaths;
    }
    int HurricaneEntry::getnumDeaths(){
        return numDeaths;
    }
    vector<string> HurricaneEntry::getStrongestStorms(){
        return StrongestStorms;
    }
    
    int HurricaneEntry::getNumberStrongestStorms(){
        int index = -1;
        int count = 1;
        index = StrongestStorms.at(0).find("-");
        
        while(index > -1 && index < StrongestStorms.at(0).size()){
        count = count + 1;
        index = StrongestStorms.at(0).find("-",index+1);
        }
        
        return count;
    }
    void HurricaneEntry::setKey(int key){
    //Will be one of the constant from above
    //If Hurricane is the key that means the linked list is will be created based year
    this->key = key;
    }
    
    int HurricaneEntry::getKey(){
        return key;
    }
    
    
    bool HurricaneEntry::operator< (HurricaneEntry left){
        if(key == 0){
            if(year < left.year){
                return true;
            }
            else{
                return false;
            }
        }
        if(key == 1){
            if(numHurricanes < left.numHurricanes){
                return true;
            }
            else{
                return false;
            }
        }
        if(key == 2){
            if(numTropicalStorms < left.numTropicalStorms){
                return true;
            }
            else{
                return false;
            }
        }
        if(key == 3){
            if(numMajorHurricanes < left.numMajorHurricanes){
                return true;
            }
            else{
                return false;
            }
        }
        if(key == 4){
            if(numDeaths < left.numDeaths){
                return true;
            }
            else{
                return false;
            }
        }
    }
    
    bool HurricaneEntry::operator> (HurricaneEntry left){
        if(key == 0){
            if(year > left.year){
                return true;
            }
            else{
                return false;
            }
        }
        if(key == 1){
            if(numHurricanes > left.numHurricanes){
                return true;
            }
            else{
                return false;
            }
        }
        if(key == 2){
            if(numTropicalStorms > left.numTropicalStorms){
                return true;
            }
            else{
                return false;
            }
        }
        if(key == 3){
            if(numMajorHurricanes > left.numMajorHurricanes){
                return true;
            }
            else{
                return false;
            }
        }
        if(key == 4){
            if(numDeaths > left.numDeaths){
                return true;
            }
            else{
                return false;
            }
        }
    }
    
    bool HurricaneEntry::operator<= (HurricaneEntry left){
        if(key == 0){
            if(year <= left.year){
                return true;
            }
            else{
                return false;
            }
        }
        if(key == 1){
            if(numHurricanes <= left.numHurricanes){
                return true;
            }
            else{
                return false;
            }
        }
        if(key == 2){
            if(numTropicalStorms <= left.numTropicalStorms){
                return true;
            }
            else{
                return false;
            }
        }
        if(key == 3){
            if(numMajorHurricanes <= left.numMajorHurricanes){
                return true;
            }
            else{
                return false;
            }
        }
        if(key == 4){
            if(numDeaths <= left.numDeaths){
                return true;
            }
            else{
                return false;
            }
        }
    }
    bool HurricaneEntry::operator>= (HurricaneEntry left){
        if(key == 0){
            if(year >= left.year){
                return true;
            }
            else{
                return false;
            }
        }
        if(key == 1){
            if(numHurricanes >= left.numHurricanes){
                return true;
            }
            else{
                return false;
            }
        }
        if(key == 2){
            if(numTropicalStorms >= left.numTropicalStorms){
                return true;
            }
            else{
                return false;
            }
        }
        if(key == 3){
            if(numMajorHurricanes >= left.numMajorHurricanes){
                return true;
            }
            else{
                return false;
            }
        }
        if(key == 4){
            if(numDeaths >= left.numDeaths){
                return true;
            }
            else{
                return false;
            }
        }
    }
    
    bool HurricaneEntry::operator!= (HurricaneEntry left){
        if(key != left.key){
            return true;
        }
        else{
            return false;
        }
    }
    
    bool HurricaneEntry::operator== (HurricaneEntry left){
        if(key == left.key){
            return true;
        }
        else{
            return false;
        }
    }
    
    #endif