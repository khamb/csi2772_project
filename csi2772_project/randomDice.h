//
//  randomDice.h
//  csi2772_project
//
//  Created by Khadim Mbaye on 11/16/17.
//  Copyright © 2017 Khadim Mbaye. All rights reserved.
//

#ifndef randomDice_h
#define randomDice_h

#include <iostream>
#include <chrono>
#include <random>

struct RandomDice{
    static int randomise(int from, int to){
        std::random_device rd;  //Will be used to obtain a seed for the random number engine
        std::mt19937 generator(rd()); //Standard mersenne_twister_engine seeded with rd()
        return std::uniform_int_distribution<int>{from,to}(generator);
    }
};

#endif /* randomDice_h */
