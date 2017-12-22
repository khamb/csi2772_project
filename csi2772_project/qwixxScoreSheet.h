//
//  qwixxScoreSheet.h
//  csi2772_project
//
//  Created by Khadim Mbaye on 11/16/17.
//  Copyright © 2017 Khadim Mbaye. All rights reserved.
//

#ifndef qwixxScoreSheet_h
#define qwixxScoreSheet_h

#include "scoreSheet.h"
#include "qwixxRow.h"
#include <vector>
#include <list>
#include <map>
using namespace std;

class QwixxScoreSheet: public ScoreSheet{
    
private:
    QwixxRow<vector<int>, Colour::RED> redRow;
    QwixxRow<vector<int>, Colour::YELLOW> yelRow;
    QwixxRow<vector<int>, Colour::BLUE> blueRow;
    QwixxRow<vector<int>, Colour::GREEN> greenRow;
    int redTotal;
    int yelTotal;
    int blueTotal;
    int greenTotal;
    map<int,int> scoreTable;
    bool naDone;
    int leftCrossed;
    
protected:
    bool validate(const RollOfDice& rd, Colour C,int =-1);
    
public:
    QwixxScoreSheet(string playerName, int fails, int total): ScoreSheet::ScoreSheet(playerName,fails,total),redTotal(0),yelTotal(0),blueTotal(0),greenTotal(0),naDone(false), leftCrossed(-2){
        
        for (int i=2; i<13; i++) {//init redRow and yelRow
            redRow.push(i);
            yelRow.push(i);
        }
        
        for (int i=12; i>1; i--) {//init redRow and yelRow
            blueRow.push(i);
            greenRow.push(i);
        }
        
        //insert U/L value
        //asci U =85, asci L = 76
        redRow.push(85);
        yelRow.push(85);
        blueRow.push(85);
        greenRow.push(85);
        
        //initialiser la table de score <entree,point>
        scoreTable[0]=0;
        scoreTable[1]=1;
        scoreTable[2]=3;
        scoreTable[3]=6;
        scoreTable[4]=10;
        scoreTable[5]=15;
        scoreTable[6]=21;
        scoreTable[7]=28;
        scoreTable[8]=36;
        scoreTable[9]=45;
        scoreTable[10]=55;
        scoreTable[11]=66;
        scoreTable[12]=78;
        
        
    }
    
    bool score(const RollOfDice& rd, Colour C,int =-1); //??
    
    bool operator!() const;
    
    int calcTotal();
    
    //helper
    bool getCombin(){
        return naDone;
    }
    void setCombin(bool b){
        naDone = b;
    }
    void setleftCrossed(int i){
        leftCrossed =i;
    }
    //end helper
    
    friend ostream& operator<<(ostream&, QwixxScoreSheet&);
    
};

#endif /* qwixxScoreSheet_h */
