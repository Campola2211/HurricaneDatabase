//
//  HurricaneEntry .h
//  Word Surfer
//
//  Created by Jennifer Polack on 4/4/18.
//  Copyright © 2018 Jennifer Polack. All rights reserved.
//
/*
 * File: HuricaneEntry.h
 * Code: Stores information about a hurricane
 * Name: Nicholas Campola
 * Date: 11/9/2018
 * CPSC 340
 */

#ifndef HurricaneEntry__h
#define HurricaneEntry__h
#include <vector>
#include <iostream>
#include <string>
using namespace std;

class HurricaneEntry {
    friend ostream & operator<<(ostream &out, HurricaneEntry temp);
public:

    /**
     Default Constructor for HurricaneEntry
     */ 
    HurricaneEntry();
    /**
     Constructor for HurricaneEntry
     */ 
    HurricaneEntry(string line);
    /**
     Sets the year of a hurricane HurricaneEntry
     @param year the year of the entry
     */ 
    void setYear(int year);
    /**
     Gets the year of a hurricane HurricaneEntry
     @returns year the year of the entry
     */ 
    int getYear();
    /**
     Sets the number of tropical storms for a HurricaneEntry
     @param numTropicalStorms number of tropical storms
     */ 
    void setnumTropicalStorms(int numTropicalStorms);
    /**
     Gets the number of tropical storms for a HurricaneEntry
     @returns numTropicalStorms number of tropical storms
     */ 
    int getnumTropicalStorms();
    /**
     Sets the number of hurricanes for a HurricaneEntry
     @param numHurricanes number of hurricanes
     */ 
    void setnumHurricanes(int numHurricanes);
    /**
     Gets the number of hurricanes for a HurricaneEntry
     @returns numHurricanes number of hurricanes
     */ 
    int getnumHurricanes();
    /**
     Sets the number of majors hurricanes for a HurricaneEntry
     @param numMajorHurricanes number of major hurricanes
     */ 
    void setnumMajorHurricanes(int numMajorHurricanes);
    /**
     Gets the number of majors hurricanes for a HurricaneEntry
     @returns numMajorHurricanes number of major hurricanes
     */ 
    int getnumMajorHurricanes();
    /**
     Sets the number of deaths for a HurricaneEntry
     @param numDeaths number of deaths
     */ 
    void setnumDeaths(int numDeaths);
    /**
     Gets the number of deaths for a HurricaneEntry
     @returns numDeaths number of deaths
     */ 
    int getnumDeaths();
    /**
     Gets vector of strongestStorms in a hurricane entry
     @returns vector<string>
     */ 
    vector<string> getStrongestStorms();
    /**
     Gets the number of strongestStorms in a hurricane entry
     @returns int
     */ 
    int getNumberStrongestStorms();
    /**
     Sets the key for a HurricaneEntry
     @param key identifier for how to be sorted
     */ 
    void setKey(int key);
    //Will be one of the constant from above
    //If Hurricane is the key that means the linked list is will be created based year
    /**
     Gets the key for a HurricaneEntry
     @returns key identifier for how to be sorted
     */ 
    int getKey();
    
    /**
     Boolean operator that chooses which private variable to compare based on the key value of a hurricane entry
     @param left the hurricane entry on the left side of a compare
     @returns bool
     */ 
    bool operator< (HurricaneEntry left);
    /**
     Boolean operator that chooses which private variable to compare based on the key value of a hurricane entry
     @param left the hurricane entry on the left side of a compare
     @returns bool
     */ 
    bool operator> (HurricaneEntry left);
    /**
     Boolean operator that chooses which private variable to compare based on the key value of a hurricane entry
     @param left the hurricane entry on the left side of a compare
     @returns bool
     */ 
    bool operator<= (HurricaneEntry left);
    /**
     Boolean operator that chooses which private variable to compare based on the key value of a hurricane entry
     @param left the hurricane entry on the left side of a compare
     @returns bool
     */ 
    bool operator>= (HurricaneEntry left);
    /**
     Boolean operator that checks the value between two keys
     @param left the hurricane entry on the left side of a compare
     @returns bool
     */ 
    bool operator!= (HurricaneEntry left);
    /**
     Boolean operator that checks the value between two keys
     @param left the hurricane entry on the left side of a compare
     @returns bool
     */ 
    bool operator== (HurricaneEntry left);
    
private:
    
    int year;
    int numTropicalStorms;
    int numHurricanes;
    int numMajorHurricanes;
    int numDeaths;
    vector<string>    StrongestStorms;
    int key;

    
};


#endif /* HurricaneEntry__h */
