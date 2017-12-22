//
//  player.h
//  csi2772_project
//
//  Created by Khadim Mbaye on 11/16/17.
//  Copyright © 2017 Khadim Mbaye. All rights reserved.
//

#ifndef player_h
#define player_h

#include "rollOfDice.h"

class Player{
protected:
    bool isActive;

public:
    virtual void inputBeforeRoll(RollOfDice& rd) = 0;
    virtual void inputAfterRoll(RollOfDice& rd) = 0;
    void setActive(bool b){
        isActive = b;
    }
    bool getActive(){
        return isActive;
    }

};

#endif /* player_h */
