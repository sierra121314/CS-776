//
//  GA.h
//  CS776_HW3
//
//  Created by Sierra Gonzales on 9/21/17.
//  Copyright © 2017 Sierra Gonzales. All rights reserved.
//

#ifndef GA_h
#define GA_h

bool low;
bool nom;
bool high;

if (low == true) {
    double prob_crossover = 0.2;
    double prob_mutation = 0.0001;
}

if (nom == true) {
    double prob_crossover = 0.67;
    double prob_mutation = 0.001;
}

if (high == true) {
    double prob_crossover = 0.99;
    double prob_mutation = 0.01;
}

class GA {
    int pop_size;
    int max_gen;
    void generate();
    void evaluate();
    void mutate();
    void crossover();
    void run();
};

void GA:generate(){
    for(i = 0; i<pop_size; i++){
        //initialize pop with randomly generated strings of 1's and 0's
    }
}

void GA:evaluate(){
    //take decoded individual
    //give fitness
    //if (fitness < min_fitness) { min_fitness = fitness; }
    // if (fitness > max_fitness) {  max_fitness = fitness; }
    // if (fitness
}

void GA::mutate(){
    
}

void GA::crossover() {
    
}

void GA::run(){
    generate();
    evaluate();
    for (int t=0; t < max_gen; t++){
        //selection
        crossover();
        mutate();
    }
}

#endif /* GA_h */
