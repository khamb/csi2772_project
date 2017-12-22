//
//  qwixxPlayer.h
//  csi2772_project
//
//  Created by Khadim Mbaye on 11/16/17.
//  Copyright © 2017 Khadim Mbaye. All rights reserved.
//

#ifndef qwixxPlayer_h
#define qwixxPlayer_h

#include "player.h"
#include "qwixxScoreSheet.h"

class QwixxPlayer: public Player{
private:
    QwixxScoreSheet scoreSheet;
    
    
public:
    QwixxPlayer(string pName): scoreSheet(pName,0,0){}
    void inputBeforeRoll(RollOfDice& rd);
    void inputAfterRoll(RollOfDice& rd);
    
    //helpers
    void printScoreSheet(){
        if (!scoreSheet) {
            cout<<"Player Name: "<<scoreSheet.getPlayerName()<<"          Points:"<<scoreSheet.setTotal()<<endl;
            cout<<scoreSheet<<endl;
            cout<<"Failed Throws:"<<scoreSheet.getFails()<<endl;
            cout<<"\n";
        }else{
            cout<<"Player Name: "<<scoreSheet.getPlayerName()<<endl;
            cout<<scoreSheet<<endl;
            cout<<"Failed Throws:"<<scoreSheet.getFails()<<endl;
            cout<<"\n";
        }
    }
    
    QwixxScoreSheet getScoreSheet(){//return the scorsheet object
        return scoreSheet;
    }
    //end helper
};

#endif /* qwixxPlayer_h */
