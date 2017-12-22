//
//  scoreSheet.h
//  csi2772_project
//
//  Created by Khadim Mbaye on 11/16/17.
//  Copyright © 2017 Khadim Mbaye. All rights reserved.
//

#ifndef scoreSheet_h
#define scoreSheet_h
#include "rollOfDice.h"
#include <string>

class ScoreSheet{ //all methods might be pure virtual
protected:
    string playerName;
    int failedThrows;
    int total; // score total
    
    virtual bool validate(const RollOfDice& rd,Colour C, int pos)  = 0;//to be defined is the base concrete classes
    
public:
    ScoreSheet(string pName, int fails, int t_points): playerName(pName), failedThrows(0), total(t_points){}
    
    virtual bool score(const RollOfDice& rd, Colour C, int pos=-1) = 0;
    
    virtual bool operator!() const = 0;
    
    virtual int calcTotal() = 0; //??
    
    int setTotal(){
        total = calcTotal();
        return total;
    }
    
    //helpers
    void incrementFails(){
        failedThrows++;
    }
    
    int getFails(){
        return failedThrows;
    }
    string getPlayerName(){
        return playerName;
    }
    //end helpers

    friend ostream& operator<<(ostream& ,ScoreSheet&);
};

#endif /* scoreSheet_h */
