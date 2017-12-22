//
//  dice.h
//  csi2772_project
//
//  Created by Khadim Mbaye on 11/16/17.
//  Copyright © 2017 Khadim Mbaye. All rights reserved.
//

#ifndef dice_h
#define dice_h

#include <iostream>
#include "randomDice.h"
#include "colour.h"
using namespace std;

//initialising the member variable of our helper struct
//default_random_engine RandomDice::generator;

struct Dice{
    //member variables
    const Colour couleur;
    int face;
    int roll();
    friend ostream& operator<<(ostream& , const Dice&);
};

#endif /* dice_h */
