//
//  qwintoScoreSheet.cpp
//  csi2772_project
//
//  Created by Khadim Mbaye on 11/22/17.
//  Copyright © 2017 Khadim Mbaye. All rights reserved.
//

#include "qwintoScoreSheet.h"

bool QwintoScoreSheet::validate(const RollOfDice& rd,Colour C, int pos) {
    int rdScore = rd;
    //est ce que cette couleur a ete utilisee?
    
    //====les nombres doivent etre croissants de Gauche vers Droite
    if(C==Colour::RED){
        for (int i = pos; i < 10;i++){//red
            if (rdScore >= redRow[i] && redRow[i] != 0){
                return false;
            }
        }
        for (int i = pos; i > 0;i--){
            if (rdScore <= redRow[i] && redRow[i] != 0){
                return false;
            }
        }
    }else if(C==Colour::YELLOW){//yellow
        for (int i = pos; i < 10;i++){
            if (rdScore >= yelRow[i] && yelRow[i] != 0){
                return false;
            }
        }
        for (int i = pos; i > 0;i--){
            if (rdScore <= yelRow[i] && yelRow[i] != 0){
                return false;
            }
        }
    }else if(C==Colour::BLUE){//blue
        for (int i = pos; i < 10;i++){
            if (rdScore >= blueRow[i] && blueRow[i] != 0){
                return false;
            }
        }
        for (int i = pos; i > 0;i--){
            if (rdScore <= blueRow[i] && blueRow[i] != 0){
                return false;
            }
        }
    }


    //=====
    switch (C) {
        case Colour::RED:
            for (int i=0;i<10;i++) {
                if (redRow[i]==rdScore) {
                    return false;
                }
            }
            break;
        case Colour::YELLOW:
            for (int i=0;i<10;i++) {
                if (yelRow[i]==rdScore) {
                    return false;
                }
            }
            break;
        case Colour::BLUE:
            for (int i=0;i<10;i++) {
                if (blueRow[i]==rdScore) {
                    return false;
                }
            }
            break;
            
        default:
            break;
    }
    
    //pas de scores repetes
    if( count(redRow.r_begin,redRow.r_end,rdScore) > 0 ){
        return false;
    }
    if(count(yelRow.r_begin,yelRow.r_end,rdScore) >0 ){
        return false;
    }
    if(count(blueRow.r_begin,blueRow.r_end,rdScore) >0 ){
        return false;
    }
    
    // champs invalides ..
    if ( (pos== 3 && C == Colour::RED) || (pos== 5 && C == Colour::YELLOW) || (pos== 4 && C == Colour::BLUE) ) {
        return false;
    }
    
    //les joueurs peuvent entrer les scores dans les rangees si des des de la meme couleur sont utilises
    int used=0;
    for (auto& d:rd) {
        if (d.couleur == C) {
            used++;
        }
    }
    if (used==0) {
        return false;
    }
    
    //if cant score, its a fail ?? how to implement it ...
    return true;
}

bool QwintoScoreSheet::score(const RollOfDice& rd, Colour C,int pos){
    
    try {
        if ( !validate(rd, C, pos) ) {
            throw runtime_error("Vous ne pouvez pas entrer le score à cette postion!");
        }
        switch (C) {
            case Colour::RED:
                redRow[pos] = rd;
                redTotal++;
                return true;
                break;
            case Colour::YELLOW:
                yelRow[pos] = rd;
                yelTotal++;
                return true;
                break;
            case Colour::BLUE:
                blueRow[pos] = rd;
                blueTotal++;
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

int QwintoScoreSheet::calcTotal(){
    
    int bonus=0;
    int tmpTotal = 0;
    
    //si rangees complete, score = derniere entree
    if(redRow.isFull()){
        redTotal = redRow[9];
    }else if(yelRow.isFull()){
        yelTotal = yelRow[9];
    }else if(blueRow.isFull()){
        blueTotal = blueRow[9];
    }
    //si colonne bonus special
    if (redRow[1]!=0 && yelRow[2]!=0 && blueRow[3]!=0) {
        bonus+=redRow[1]; //red
    }else if(redRow[5]!=0 && yelRow[6]!=0 && blueRow[7]!=0){
        bonus+=redRow[5]; //red
    }else if(yelRow[7]!=0 && redRow[6]!=0 && blueRow[8]!=0){
        bonus+=yelRow[7]; //yel
    }else if(blueRow[2]!=0 && yelRow[1]!=0 && blueRow[0]!=0){
        bonus+=blueRow[2]; //blue
    }else if(blueRow[9]!=0 && yelRow[8]!=0 && redRow[7]!=0){
        bonus+=blueRow[9]; //blue
    }
    tmpTotal = bonus + redTotal + yelTotal + blueTotal - (getFails()*5);
    
    return tmpTotal;
}

bool QwintoScoreSheet::operator!() const{
    //if 4 fails or 2 completed rows, GAME OVER
    if (failedThrows == 4 || (redRow.isFull() && blueRow.isFull()) || (redRow.isFull() && yelRow.isFull()) || (yelRow.isFull() && blueRow.isFull())) {
        return true;
    }
    return false;
}

ostream& operator<<(ostream&os, QwintoScoreSheet& qwintoS){
    cout<<qwintoS.redRow;
    cout<<qwintoS.yelRow;
    cout<<qwintoS.blueRow;
    return os;
}
