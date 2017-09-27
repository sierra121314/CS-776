//
//  main.cpp
//  CS776_HW3
//
//  Created by Sierra Gonzales on 9/21/17.
//  Copyright © 2017 Sierra Gonzales. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <math.h>
#include "GA.h"
#include <cstdlib>

using namespace std;

bool DeJong_1;
bool DeJong_2;
bool DeJong_3;
bool DeJong_4;

int sim_size = 1;

class bits {
public:
    double range;
    double num_x;
    double x;
    double b_size;
    double string_size;
    double lower_bound;
    double funct;
    void bit_size();
    void problem_setup();
    
};

void bits::bit_size(){
    b_size = log2(range) + 1;
    //cout << "bitsize: " << bit_size << endl;
    string_size = b_size*num_x;
    cout << string_size << endl;
}


void bits::problem_setup() {
    if (DeJong_1 == true) {
        range = 512;
        num_x = 3;
        bit_size(); //times num_x
        lower_bound = -5.12;
    }
    
    if (DeJong_2 == true) {
        range = 2048;
        num_x = 2;
        bit_size(); //times num_x
        lower_bound = -2.048;
        funct = 0; //redo
    }
    
    if (DeJong_3 == true) {
        range = 512;
        num_x = 5;
        bit_size(); //times num_x
        lower_bound = -5.12;
        funct = round(x);
    }
    
    if (DeJong_4 == true) {
        range = 128;
        num_x = 30;
        bit_size(); //times num_x
        lower_bound = -1.28;
        funct = 0; //redo
    }
}

int main() {
    DeJong_1 = true;
    DeJong_2 = false;
    DeJong_3 = false;
    DeJong_4 = false;
    
    GA G;
    srand(time (NULL));
    for (int s = 0; s < sim_size; s++){
        bits B;
        B.problem_setup();
        G.run(B.string_size, B.b_size, B.num_x, B.lower_bound, B.x, B.funct, DeJong_1, DeJong_2, DeJong_3, DeJong_4);
    }
    
    
    
    return 0;
}
