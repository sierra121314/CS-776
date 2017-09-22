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
#include "DeJong_funct_1.h"

using namespace std;

bool DeJong_1 = true;
bool DeJong_2 = false;
bool DeJong_3 = false;
bool DeJong_4 = false;

int sim_size = 1;

class bits {
public:
    int bits;
    void bit_size();
    void problem_setup();
    
};

void bits::bit_size(){
    int bit_size = log2(bits) + 1;
    //cout << "bitsize: " << bit_size << endl;
}

void bits::problem_setup() {
    if (DeJong_1 == true) {
        bits = 512;
        bit_size(); //times num_x
        //call DeJong function?
    }
    
    if (DeJong_2 == true) {
        bits = 2048;
        bit_size(); //times num_x
        
    }
    
    if (DeJong_3 == true) {
        bits = 512;
        bit_size(); //times num_x
        
    }
    
    if (DeJong_4 == true) {
        bits = 128;
        bit_size(); //times num_x
        
    }
}

int main() {
    
    for (int s = 0; s < sim_size; s++){
        bits B;
        B.problem_setup();
        //call GA
    }
    
    
    
    return 0;
}
