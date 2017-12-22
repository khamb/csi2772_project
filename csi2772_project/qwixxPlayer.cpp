//
//  qwixxPlayer.cpp
//  csi2772_project
//
//  Created by Khadim Mbaye on 11/30/17.
//  Copyright © 2017 Khadim Mbaye. All rights reserved.
//

#include "qwixxPlayer.h"

void QwixxPlayer::inputBeforeRoll(RollOfDice& rd){
    if (isActive) {
        //creating a 6 dee RollOfDice
        Dice deer = {.couleur = Colour::RED, .face = 0};
        rd.push(deer);
        Dice deey = {.couleur = Colour::YELLOW, .face = 0};
        rd.push(deey);
        Dice deeb = {.couleur = Colour::BLUE, .face = 0};
        rd.push(deeb);
        Dice deeg = {.couleur = Colour::GREEN, .face = 0};
        rd.push(deeg);
        Dice deew1 = {.couleur = Colour::WHITE, .face = 0};
        rd.push(deew1);
        Dice deew2 = {.couleur = Colour::WHITE, .face = 0};
        rd.push(deew2);
        cout<<"lancer des D ............"<<endl;
        rd.roll();
    }
    
}


void QwixxPlayer::inputAfterRoll(RollOfDice& rd){
    RollOfDice whiteScore = rd.pair();
    
    if (isActive) {
        //input the public score
        string wis,row,combin;
        cout<< scoreSheet.getPlayerName()<<", VOULEZ-vous entrer le pointage des D blancs qui est ["<<int(whiteScore)<<"] ?(yes/no): ";
        cin>>wis;
        
        if (wis=="yes") {
            cout<<"Dans quelle rangee voulez-vous l'entrer? (red/yellow/blue/green): ";
            cin>>row;
            while (row!="red" && row!="yellow" && row!="blue" && row!="green") {
                cout<<"Entree invalide!!, veuillez entrer red, yellow, blue ou green: " ;
                cin.clear();
                cin.ignore(256,'\n');
                cin>>row;
            }
            cout<<endl;
            if (row=="red") { // input score in the right row
                scoreSheet.score(whiteScore, Colour::RED);
            } else if (row=="yellow") {
                scoreSheet.score(whiteScore, Colour::YELLOW);
            } else if (row=="blue") {
                scoreSheet.score(whiteScore, Colour::BLUE);
            }
            else if (row=="green") {
                scoreSheet.score(whiteScore, Colour::GREEN);
            }
            
            //combinaison de score
            //if (scoreSheet.getCombin()) {
                int whiteS;
                RollOfDice combinedROD;
                cout<<scoreSheet.getPlayerName()<<", Voulez-vous faire une combinaison de couleur?(yes/no): ";
                cin>>combin;
                if (combin=="yes") {
                    cout<<rd;
                    
                    //demander score de blanc
                    cout<<"quel est le score du D blanc choisi?(1..6): ";
                    cin>>whiteS;
                    while (cin.fail() || whiteS>7 || whiteS<1) {//if not int
                        cout<<"Entree invalide!!, un chiffre entre 1 et 6 comme position: " ;
                        cin.clear();
                        cin.ignore(256,'\n');
                        cin>>whiteS;
                    }
                    cout<<endl;
                    
                    //selectionner le de blanc en question
                    for (auto& chosen:rd) {
                        if (chosen.face==whiteS) {
                            combinedROD.push(chosen);
                            break;
                        }
                    }
                    
                    //demander autre couleur
                    cout<<"quelle couleur voulez-vous la combiner avec? (red/yellow/blue/green): ";
                    cin>>row;
                    while (row!="red" && row!="yellow" && row!="blue" && row!="green") {
                        cout<<"Entree invalide!!, veuillez entrer red, yellow, blue ou green: " ;
                        cin.clear();
                        cin.ignore(256,'\n');
                        cin>>row;
                    }
                    cout<<endl;
                    if (row=="red") {
                        for (auto& chosen:rd) {
                            if (chosen.couleur==Colour::RED) {
                                combinedROD.push(chosen);
                                break;
                            }
                        }
                        scoreSheet.score(combinedROD, Colour::RED);
                    } else if (row=="yellow") {
                        for (auto& chosen:rd) {
                            if (chosen.couleur==Colour::YELLOW) {
                                combinedROD.push(chosen);
                                break;
                            }
                        }
                        scoreSheet.score(combinedROD, Colour::YELLOW);
                    } else if (row=="blue") {
                        for (auto& chosen:rd) {
                            if (chosen.couleur==Colour::BLUE) {
                                combinedROD.push(chosen);
                                break;
                            }
                        }
                        scoreSheet.score(combinedROD, Colour::BLUE);
                    }
                    else if (row=="green") {
                        for (auto& chosen:rd) {
                            if (chosen.couleur==Colour::GREEN) {
                                combinedROD.push(chosen);
                                break;
                            }
                        }
                        scoreSheet.score(combinedROD, Colour::GREEN);
                    }
                    //fin demander autre couleur
                    
                //}
            }
            
        } else{// if no
            //failedThrows++
            scoreSheet.incrementFails();
            //log lancer echoue!
            cout<<"Il y a "<<scoreSheet.getFails()<<" echecs pour le moment !"<<endl;
        }
        
    } else{// PLAYER NOT ACTIF
        
        string wis,row,combin;
        cout<<scoreSheet.getPlayerName()<<", VOULEZ-vous entrer le pointage des D blancs qui de ["<<int(whiteScore)<<"] ?(yes/no): ";
        cin>>wis;
        
        if (wis=="yes") {
            cout<<"Dans quelle rangee voulez-vous l'entrer? (red/yellow/blue/green): ";
            cin>>row;
            while (row!="red" && row!="yellow" && row!="blue" && row!="green") {
                cout<<"Entree invalide!!, veuillez entrer red, yellow, blue ou green: " ;
                cin.clear();
                cin.ignore(256,'\n');
                cin>>row;
            }
            cout<<endl;
            if (row=="red") { // input score in the right row
                scoreSheet.score(whiteScore, Colour::RED);
            } else if (row=="yellow") {
                scoreSheet.score(whiteScore, Colour::YELLOW);
            } else if (row=="blue") {
                scoreSheet.score(whiteScore, Colour::BLUE);
            }
            else if (row=="green") {
                scoreSheet.score(whiteScore, Colour::GREEN);
            }
        }
        
        //scoreSheet.setCombin(true);
    }
    
}
