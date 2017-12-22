//
//  qwintoRow.h
//  csi2772_project
//
//  Created by Khadim Mbaye on 11/20/17.
//  Copyright © 2017 Khadim Mbaye. All rights reserved.
//

#ifndef qwintoRow_h
#define qwintoRow_h
#include "colour.h"
#include "rollOfDice.h"
#include <stdexcept>
#include <array>


typedef std::array<int, 10> Array;


template<Colour C>
class QwintoRow{
private:
    Array row{}; //representaton of a qwintoRow
    int wrong_index =-1;
    
    bool validate(int i) const{
        try{
            if(i<0 || i>9){
                throw out_of_range("index out of range ...");
            }

            return true;
        }catch(out_of_range er){
            cerr<<er.what()<<endl;
        }
        return false;
    }
    
    
public:
    QwintoRow(){
    }
    
    int& operator[](const int i) {
        if(!validate(i)){
            return wrong_index;
        }
        return row[i];
    }
    
    int operator[](int i) const{
        if(!validate(i)){
            return wrong_index;
        }
        return row[i];
    }

    //defining helpers
    Array::iterator r_begin = row.begin();
    Array::iterator r_end = row.begin();
    bool isFull() const{
       int currSize = static_cast<int>(row.size() - count(row.begin(), row.end(), 0));
        return currSize == row.size();
    }
    //end
    
    friend ostream& operator<<(ostream& os, const QwintoRow<C>& row){
        
        if(C==Colour::RED){
            cout<<"            -------------------------------"<<endl;
            for (int i=0;i<10;i++) {
                if(i==0){
                    cout<<"Red         |";
                   (row[i]==0)? cout<<"  ":cout<<setw(2)<<row[i];
                }
                else if(i==1 || i==5){
                    cout<<"%";
                    ((row[i]==0)? cout<<"  ": cout<<setw(2)<<row[i])<<"%";
                } else if(i==3){
                    cout<<"XX";
                }else if(i==4){
                    cout<<"|";
                    (row[i]==0)? cout<<"  ": cout<<setw(2)<<row[i];
                }else{
                    (row[i]==0)? cout<<"  ":cout<<setw(2)<<row[i];
                    cout<<"|";
                }
            }
            cout<<endl;
            cout<<"         ----------------------------------"<<endl;
        } else if(C==Colour::YELLOW){
            for (int i=0;i<10;i++) {
                if(i==0){
                    cout<<"Yellow   |";
                    (row[i]==0)? cout<<"  ": cout<<setw(2)<<row[i];
                }
                else if(i==7){
                    cout<<"%";
                    ((row[i]==0)? cout<<"  ": cout<<setw(2)<<row[i])<<"%";
                } else if(i==5){
                    cout<<"|XX";
                }else if(i>7){
                    (row[i]==0)? cout<<"  ": cout<<setw(2)<<row[i];
                    cout<<"|";
                }else{
                    cout<<"|";
                    (row[i]==0)? cout<<"  ": cout<<setw(2)<<row[i];
                }
            }
            cout<<endl;
            cout<<"      ----------------------------------"<<endl;
        }if(C==Colour::BLUE){
            for (int i=0;i<10;i++) {
                if(i==0){
                    cout<<"Blue  |";
                    (row[i]==0)? cout<<"  ":cout<<setw(2)<<row[i];
                }
                else if(i==2 || i==9){
                    cout<<"%";
                    ((row[i]==0)? cout<<"  ": cout<<setw(2)<<row[i])<<"%";
                } else if(i==4){
                    cout<<"|XX";
                } else if(i==3){
                    (row[i]==0)? cout<<"  ": cout<<setw(2)<<row[i];
                }else{
                    cout<<"|";
                    (row[i]==0)? cout<<"  ": cout<<setw(2)<<row[i];
                }
            }
            cout<<endl;
            cout<<"      -------------------------------"<<endl;
        }
        
        return os;
    }
    
};

    


#endif /* qwintoRow_h */
