//
//  qwintoScoreSheet.h
//  csi2772_project
//
//  Created by Khadim Mbaye on 11/16/17.
//  Copyright © 2017 Khadim Mbaye. All rights reserved.
//

#ifndef qwintoScoreSheet_h
#define qwintoScoreSheet_h

#include "scoreSheet.h"
#include "qwintoRow.h"
#include <stdexcept>

//some helper functions might be missing??

class QwintoScoreSheet: public ScoreSheet{

private:
    QwintoRow<Colour::RED> redRow;
    QwintoRow<Colour::YELLOW> yelRow;
    QwintoRow<Colour::BLUE> blueRow;
    int redTotal;
    int yelTotal;
    int blueTotal;
    int mostLeft;
    int mli;
    
    
protected:
    bool validate(const RollOfDice& rd, Colour C, int pos) ;
    
public:
    QwintoScoreSheet(string playerName, int fails, int total): ScoreSheet::ScoreSheet(playerName,fails,total),redTotal(0),yelTotal(0),blueTotal(0),mostLeft(-2),mli(-2){}
    
    bool score(const RollOfDice& rd, Colour C, int pos=-1); //??
    
    bool operator!() const;
    
    int calcTotal();
    
    void setMostLeft(int i){
        mostLeft =i;
    }
    
    void setmli(int i){
       mli =i;
    }
    
    friend ostream& operator<<(ostream&, QwintoScoreSheet&);
    
};

#endif /* qwintoScoreSheet_h */
