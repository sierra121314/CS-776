//
//  GA.h
//  CS776_HW3
//
//  Created by Sierra Gonzales on 9/21/17.
//  Copyright © 2017 Sierra Gonzales. All rights reserved.
//

#ifndef GA_h
#define GA_h
#include <random>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <assert.h>

using namespace std;


class GA {
public:
    int pop_size = 10;
    int max_gen = 100;
    double fitness;
    double prob_crossover;
    double prob_mutation;
    void generate(double string_size);
    double generateGaussianNoise();
    double evaluate(vector< vector<int> > pop, double b_size, double num_x, double lower_bound, double x, double funct, bool DeJong_1, bool DeJong_2, bool DeJong_3, bool DeJong_4);
    void selection();
    void crossover_mutate();
    void run(double string_size, double b_size, double num_x, double lower_bound, double x, double funct, bool DeJong_1, bool DeJong_2, bool DeJong_3, bool DeJong_4);
    
    vector<doubles> fit_vector;
    vector<doubles> prob_vector;
    
    bool low;
    bool nom;
    bool high;
    
    vector<int> vec;
    vector< vector<int> > pop, new_pop; //parent
};

void GA::generate(double string_size){
    
    //vector<vector<int>> new_pop; //child
    for(int i = 0; i < pop_size; i++){
        //initialize pop with randomly generated strings of 1's and 0's
        vec.clear();
        for (int j = 0; j < string_size; j++){
            
            vec.push_back(rand() % 2);
            //cout << vec.at(j) << "\t";
        }
        //cout << "I'm done" << endl;
        pop.push_back(vec);
    }
    //cout << "I'm really done" << endl;
}

double GA::generateGaussianNoise() {
    const double epsilon = numeric_limits<double>::min();
    const double two_pi = 2.0*3.14159265358979323846;
    double mu = .5;
    //double mu = (((double)rand() / RAND_MAX) - 0.5) * 2;
    double sigma = 0.5;
    //double sigma = (((double)rand() / RAND_MAX) - 0.5) * 2;
    int n = 0;
    //cout << mu << "," << sigma << endl;
    double z0, z1;
    double u1=0, u2=0;
    
    do{
        //cout << u1 << "," u2 << endl;
        u1 = ((double)rand() / RAND_MAX);
        u2 = ((double)rand() / RAND_MAX);
        //cout << u1 << "," << u2 << endl;
    } while (u1 <= epsilon);
    z0 = sqrt(-2.0 * log(u1)) * cos(two_pi * u2);
    z1 = sqrt(-2.0 * log(u1)) * sin(two_pi * u2);
    //cout << z0 << endl;
    n = z0 * sigma + mu;
    while (n>1 || n<0){
        //cout << "new error loop" << endl;
        double z0, z1;
        double u1=0, u2=0;
        
        do{
            //cout << u1 << "," u2 << endl;
            u1 = ((double)rand() / RAND_MAX);
            u2 = ((double)rand() / RAND_MAX);
            //cout << u1 << "," << u2 << endl;
        } while (u1 <= epsilon);
        z0 = sqrt(-2.0 * log(u1)) * cos(two_pi * u2);
        z1 = sqrt(-2.0 * log(u1)) * sin(two_pi * u2);
        //cout << z0 << endl;
        n = z0 * sigma + mu;
    }
    return n;
}

double GA::evaluate(vector< vector <int> > pop, double b_size, double num_x, double lower_bound, double x, double funct, bool DeJong_1, bool DeJong_2, bool DeJong_3, bool DeJong_4){
    //take decoded individual
    fitness = 0;
    for (int p = 0; p < num_x; p++){ //P comes from main.cpp
        int num = 0;
        for (int i = 0; i < b_size; i++){
            num =+ vec.at(i + p*b_size)*pow(2,i); // decode
            
        }
        //cout << "num" << p << "\t" << num << endl;
        x = lower_bound + num*(b_size/(pow(2,b_size)-1));
        int n = generateGaussianNoise();
        if (DeJong_1 == true){
            funct = pow(x,2);
        }
        else if (DeJong_2 ==true){
            funct = 0; //REALLY DO THIS
        }
        else if (DeJong_3 == true){
            funct = round(x);
        }
        else if (DeJong_4 == true){
            funct = p*pow(x,4) + n;
        }
        fitness =+ funct; //use function to evaluate fitness
        //cout << p << "\tfitness\t" << fitness << endl;
    }
    return fitness;
    
    //if (fitness < min_fitness) { min_fitness = fitness; }
    // if (fitness > max_fitness) {  max_fitness = fitness; }
    // if (fitness
}

void GA::selection(){
    //sum of fitness of the entire population
    
    int sum=0;
    prob_vector.clear();
    for(int f=0; f<fit_vector.size(); f++){
        sum =+ fit_vector.at(f);
    }
    
    for(int i=0; i <  pop_size; i++){
        int prob_chosen = 0;
        prob_chosen = fit_vector.at(i)/sum;
        prob_vector.push_back(prob_chosen);
    }
    // ROULETTE WHEEL //
    
    for (int i = 0; i < pop_size; i++){
        if ( i == 0 ){
            
        }
        if (i > 0){
            
        }
    }
    //return something?
    
    
}

void GA::crossover_mutate(){
    if (low == true) {
        prob_crossover = 0.2;
        prob_mutation = 0.0001;
    }
    
    if (nom == true) {
        prob_crossover = 0.67;
        prob_mutation = 0.001;
    }
    
    if (high == true) {
        prob_crossover = 0.99;
        prob_mutation = 0.01;
    }
    
    // for (int cx=0; cx < bit_size*nun_x*prob_crossover; cx++) { //do cross over }
    // for (int m=0; m < bit_size*num_x*prob_mutation; m++) { //mutate stuff}
    
}



void GA::run(double string_size, double b_size, double num_x, double lower_bound, double x, double funct, bool DeJong_1, bool DeJong_2, bool DeJong_3, bool DeJong_4){
    bool low = true;
    bool nom = false;
    bool high = false;
    generate(string_size);
    for (int g = 0; g < max_gen; g++) {
        for (int p = 0; p < pop_size; p++){
            
            evaluate(pop, b_size, num_x, lower_bound, x, funct, DeJong_1, DeJong_2, DeJong_3, DeJong_4);
            fit_vector.push_back(fitness);
        }
        assert(fit_vector.size() == pop_size);
        //selection
        crossover_mutate();
        pop = new_pop;
    }
}

#endif /* GA_h */
