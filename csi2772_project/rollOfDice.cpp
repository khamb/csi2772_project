//
//  rollOfDice.cpp
//  csi2772_project
//
//  Created by Khadim Mbaye on 11/16/17.
//  Copyright © 2017 Khadim Mbaye. All rights reserved.
//

#include "rollOfDice.h"

void RollOfDice::roll(){
    for(Dice& d:conteneur){
        d.roll();
    }
}

RollOfDice RollOfDice::pair() const{
    RollOfDice myRod; //will contain 2 white dices
    
    for (auto& d:conteneur ) {
        if (d.couleur==Colour::WHITE) {
            myRod.push(d);
        }
    }
    
    return myRod;
}

RollOfDice::operator int() const{
    int sum_faces = 0;
    for(Dice d:conteneur){
        sum_faces += d.face;
    }
    return sum_faces;
}

ostream& operator<<(ostream& os , RollOfDice& rd){
        for (Dice d:rd) {
            cout<<d<<endl;
        }
    os<<endl;
    return os;
}
