//
//  qwixxRow.h
//  csi2772_project
//
//  Created by Khadim Mbaye on 11/20/17.
//  Copyright © 2017 Khadim Mbaye. All rights reserved.
//

#ifndef qwixxRow_h
#define qwixxRow_h

#include "colour.h"
#include "rollOfDice.h"
#include <stdexcept>


//template< class T, Colour C>
template<class T, Colour C>
class QwixxRow {

private:
    T conteneur; // max of 12 columns
    
public:
    QwixxRow(){
    }
    
    QwixxRow<T,C>& operator+=(const RollOfDice& rd){
        try {
            if (rd.getSize() != 2) {
                throw runtime_error("RollOfDice object size != 2 ...");
            }
            
            //do something ..
            for (const Dice& d:rd) {
                conteneur.push_back(d);
            }
            
        } catch (runtime_error er) {
            cerr<<er.what()<<endl;
        }
        
        return *this;
    }
    
    //helper
    void push(int i){
        conteneur.push_back(i);
    }
    /*void set(int val,int i){
        conteneur[i] = val;
    }*/
    
    int& operator[](const int i) {
        return conteneur[i];
    }
    
    int operator[](int i) const{
        return conteneur[i];
    }
    //end helper
    
    friend ostream& operator<<(ostream& os, QwixxRow<T,C>& row){
        
        
        cout<<"         ------------------------------------"<<endl;
        switch (C) {
            case Colour::RED:
                cout<<"Red      |";
                break;
            case Colour::YELLOW:
                cout<<"Yellow   |";
                break;
            case Colour::BLUE:
                cout<<"Blue     |";
                break;
            case Colour::GREEN:
                cout<<"Green    |";
                break;
            default:
                break;
        }
        
        for (int i=0;i<11;i++) {
            (row[i]==-1)? cout<<"XX":cout<<setw(2)<<row[i];
            cout<<"|";
        }
        (row[11]==85)? cout<<" U": cout<<" L";
        cout<<endl;
        
        return os;
    }
};
#endif /* qwixxRow_h */
