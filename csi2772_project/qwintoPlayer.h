
//
//  qwintoPlayer.h
//  csi2772_project
//
//  Created by Khadim Mbaye on 11/16/17.
//  Copyright © 2017 Khadim Mbaye. All rights reserved.
//

#ifndef qwintoPlayer_h
#define qwintoPlayer_h

#include "player.h"
#include "qwintoScoreSheet.h"

class QwintoPlayer: public Player{
private:
    QwintoScoreSheet scoreSheet;
    int nDicesRolled;
    
public:
    QwintoPlayer(string pName): scoreSheet(pName,0,0), nDicesRolled(0){}
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
    
    QwintoScoreSheet getScoreSheet(){//return the scorsheet object
        return scoreSheet;
    }
    //end helper
};

#endif /* qwintoPlayer_h */
