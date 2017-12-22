//
//  main.cpp
//  csi2772_project
//
//  Created by Khadim Mbaye on 11/12/17.
//  Copyright © 2017 Khadim Mbaye. All rights reserved.
//
#include "colour.h"
#include "dice.h"
#include "rollOfDice.h"
#include "qwintoRow.h"
#include "qwixxRow.h"
#include "scoreSheet.h"
#include "qwintoScoreSheet.h"
#include "qwixxScoreSheet.h"
#include "player.h"
#include "qwintoPlayer.h"
#include "qwixxPlayer.h"

using namespace std;

bool isQwintoWinner(QwintoPlayer* p1, QwintoPlayer* p2){ //fonction utiliser pour determiner le gagnant de la partie
    return (p1->getScoreSheet()).calcTotal() == (p1->getScoreSheet()).calcTotal();
}

bool isQwixxWinner(QwixxPlayer* p1, QwixxPlayer* p2){ //fonction utiliser pour determiner le gagnant de la partie
    return (p1->getScoreSheet()).calcTotal() == (p1->getScoreSheet()).calcTotal();
}

int main(int argc, const char * argv[]) {
    
    //selection du jeu
    string selected;
    bool qwinto = false;
    bool qwixx = false;
    
    cout<<"Bienvenue! Selectionner un jeu (qwinto/qwixx)?: ";
    cin>>selected;
    while (selected!="qwinto" && selected!="qwixx") {
        cout<<"Entree invalide!!, veuillez entrer qwinto ou qwixx: " ;
        cin.clear();
        cin.ignore(256,'\n');
        cin>>selected;
    }
    if (selected=="qwinto") {
        qwinto = true;
        qwixx = false;
    } else if (selected=="qwixx"){
        qwixx = true;
        qwinto = false;
    }
    
    
    if (qwinto) {
        cout<<"\n//================ QWINTO GAME ====================//"<<endl;
        
        //combien de joueurs
        int numOfPlayers;
        cout<<"Combien de joueurs pour cette partie?: ";
        cin>>numOfPlayers;
        while (cin.fail() || numOfPlayers>3 || numOfPlayers<1) {//if not int
            cout<<"Entree invalide!!, veuillez entrer un chiffre de 1 à 3 nombre de joueurs: " ;
            cin.clear();
            cin.ignore(256,'\n');
            cin>>numOfPlayers;
        }
        cout<<endl;
        
        vector<QwintoPlayer*> vec;
        //demander le nom des joueurs
        for (int i=0; i<numOfPlayers; i++) {
            string pName;
            cout<<"Quel est le nom du "<<i+1<<"° joueur?: ";
            cin>>pName;
            cout<<endl;
            vec.push_back(new QwintoPlayer(pName)); //insert players in vec
        }
        
        
        
        auto a = *(vec.begin());
        bool gameOver= !(a->getScoreSheet());
        
        while (!gameOver) {
            for(auto& p:vec){
                p->setActive(true);//debut du tour du joueur actif
                RollOfDice rd; //create the RollOfDice
                cout<<"-------------Au tour de "<<(p->getScoreSheet()).getPlayerName()<<"---------------"<<endl;
                p->inputBeforeRoll(rd);
                cout<<"lancer des dés ..........."<<endl;
                rd.roll();
                cout<<rd;
                p->printScoreSheet();
                p->inputAfterRoll(rd);
                
                for (auto& p:vec) {//print scoresheet of none active players and get their inputs and score
                    if ( !(p->getActive()) ) {
                        p->printScoreSheet();
                        p->inputAfterRoll(rd);
                    }
                }
                
                p->setActive(false);// fin du tour
                gameOver = !(p->getScoreSheet());
            }
            
        }
        
        //after fin du game
        for (auto& p:vec) {
            cout<<"----------------FIN DU GAME------------------"<<endl;
            p->printScoreSheet();
        }
        
        //determiner gagnant
        QwintoPlayer winner = **(max_element(vec.begin(), vec.end(), isQwintoWinner));
        cout<<"BRAVO **"<<(winner.getScoreSheet()).getPlayerName()<<"**, VOUS AVEZ GAGNÉ LA PARTIE!"<<endl;
        
        //================ End Qwinto Game====================//
        
    } else if (qwixx) {
        cout<<"\n//================ QWIXX GAME====================//"<<endl;
        
        //combien de joueurs
        int numOfPlayers;
        cout<<"Combien de joueurs pour cette partie?: ";
        cin>>numOfPlayers;
        while (cin.fail() || numOfPlayers>3 || numOfPlayers<1) {//if not int
            cout<<"Entree invalide!!, veuillez entrer un chiffre de 1 à 3 comme nombre de joueurs: " ;
            cin.clear();
            cin.ignore(256,'\n');
            cin>>numOfPlayers;
        }
        cout<<endl;
        
        vector<QwixxPlayer*> vec;
        //demander le nom des joueurs
        for (int i=0; i<numOfPlayers; i++) {
            string pName;
            cout<<"Quel est le nom du "<<i+1<<"° joueur?: ";
            cin>>pName;
            cout<<endl;
            vec.push_back(new QwixxPlayer(pName)); //insert players in vec
        }
        
        auto a = *(vec.begin());
        bool gameOver= !(a->getScoreSheet());
        
        while (!gameOver) {
            for(auto& p:vec){
                p->setActive(true);//debut du tour du joueur actif
                RollOfDice rd; //create the RollOfDice
                cout<<"-------------Au tour de "<<(p->getScoreSheet()).getPlayerName()<<"---------------"<<endl;
                p->inputBeforeRoll(rd);
                cout<<rd;
                p->printScoreSheet();
                p->inputAfterRoll(rd);
                
                for (auto& p:vec) {//print scoresheet of none active players and get their inputs and score
                    if ( !(p->getActive()) ) {
                        p->printScoreSheet();
                        p->inputAfterRoll(rd);
                    }
                }
                p->setActive(false);// fin du tour
                gameOver = !(p->getScoreSheet());
            }
            
        }
        
        //after fin du game
        for (auto& p:vec) {
            cout<<"----------------FIN DU GAME------------------"<<endl;
            p->printScoreSheet();
        }
        
        //determiner gagnant
        QwixxPlayer winner = **(max_element(vec.begin(), vec.end(), isQwixxWinner));
        cout<<"BRAVO **"<<(winner.getScoreSheet()).getPlayerName()<<"**, VOUS AVEZ GAGNÉ LA PARTIE!"<<endl;
        
        
    }
    

    return 0;
}
