//
//  dice.cpp
//  csi2772_project
//
//  Created by Khadim Mbaye on 11/16/17.
//  Copyright © 2017 Khadim Mbaye. All rights reserved.
//

#include <stdio.h>
#include "dice.h"


int Dice::roll(){
    face = RandomDice::randomise(1,6);
    return face;
}

ostream& operator<<(ostream& os, const Dice& d){ //overloading output operator (COLOUR,FACE)
    os<<"(";
    switch (d.couleur) {
     case Colour::RED:
     os<<"RED";
     break;
     case Colour::YELLOW:
     os<<"YELLOW";
     break;
     case Colour::GREEN:
     os<<"GREEN";
     break;
     case Colour::BLUE:
     os<<"BLUE";
     break;
     case Colour::WHITE:
     os<<"WHITE";
     break;
     default:
     break;
     }
    os<<","<<d.face<<")";
    return os;
}
