//
//  qwintoPlayer.cpp
//  csi2772_project
//
//  Created by Khadim Mbaye on 11/30/17.
//  Copyright © 2017 Khadim Mbaye. All rights reserved.
//

#include "qwintoPlayer.h"
void QwintoPlayer::inputBeforeRoll(RollOfDice& rd){//behaves differently whether the player is active or not
    string colour;
    
    if (isActive) {
        //number of dices to  be rolled  1 to 3
        cout<<"Combien de dés voulez-vous lancer, "<<scoreSheet.getPlayerName()<<"?: ";
        cin>>nDicesRolled;
        while (cin.fail() || nDicesRolled<1 || nDicesRolled>3) {//if not int
            cout<<"Entree invalide!!, veuillez entrer un chiffre entre 1 et 3: " ;
            cin.clear();
            cin.ignore(256,'\n');
            cin>>nDicesRolled;
        }
        cout<<endl;
        //their colours
        if (nDicesRolled==3) {
            Dice dee = {.couleur = Colour::RED, .face = 0};
            Dice dee2 = {.couleur = Colour::YELLOW, .face = 0};
            Dice dee3 = {.couleur = Colour::BLUE, .face = 0};
            rd.push(dee);
            rd.push(dee2);
            rd.push(dee3);
        }if (nDicesRolled!=3) {
            for (int i=0; i<nDicesRolled; i++) {
                
                cout<<"Quel est la couleur du "<<(i+1)<<"° dé(red/yellow/blue)?:";
                cin>>colour;
                while (colour!="red" && colour!="yellow" && colour!="blue") {//if not int
                    cout<<"Entree invalide!!, veuillez entrer red, yellow ou blue: " ;
                    cin.clear();
                    cin.ignore(256,'\n');
                    cin>>colour;
                }
                cout<<endl;
                //create dice according to choise and add to the rollOfDice
                if (colour == "red") {
                    Dice dee = {.couleur = Colour::RED, .face = 0};
                    rd.push(dee);
                } else if (colour == "yellow") {
                    Dice dee = {.couleur = Colour::YELLOW, .face = 0};
                    rd.push(dee);
                } else if (colour == "blue") {
                    Dice dee = {.couleur = Colour::BLUE, .face = 0};
                    rd.push(dee);
                }
            }
        }
       
    }

    //after, roll dices and show result on main.cpp    
}

void QwintoPlayer::inputAfterRoll(RollOfDice& rd){//behaves differently whether the player is active or not
    
    //where to input score, according dice color/row color => which position
    if (!isActive) {
        string wis; //want to input score
        string row;
        int pos;
        cout<<"VOULEZ-vous entrer le pointage pour ce tour, "<< scoreSheet.getPlayerName()<<"? (yes/no):";
        cin>>wis; //might wanna add a loop to check input??..........??
        cout<<endl;
        if (wis=="yes") {
            cout<<"Dans quelle rangee voulez-vous l'entrer? (red/yellow/blue): ";
            cin>>row;
            while (row!="red" && row!="yellow" && row!="blue") {
                cout<<"Entree invalide!!, veuillez entrer red, yellow ou blue: " ;
                cin.clear();
                cin.ignore(256,'\n');
                cin>>row;
            }
            cout<<endl;
            cout<<"A quelle postion de la rangee "<<row<<" voulez-vous l'entrer? (0..9): ";
            cin>>pos;
            while (cin.fail()) {//if not int
                cout<<"Entree invalide!!, un chiffre entre 0 et 9 comme position: " ;
                cin.clear();
                cin.ignore(256,'\n');
                cin>>pos;
            }
            cout<<endl;
            if (row=="red") { // input score in the right row
                scoreSheet.score(rd, Colour::RED,pos);
            } else if (row=="yellow") {
                scoreSheet.score(rd, Colour::YELLOW,pos);
            } else if (row=="blue") {
                scoreSheet.score(rd, Colour::BLUE,pos);
            }
        }
        
    }else{ //if player is active
        string wis; //want to input score
        string row;
        int pos;
        cout<<"POUVEZ-vous entrer le pointage pour ce tour,"<< scoreSheet.getPlayerName()<<"? (yes/no):";
        cin>>wis; //might wanna add a loop to check input??..........??
        cout<<endl;
        if (wis=="yes") {
            cout<<"Dans quelle rangee voulez-vous l'entrer? (red/yellow/blue): ";
            cin>>row;
            while (row!="red" && row!="yellow" && row!="blue") {
                cout<<"Entree invalide!!, veuillez entrer red, yellow ou blue: " ;
                cin.clear();
                cin.ignore(256,'\n');
                cin>>row;
            }
            cout<<endl;
            cout<<"A quelle postion de la rangee "<<row<<" voulez-vous l'entrer? (0..9): ";
            cin>>pos;
            while (cin.fail()) {//if not int
                cout<<"Entree invalide!!, un chiffre entre 0 et 9 comme position: " ;
                cin.clear();
                cin.ignore(256,'\n');
                cin>>pos;
            }
            cout<<endl;
            if (row=="red") { // input score in the right row
                scoreSheet.score(rd, Colour::RED,pos);
            } else if (row=="yellow") {
                scoreSheet.score(rd, Colour::YELLOW,pos);
            } else if (row=="blue") {
                scoreSheet.score(rd, Colour::BLUE,pos);
            }
        } else{// if no
            //failedThrows++
            scoreSheet.incrementFails();
            //log lancer echoue!
            cout<<"Il y a "<<scoreSheet.getFails()<<" echecs pour le moment !"<<endl;
        }
    }
    
    //after, score dice according to input
    //do not forget to retroact with players
}
