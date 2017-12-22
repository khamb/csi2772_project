//
//  rollOfDice.h
//  csi2772_project
//
//  Created by Khadim Mbaye on 11/16/17.
//  Copyright © 2017 Khadim Mbaye. All rights reserved.
//

#ifndef rollOfDice_h
#define rollOfDice_h

#include "dice.h"
#include <vector>
#include <random>
#include <algorithm>
#include <iomanip>

using namespace std;

struct RollOfDice{
    
private:
    vector<Dice> conteneur;
    
    
public:
    void roll();
    RollOfDice pair() const;
    
    //iterators redefining for rollOfDice
    vector<Dice>::iterator begin(){ return conteneur.begin();}
    vector<Dice>::iterator end(){return conteneur.end();}
    vector<Dice>::const_iterator begin() const { return conteneur.cbegin();}
    vector<Dice>::const_iterator end() const {return conteneur.cend();}
    //End of iterators redefining
    
    //helper functions
    void push(const Dice& d){ conteneur.push_back(d); }
    size_t getSize() const { return conteneur.size();}
    //End of helper functions
    
    
    operator int() const;
    friend ostream& operator<<(ostream& , RollOfDice&);
};

#endif /* rollOfDice_h */
