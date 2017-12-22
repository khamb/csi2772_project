//
//  qwixxScoreSheet.cpp
//  csi2772_project
//
//  Created by Khadim Mbaye on 11/22/17.
//  Copyright © 2017 Khadim Mbaye. All rights reserved.
//

#include "qwixxScoreSheet.h"


bool QwixxScoreSheet::validate(const RollOfDice& rd, Colour C,int pos){
    
    int rdScore = rd;
    int index = rdScore;
    //verifier les bornes
    if (rdScore<0 || rdScore>12) {
        return false;
    }
    
    //si la case est deja coche
    if ((C==Colour::RED && redRow[index-2]==-1) || (C==Colour::YELLOW && yelRow[index-2]==-1) || (C==Colour::BLUE && blueRow[12-index]==-1) || (C==Colour::GREEN && greenRow[12-index]==-1) ) {
        return false;
    }
    
    //il faut cocher de la gauche vers la droite
    
    if(C==Colour::RED){// get most left crossed index
        for (int i=0; i<13; i++) {
            if (redRow[i]==-1) {
                setleftCrossed(i+2);
            }
        }
    }else if(C==Colour::YELLOW){
        for (int i=0; i<13; i++) {
            if (yelRow[i]==-1) {
                setleftCrossed(i+2);
            }
        }
    }else if(C==Colour::BLUE){
        for (int i=0; i<13; i++) {
            if (blueRow[i]==-1) {
                setleftCrossed(12-i);
            }
        }
    }else if(C==Colour::GREEN){
        for (int i=0; i<13; i++) {
            if (greenRow[i]==-1) {
                setleftCrossed(12-i);
            }
        }
    }
    if ((index<leftCrossed && C==Colour::RED && leftCrossed!=-2) || (C==Colour::YELLOW && index<leftCrossed && leftCrossed!=-2)) {//si le joueur essay de cocher une cas de la droite vers la gauche, faux
        setleftCrossed(-2);
        return false;
    }
    if ((index>leftCrossed && C==Colour::BLUE && leftCrossed!=-2) || (index>leftCrossed &&C==Colour::GREEN && leftCrossed!=-2)) {//si le joueur essay de cocher une cas de la droite vers la gauche, faux
        setleftCrossed(-2);
        return false;
    }
    
    //si la derniere case est coche??
    if ( (index==12 && C==Colour::RED && redTotal<4) || (index==12 && C==Colour::YELLOW && yelTotal<4) ) {
        return false;
    } 
    if ( (index==2 && C==Colour::BLUE && blueTotal<4) || (index==2 && C==Colour::GREEN && greenTotal<4) ) {
        return false;
    }
    
    return true;
}

bool QwixxScoreSheet::score(const RollOfDice& rd, Colour C,int pos){
    int rdScore = rd;
    int index = rdScore;
    
    try {
        if ( !validate(rd, C) ) {
            throw runtime_error("Vous ne pouvez pas entrer le score à cette postion!");
        }
        switch (C) {
            case Colour::RED:
                redRow[index-2] = -1;
                redTotal++;
                if (index==12) {
                    redRow[11] = 76;
                }
                return true;
                break;
            case Colour::YELLOW:
                yelRow[index-2] = -1;
                yelTotal++;
                if (index==12) {
                    redRow[11] = 76;
                }
                return true;
                break;
            case Colour::BLUE:
                blueRow[12-index] = -1;
                blueTotal++;
                if (index==2) {
                    redRow[11] = 76;
                }
                return true;
                break;
            case Colour::GREEN:
                greenRow[12-index] = -1;
                greenTotal++;
                if (index==2) {
                    redRow[11] = 76;
                }
                return true;
                break;
                
            default:
                break;
        }
    } catch (runtime_error err) {
        cout<<err.what()<<endl;
    }
    
    return false;
}

int QwixxScoreSheet::calcTotal(){
    int tmpTotal = 0;
    tmpTotal = scoreTable[redTotal] + scoreTable[yelTotal] + scoreTable[blueTotal] + scoreTable[greenTotal] - (getFails()*5);
    return tmpTotal;
}

bool QwixxScoreSheet::operator!() const{
    //RB, RY, RG , BY, BG, YG
    if (failedThrows == 4) {
        return true;
    } else if (redRow[11]==76 && yelRow[11]==76){
        return true;
    } else if (yelRow[11]==76 && blueRow[11]==76){
        return true;
    } else if (blueRow[11]==76 && greenRow[11]==76){
        return true;
    } else if (greenRow[11]==76 && yelRow[11]==76){
        return true;
    } else if (blueRow[11]==76 && redRow[11]==76){
        return true;
    } else if (greenRow[11]==76 && redRow[11]==76){
        return true;
    }
    return false;
}

ostream& operator<<(ostream& os, QwixxScoreSheet& qwixxS){
    cout<<qwixxS.redRow;
    cout<<qwixxS.yelRow;
    cout<<qwixxS.blueRow;
    cout<<qwixxS.greenRow;
    cout<<"         ------------------------------------"<<endl;
    return os;
}
