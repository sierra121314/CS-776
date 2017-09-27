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
#include <fstream>

using namespace std;

bool DeJong_1;
bool DeJong_2;
bool DeJong_3;
bool DeJong_4;

bool low;
bool nom;
bool high;

int sim_size = 30;

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
        bit_size();
        lower_bound = -5.12;
    }
    
    if (DeJong_2 == true) {
        range = 2048;
        num_x = 2;
        bit_size();
        lower_bound = -2.048;
        
    }
    
    if (DeJong_3 == true) {
        range = 512;
        num_x = 5;
        bit_size();
        lower_bound = -5.12;
        funct = round(x);
    }
    
    if (DeJong_4 == true) {
        range = 128;
        num_x = 30;
        bit_size();
        lower_bound = -1.28;
        funct = 0; //redo
    }
}

int main() {
    DeJong_1 = true;
    DeJong_2 = false;
    DeJong_3 = false;
    DeJong_4 = false;
    
    low = true;
    nom = false;
    high = false;
    
    ofstream f1out_low_min;
    ofstream f1out_low_max;
    ofstream f1out_low_ave;
    ofstream f1out_high_min;
    ofstream f1out_high_max;
    ofstream f1out_high_ave;
    ofstream f1out_nom_min;
    ofstream f1out_nom_max;
    ofstream f1out_nom_ave;
    
    
    if (DeJong_1 ==true && low==true){
        f1out_low_min.open("F1-low-min.txt", ofstream::out | ofstream::trunc);
        f1out_low_max.open("F1-low-max.txt", ofstream::out | ofstream::trunc);
        f1out_low_ave.open("F1-low-ave.txt", ofstream::out | ofstream::trunc);
        
        GA G;
        srand(time (NULL));
        
        for (int s = 0; s < sim_size; s++){
            cout <<"stat run\t" << s << endl;
            bits B;
            B.problem_setup();
            G.run(B.string_size, B.b_size, B.num_x, B.lower_bound,  B.funct, DeJong_1, DeJong_2, DeJong_3, DeJong_4, low, nom, high);
            
        }
    }
    if (DeJong_1 ==true && low==true){
        f1out_low_min.close();
        f1out_low_max.close();
        f1out_low_ave.close();
    }
    low = false;
    nom = false;
    high = true;
    
    if (DeJong_1 ==true && high==true){
        f1out_high_min.open("F1-high-min.txt", ofstream::out | ofstream::trunc);
        f1out_high_max.open("F1-high-max.txt", ofstream::out | ofstream::trunc);
        f1out_high_ave.open("F1-high-ave.txt", ofstream::out | ofstream::trunc);
        
        GA G;
        srand(time (NULL));
        
        for (int s = 0; s < sim_size; s++){
            cout <<"stat run\t" << s << endl;
            bits B;
            B.problem_setup();
            G.run(B.string_size, B.b_size, B.num_x, B.lower_bound,  B.funct, DeJong_1, DeJong_2, DeJong_3, DeJong_4, low, nom, high);
            
        }
    }
    if (DeJong_1 ==true && high==true){
        f1out_high_min.close();
        f1out_high_max.close();
        f1out_high_ave.close();
    }
    
    low = false;
    nom = true;
    high = false;
    if (DeJong_1 ==true && nom==true){
        f1out_nom_min.open("F1-nom-min.txt", ofstream::out | ofstream::trunc);
        f1out_nom_max.open("F1-nom-max.txt", ofstream::out | ofstream::trunc);
        f1out_nom_ave.open("F1-nom-ave.txt", ofstream::out | ofstream::trunc);
        
        GA G;
        srand(time (NULL));
        
        for (int s = 0; s < sim_size; s++){
            cout <<"stat run\t" << s << endl;
            bits B;
            B.problem_setup();
            G.run(B.string_size, B.b_size, B.num_x, B.lower_bound,  B.funct, DeJong_1, DeJong_2, DeJong_3, DeJong_4, low, nom, high);
            
        }
    }
    if (DeJong_1 ==true && nom==true){
        f1out_nom_min.close();
        f1out_nom_max.close();
        f1out_nom_ave.close();
    }
    ///// DEJONG 2 ///////
    DeJong_1 = false;
    DeJong_2 = true;
    
    low = true;
    nom = false;
    high = false;
    ofstream f2out_low_min;
    ofstream f2out_low_max;
    ofstream f2out_low_ave;
    ofstream f2out_high_min;
    ofstream f2out_high_max;
    ofstream f2out_high_ave;
    ofstream f2out_nom_min;
    ofstream f2out_nom_max;
    ofstream f2out_nom_ave;
    
    if (DeJong_2 ==true && low==true){
        f2out_low_min.open("F2-low-min.txt", ofstream::out | ofstream::trunc);
        f2out_low_max.open("F2-low-max.txt", ofstream::out | ofstream::trunc);
        f2out_low_ave.open("F2-low-ave.txt", ofstream::out | ofstream::trunc);
        
        GA G;
        srand(time (NULL));
        
        for (int s = 0; s < sim_size; s++){
            cout <<"stat run\t" << s << endl;
            bits B;
            B.problem_setup();
            G.run(B.string_size, B.b_size, B.num_x, B.lower_bound,  B.funct, DeJong_1, DeJong_2, DeJong_3, DeJong_4, low, nom, high);
            
        }
    }
    if (DeJong_2 ==true && low==true){
        f2out_low_min.close();
        f2out_low_max.close();
        f2out_low_ave.close();
    }
    low = false;
    nom = false;
    high = true;
    
    if (DeJong_2 ==true && high==true){
        f2out_high_min.open("F2-high-min.txt", ofstream::out | ofstream::trunc);
        f2out_high_max.open("F2-high-max.txt", ofstream::out | ofstream::trunc);
        f2out_high_ave.open("F2-high-ave.txt", ofstream::out | ofstream::trunc);
        
        GA G;
        srand(time (NULL));
        
        for (int s = 0; s < sim_size; s++){
            cout <<"stat run\t" << s << endl;
            bits B;
            B.problem_setup();
            G.run(B.string_size, B.b_size, B.num_x, B.lower_bound,  B.funct, DeJong_1, DeJong_2, DeJong_3, DeJong_4, low, nom, high);
            
        }
    }
    if (DeJong_2 ==true && high==true){
        f2out_high_min.close();
        f2out_high_max.close();
        f2out_high_ave.close();
    }
    
    low = false;
    nom = true;
    high = false;
    if (DeJong_2 ==true && nom==true){
        f2out_nom_min.open("F2-nom-min.txt", ofstream::out | ofstream::trunc);
        f2out_nom_max.open("F2-nom-max.txt", ofstream::out | ofstream::trunc);
        f2out_nom_ave.open("F2-nom-ave.txt", ofstream::out | ofstream::trunc);
        
        GA G;
        srand(time (NULL));
        
        for (int s = 0; s < sim_size; s++){
            cout <<"stat run\t" << s << endl;
            bits B;
            B.problem_setup();
            G.run(B.string_size, B.b_size, B.num_x, B.lower_bound,  B.funct, DeJong_1, DeJong_2, DeJong_3, DeJong_4, low, nom, high);
            
        }
    }
    if (DeJong_2 ==true && nom==true){
        f2out_nom_min.close();
        f2out_nom_max.close();
        f2out_nom_ave.close();
    }
    
    ///// DEJONG 3 ///////
    DeJong_1 = false;
    DeJong_2 = false;
    DeJong_3 = true;
    
    low = true;
    nom = false;
    high = false;
    ofstream f3out_low_min;
    ofstream f3out_low_max;
    ofstream f3out_low_ave;
    ofstream f3out_high_min;
    ofstream f3out_high_max;
    ofstream f3out_high_ave;
    ofstream f3out_nom_min;
    ofstream f3out_nom_max;
    ofstream f3out_nom_ave;
    
    if (DeJong_3 ==true && low==true){
        f3out_low_min.open("F3-low-min.txt", ofstream::out | ofstream::trunc);
        f3out_low_max.open("F3-low-max.txt", ofstream::out | ofstream::trunc);
        f3out_low_ave.open("F3-low-ave.txt", ofstream::out | ofstream::trunc);
        
        GA G;
        srand(time (NULL));
        
        for (int s = 0; s < sim_size; s++){
            cout <<"stat run\t" << s << endl;
            bits B;
            B.problem_setup();
            G.run(B.string_size, B.b_size, B.num_x, B.lower_bound,  B.funct, DeJong_1, DeJong_2, DeJong_3, DeJong_4, low, nom, high);
            
        }
    }
    if (DeJong_3 ==true && low==true){
        f3out_low_min.close();
        f3out_low_max.close();
        f3out_low_ave.close();
    }
    low = false;
    nom = false;
    high = true;
    
    if (DeJong_3 ==true && high==true){
        f3out_high_min.open("F3-high-min.txt", ofstream::out | ofstream::trunc);
        f3out_high_max.open("F3-high-max.txt", ofstream::out | ofstream::trunc);
        f3out_high_ave.open("F3-high-ave.txt", ofstream::out | ofstream::trunc);
        
        GA G;
        srand(time (NULL));
        
        for (int s = 0; s < sim_size; s++){
            cout <<"stat run\t" << s << endl;
            bits B;
            B.problem_setup();
            G.run(B.string_size, B.b_size, B.num_x, B.lower_bound,  B.funct, DeJong_1, DeJong_2, DeJong_3, DeJong_4, low, nom, high);
            
        }
    }
    if (DeJong_3 ==true && high==true){
        f3out_high_min.close();
        f3out_high_max.close();
        f3out_high_ave.close();
    }
    
    low = false;
    nom = true;
    high = false;
    if (DeJong_3 ==true && nom==true){
        f3out_nom_min.open("F3-nom-min.txt", ofstream::out | ofstream::trunc);
        f3out_nom_max.open("F3-nom-max.txt", ofstream::out | ofstream::trunc);
        f3out_nom_ave.open("F3-nom-ave.txt", ofstream::out | ofstream::trunc);
        
        GA G;
        srand(time (NULL));
        
        for (int s = 0; s < sim_size; s++){
            cout <<"stat run\t" << s << endl;
            bits B;
            B.problem_setup();
            G.run(B.string_size, B.b_size, B.num_x, B.lower_bound,  B.funct, DeJong_1, DeJong_2, DeJong_3, DeJong_4, low, nom, high);
            
        }
    }
    if (DeJong_3 ==true && nom==true){
        f3out_nom_min.close();
        f3out_nom_max.close();
        f3out_nom_ave.close();
    }

    //DEJONG 4//
    DeJong_1 = false;
    DeJong_2 = false;
    DeJong_3 = false;
    DeJong_4 = true;
    low = true;
    nom = false;
    high = false;
    ofstream f4out_low_min;
    ofstream f4out_low_max;
    ofstream f4out_low_ave;
    ofstream f4out_high_min;
    ofstream f4out_high_max;
    ofstream f4out_high_ave;
    ofstream f4out_nom_min;
    ofstream f4out_nom_max;
    ofstream f4out_nom_ave;
    
    if (DeJong_4 ==true && low==true){
        f4out_low_min.open("F4-low-min.txt", ofstream::out | ofstream::trunc);
        f4out_low_max.open("F4-low-max.txt", ofstream::out | ofstream::trunc);
        f4out_low_ave.open("F4-low-ave.txt", ofstream::out | ofstream::trunc);
        
        GA G;
        srand(time (NULL));
        
        for (int s = 0; s < sim_size; s++){
            cout <<"stat run\t" << s << endl;
            bits B;
            B.problem_setup();
            G.run(B.string_size, B.b_size, B.num_x, B.lower_bound,  B.funct, DeJong_1, DeJong_2, DeJong_3, DeJong_4, low, nom, high);
            
        }
    }
    if (DeJong_4 ==true && low==true){
        f4out_low_min.close();
        f4out_low_max.close();
        f4out_low_ave.close();
    }
    low = false;
    nom = false;
    high = true;
    
    if (DeJong_4 ==true && high==true){
        f4out_high_min.open("F4-high-min.txt", ofstream::out | ofstream::trunc);
        f4out_high_max.open("F4-high-max.txt", ofstream::out | ofstream::trunc);
        f4out_high_ave.open("F4-high-ave.txt", ofstream::out | ofstream::trunc);
        
        GA G;
        srand(time (NULL));
        
        for (int s = 0; s < sim_size; s++){
            cout <<"stat run\t" << s << endl;
            bits B;
            B.problem_setup();
            G.run(B.string_size, B.b_size, B.num_x, B.lower_bound,  B.funct, DeJong_1, DeJong_2, DeJong_3, DeJong_4, low, nom, high);
            
        }
    }
    if (DeJong_4 ==true && high==true){
        f4out_high_min.close();
        f4out_high_max.close();
        f4out_high_ave.close();
    }
    
    low = false;
    nom = true;
    high = false;
    if (DeJong_4 ==true && nom==true){
        f4out_nom_min.open("F4-nom-min.txt", ofstream::out | ofstream::trunc);
        f4out_nom_max.open("F4-nom-max.txt", ofstream::out | ofstream::trunc);
        f4out_nom_ave.open("F4-nom-ave.txt", ofstream::out | ofstream::trunc);
        
        GA G;
        srand(time (NULL));
        
        for (int s = 0; s < sim_size; s++){
            cout <<"stat run\t" << s << endl;
            bits B;
            B.problem_setup();
            G.run(B.string_size, B.b_size, B.num_x, B.lower_bound,  B.funct, DeJong_1, DeJong_2, DeJong_3, DeJong_4, low, nom, high);
            
        }
    }
    if (DeJong_4 ==true && nom==true){
        f4out_nom_min.close();
        f4out_nom_max.close();
        f4out_nom_ave.close();
    }

    
    return 0;
}
