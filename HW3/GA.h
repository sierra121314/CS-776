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
#include <algorithm>
#include <stdlib.h>
#include <fstream>

using namespace std;


class GA {
public:
    int pop_size = 60;
    int max_gen = 80;
    double fitness;
    double parent_1;
    double parent_2;
    double child_1;
    double child_2;
    double prob_crossover =0;
    double prob_mutation =0;
    double sum;
    void generate(double string_size);
    void init_fit_vec();
    double generateGaussianNoise();
    double evaluate(int p, double b_size, double num_x, double lower_bound, double funct, bool DeJong_1, bool DeJong_2, bool DeJong_3, bool DeJong_4);
    void selection();
    void crossover_mutate(double bit_size, double num_x, bool low, bool nom, bool high);
    void run(double string_size, double b_size, double num_x, double lower_bound, double funct, bool DeJong_1, bool DeJong_2, bool DeJong_3, bool DeJong_4, bool low, bool nom, bool high);
    
    vector<double> fit_vector;
    vector<double> prob_vector;
    vector<double> prob_range;
    
    
    
    vector<int> vec;
    vector< vector<int> > pop, new_pop; //parent
};

void GA::init_fit_vec(){
    for(int i =0; i<pop_size; i++){
        fit_vector.push_back(0);
        
    }
    //cout << "size" << fit_vector.size() << endl;
}


void GA::generate(double string_size){
    
    //vector<vector<int>> new_pop; //child
    for(int i = 0; i < pop_size; i++){
        //initialize pop with randomly generated strings of 1's and 0's
        vec.clear();
        for (int j = 0; j < string_size; j++){
            
            vec.push_back(rand() % 2);
            //cout << vec.at(j) << "\t";
        }
        assert(vec.size() == string_size);
        //cout << "I'm done" << endl;
        pop.push_back(vec); //a population has a set of arrays of 0s and 1s
    }
    new_pop=pop;
    //cout << "new_pop.at(0).at(0)\t" << new_pop.at(0).at(0) << endl;

}

double GA::generateGaussianNoise() {
    //https://en.wikipedia.org/wiki/Box–Muller_transform
    const double epsilon = numeric_limits<double>::min();
    const double two_pi = 2.0*3.14159265358979323846;
    double mu = 0;
    //double mu = (((double)rand() / RAND_MAX) - 0.5) * 2;
    double sigma = 1;
    //double sigma = (((double)rand() / RAND_MAX) - 0.5) * 2;
    double n = 0;
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
    while (n>1 || n<-1){
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

double GA::evaluate(int p, double b_size, double num_x, double lower_bound, double funct, bool DeJong_1, bool DeJong_2, bool DeJong_3, bool DeJong_4){
    //take decoded individual
    fitness = 0;
    double x;
    for (int t = 0; t < num_x; t++){ //P comes from main.cpp
        double num = 0;
        for (int i = 0; i < b_size; i++){
            num += pop.at(p).at(i + t*b_size)*pow(2,i); // decode
            
        }
        //cout << "num" << p << "\t" << num << endl;
        
        //cout << "x\t" << x << endl;
        double n = generateGaussianNoise();
        if (DeJong_1 == true){
            //cout << "lower\t" << lower_bound << endl;
            //cout << "bsize\t" << b_size << endl;
            x = lower_bound + num*(b_size/(pow(2,b_size)-1));
            //cout << "x\t" << x << endl;
            funct = pow(x,2);
            //cout << "funct\t" << funct << endl;
        }
        else if (DeJong_2 ==true){
            double x1 = lower_bound + num*(b_size/(pow(2,b_size)-1));
            
            double num1=0;
            for (int i = 0; i < b_size; i++){
                num1 += vec.at(i + (t+1)*b_size)*pow(2,i); // decode
                
            }
            int x2 = lower_bound + num1*(b_size/(pow(2,b_size))-1);
            //cout << "x1\t" << x1 << "\t" << "x2\t" << x2 << endl;
            funct = 100*pow(pow(x1,2)-x2,2)+pow(1-x1,2);
            fitness = funct;
            break;
        }
        else if (DeJong_3 == true){
            x = lower_bound + num*(b_size/(pow(2,b_size))-1);
            funct = round(x);
        }
        else if (DeJong_4 == true){
            x = lower_bound + num*(b_size/(pow(2,b_size))-1);
            //cout << "x\t" << x << endl;
            funct = abs(p*pow(x,4)) + n;
            //cout << "funct\t" << funct << endl;
        }
        
        fitness += funct; //use function to evaluate fitness
        //cout << p << "\tfitness\t" << fitness << endl;
    }
    //cout << "total_pop_fitness\t" << fitness << endl;
    return fitness;
    
    //if (fitness < min_fitness) { min_fitness = fitness; }
    // if (fitness > max_fitness) {  max_fitness = fitness; }
    // if (fitness
}

void GA::selection(){
    //sum of fitness of the entire population
    
    sum=0;
    prob_vector.clear();
    prob_range.clear();
    for(int f=0; f<pop_size; f++){
        sum += fit_vector.at(f);
        //assert(fit_vector.at(f)>=0);
        assert(sum>=0);
        //cout << "sum\t" << sum << endl;
    }
    
    for(int i=0; i <  pop_size; i++){
        double prob_chosen = 0;
        //cout << "fit_vector\t" << fit_vector.at(i) << endl;
        //cout << "sum\t" << sum << endl;
        prob_chosen = fit_vector.at(i)/sum;
        
        //cout << prob_chosen << endl;
        prob_vector.push_back(prob_chosen);
        
    }
    // ROULETTE WHEEL //
    
    for (int i = 0; i < pop_size; i++){
        if ( i == 0 ) {
            prob_range.push_back(prob_vector.at(0)); //1st prob chosen
        }
        if (i > 0) {
            prob_range.push_back(prob_vector.at(i) + prob_range.at(i-1));
        }
        
    }
    
    //SELECT PARENTS
    // PARENT 1 //
    double r1 = (double)rand()/RAND_MAX;
    //cout << "r1\t" << r1 << endl;
    for (int p=0; p<pop_size; p++){
        //cout << "prob_range@p" << prob_range.at(p) << endl;
        if(p == 0){
            if( 0 <= r1 && r1 < prob_range.at(p)) {
                parent_1 = p;
                //cout << "parent_1\t" << parent_1 << endl;
                break;
            }
        }
        if(p>0){
            if(prob_range.at(p-1) <= r1 && r1 < prob_range.at(p)){
                parent_1 = p;
                //cout << "parent_1\t" << parent_1 << endl;
                break;
            }
        }
    }
    //cout << "P1\t";
    for ( int q=0; q<vec.size();q++){
        
        //cout << pop.at(parent_1).at(q);
    }
    //cout << endl;
    // PARENT 2 //
    double r2 = (double) rand()/RAND_MAX;
    for (int p=0; p<pop_size; p++){
        if(p==0){
            if( 0 <= r2 && r2 < prob_range.at(p)) {
                parent_2 = p;
                //out << "parent_2\t" << parent_2 << endl;
                break;
            }
        }
        if(p>0){
            if(prob_range.at(p-1) <= r2 && r2 < prob_range.at(p)){
                parent_2 = p;
                //cout << "parent_2\t" << parent_2 << endl;
                break;
            }
        }
    }
    //cout << "P2\t";
    for ( int q=0; q<vec.size();q++){
        
        //cout << pop.at(parent_2).at(q);
    }
    //cout << endl;
}

void GA::crossover_mutate(double b_size, double num_x, bool low, bool nom, bool high){
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
    
    
    for (int cx=0; cx < pop_size/2; cx++) {
        //cout << "made it to cross over funct i.e. selection" <<endl;
        //cout << prob_crossover << "\t" << prob_mutation << endl;
        selection();
        //cout << "parent_1\t" << parent_1 << "\t" << "parent_2\t" << parent_2 << endl << endl;
        double r = (double)rand()/RAND_MAX;
        //cout << "r\t" << r << endl;
        
        //  TO CROSSOVER OR NOT TO CROSS OVER //
        if(r <= prob_crossover){
            //do cross over
            //choose cx pt
            int cross_spot = 1+ rand() % vec.size()-1; //CORRECT?
            //cout << "cross spot\t" << cross_spot << endl;
            assert(cross_spot<b_size*num_x);
            //cout << "win" << endl;
            /*
            cout << "before" <<endl;
            cout << "P1\t";
            for ( int q=0; q<vec.size();q++){
                
                cout << pop.at(parent_1).at(q);
            }
            cout << endl;
            cout << "P2\t";
            for ( int q=0; q<vec.size();q++){
                
                cout << pop.at(parent_2).at(q);
            }
            cout << endl;
            */
            for (int p = 0;  p<cross_spot; p++){
                //first half swap
                new_pop.at(2*cx).at(p) = pop.at(parent_1).at(p);
                new_pop.at(2*cx+1).at(p) = pop.at(parent_2).at(p);
            }
            
            for (int v=cross_spot; v<vec.size(); v++){
                //second half swap
                new_pop.at(2*cx).at(v) = pop.at(parent_2).at(v);
                new_pop.at(2*cx+1).at(v) = pop.at(parent_1).at(v);
            }
            
            /*
            cout << "after swap" <<endl;
            cout << "P1\t";
            for ( int q=0; q<vec.size();q++){
                cout << new_pop.at(2*cx).at(q);
            }
            cout << endl;
            cout << "P2\t";
            for ( int q=0; q<vec.size();q++){
                
                cout << new_pop.at(2*cx+1).at(q);
            }
            cout << endl << endl;
            */
            
        }
        if(r > prob_crossover){
            //cout << "new_pop\t" << &new_pop.at(2*cx) << endl;
            new_pop.at(2*cx) = pop.at(parent_1); //child_1
            new_pop.at(2*cx+1) = pop.at(parent_2); //child_1
        }
    }
    pop = new_pop;
    // MUTATE //
    for (int m=0; m < pop_size; m++) {
        //mutate stuff
        int r = (double)rand()/RAND_MAX;
        
        if(r <= prob_mutation){
            //flip the bit
            int r1 = rand() % vec.size();
            if (pop.at(m).at(r1) == 1){
                pop.at(m).at(r1)=0;
            }
            if (pop.at(m).at(r1)==0){
                pop.at(m).at(r1)=1;
            }
        }
        
    }
    
}



void GA::run(double string_size, double b_size, double num_x, double lower_bound, double funct, bool DeJong_1, bool DeJong_2, bool DeJong_3, bool DeJong_4, bool low, bool nom, bool high){
    
    ofstream f1out_low_min;
    ofstream f1out_low_max;
    ofstream f1out_low_ave;
    ofstream f1out_high_min;
    ofstream f1out_high_max;
    ofstream f1out_high_ave;
    ofstream f1out_nom_min;
    ofstream f1out_nom_max;
    ofstream f1out_nom_ave;
    // DEJONG 2 //
    ofstream f2out_low_min;
    ofstream f2out_low_max;
    ofstream f2out_low_ave;
    ofstream f2out_high_min;
    ofstream f2out_high_max;
    ofstream f2out_high_ave;
    ofstream f2out_nom_min;
    ofstream f2out_nom_max;
    ofstream f2out_nom_ave;
    //DEJONG 3//
    ofstream f3out_low_min;
    ofstream f3out_low_max;
    ofstream f3out_low_ave;
    ofstream f3out_high_min;
    ofstream f3out_high_max;
    ofstream f3out_high_ave;
    ofstream f3out_nom_min;
    ofstream f3out_nom_max;
    ofstream f3out_nom_ave;
    //DEJONG 4//
    ofstream f4out_low_min;
    ofstream f4out_low_max;
    ofstream f4out_low_ave;
    ofstream f4out_high_min;
    ofstream f4out_high_max;
    ofstream f4out_high_ave;
    ofstream f4out_nom_min;
    ofstream f4out_nom_max;
    ofstream f4out_nom_ave;
    
    if (DeJong_1 ==true && low ==true){
        f1out_low_min.open("F1-low-min.txt", fstream::app);
        f1out_low_max.open("F1-low-max.txt", fstream::app);
        f1out_low_ave.open("F1-low-ave.txt", fstream::app);
    }
    if (DeJong_1 ==true && high==true){
        f1out_high_min.open("F1-high-min.txt", fstream::app);
        f1out_high_max.open("F1-high-max.txt", fstream::app);
        f1out_high_ave.open("F1-high-ave.txt", fstream::app);
    }
    if (DeJong_1 ==true && nom==true){
        f1out_nom_min.open("F1-nom-min.txt", fstream::app);
        f1out_nom_max.open("F1-nom-max.txt", fstream::app);
        f1out_nom_ave.open("F1-nom-ave.txt", fstream::app);
    }
    //DEJONG 2//
    if (DeJong_2 ==true && low ==true){
        f2out_low_min.open("F2-low-min.txt", fstream::app);
        f2out_low_max.open("F2-low-max.txt", fstream::app);
        f2out_low_ave.open("F2-low-ave.txt", fstream::app);
    }
    if (DeJong_2 ==true && high==true){
        f2out_high_min.open("F2-high-min.txt", fstream::app);
        f2out_high_max.open("F2-high-max.txt", fstream::app);
        f2out_high_ave.open("F2-high-ave.txt", fstream::app);
    }
    if (DeJong_2 ==true && nom==true){
        f2out_nom_min.open("F2-nom-min.txt", fstream::app);
        f2out_nom_max.open("F2-nom-max.txt", fstream::app);
        f2out_nom_ave.open("F2-nom-ave.txt", fstream::app);
    }
    //DEJONG 3//
    if (DeJong_3 ==true && low ==true){
        f3out_low_min.open("F3-low-min.txt", fstream::app);
        f3out_low_max.open("F3-low-max.txt", fstream::app);
        f3out_low_ave.open("F3-low-ave.txt", fstream::app);
    }
    if (DeJong_3 ==true && high==true){
        f3out_high_min.open("F3-high-min.txt", fstream::app);
        f3out_high_max.open("F3-high-max.txt", fstream::app);
        f3out_high_ave.open("F3-high-ave.txt", fstream::app);
    }
    if (DeJong_3 ==true && nom==true){
        f3out_nom_min.open("F3-nom-min.txt", fstream::app);
        f3out_nom_max.open("F3-nom-max.txt", fstream::app);
        f3out_nom_ave.open("F3-nom-ave.txt", fstream::app);
    }
    //DEJONG 4//
    if (DeJong_4 ==true && low ==true){
        f4out_low_min.open("F4-low-min.txt", fstream::app);
        f4out_low_max.open("F4-low-max.txt", fstream::app);
        f4out_low_ave.open("F4-low-ave.txt", fstream::app);
    }
    if (DeJong_4 ==true && high==true){
        f4out_high_min.open("F4-high-min.txt", fstream::app);
        f4out_high_max.open("F4-high-max.txt", fstream::app);
        f4out_high_ave.open("F4-high-ave.txt", fstream::app);
    }
    if (DeJong_4 ==true && nom==true){
        f4out_nom_min.open("F4-nom-min.txt", fstream::app);
        f4out_nom_max.open("F4-nom-max.txt", fstream::app);
        f4out_nom_ave.open("F4-nom-ave.txt", fstream::app);
    }
    
    generate(string_size);
    init_fit_vec();
    for (int g = 0; g < max_gen; g++) {
        
        //cout << "generation\t" << g << endl;
        for (int p = 0; p < pop_size; p++){
            
            evaluate(p, b_size, num_x, lower_bound,  funct, DeJong_1, DeJong_2, DeJong_3, DeJong_4);
            //assert(fitness>=0);
            //cout << "fit before\t" << fitness << endl;
            fit_vector.at(p) = abs(fitness);
            //cout << "fit_vector\t" << fit_vector.at(p) << endl;
        }
        double min = *min_element(fit_vector.begin(), fit_vector.end());
        double max = *max_element(fit_vector.begin(), fit_vector.end());
        double ave = sum/pop_size;
        
        // DEJONG 1 //
        if (DeJong_1 ==true && low ==true){
            f1out_low_min << min << "\t";
            f1out_low_max << max << "\t";
            f1out_low_ave << ave << "\t";
        }
        if (DeJong_1 ==true && high ==true){
            f1out_high_min << min << "\t";
            f1out_high_max << max << "\t";
            f1out_high_ave << ave << "\t";
        }
        if (DeJong_1 ==true && nom ==true){
            f1out_nom_min << min << "\t";
            f1out_nom_max << max << "\t";
            f1out_nom_ave << ave << "\t";
        }
        //DEJONG 2//
        if (DeJong_2 ==true && low ==true){
            f2out_low_min << min << "\t";
            f2out_low_max << max << "\t";
            f2out_low_ave << ave << "\t";
        }
        if (DeJong_2 ==true && high ==true){
            f2out_high_min << min << "\t";
            f2out_high_max << max << "\t";
            f2out_high_ave << ave << "\t";
        }
        if (DeJong_2 ==true && nom ==true){
            f2out_nom_min << min << "\t";
            f2out_nom_max << max << "\t";
            f2out_nom_ave << ave << "\t";
        }
        //DEJONG 3//
        if (DeJong_3 ==true && low ==true){
            f3out_low_min << min << "\t";
            f3out_low_max << max << "\t";
            f3out_low_ave << ave << "\t";
        }
        if (DeJong_3 ==true && high ==true){
            f3out_high_min << min << "\t";
            f3out_high_max << max << "\t";
            f3out_high_ave << ave << "\t";
        }
        if (DeJong_3 ==true && nom ==true){
            f3out_nom_min << min << "\t";
            f3out_nom_max << max << "\t";
            f3out_nom_ave << ave << "\t";
        }
        //DEJONG 4//
        if (DeJong_4 ==true && low ==true){
            f4out_low_min << min << "\t";
            f4out_low_max << max << "\t";
            f4out_low_ave << ave << "\t";
        }
        if (DeJong_4 ==true && high ==true){
            f4out_high_min << min << "\t";
            f4out_high_max << max << "\t";
            f4out_high_ave << ave << "\t";
        }
        if (DeJong_4 ==true && nom ==true){
            f4out_nom_min << min << "\t";
            f4out_nom_max << max << "\t";
            f4out_nom_ave << ave << "\t";
        }
    
        //cout << "size after evaluating all policies\t" << fit_vector.size() << endl;
        assert(fit_vector.size() == pop_size);
        crossover_mutate(b_size, num_x, low, nom, high); //selection happens in here too
        
        if(g==max_gen-1){
            fit_vector.clear();
            pop.clear();
            new_pop.clear();
            prob_range.clear();
            prob_vector.clear();
            if (DeJong_1 ==true && low ==true){
                f1out_low_min << endl;
                f1out_low_max << endl;
                f1out_low_ave << endl;
            }
            if (DeJong_1 ==true && high ==true){
                f1out_high_min << endl;
                f1out_high_max << endl;
                f1out_high_ave << endl;
            }
            if (DeJong_1 ==true && nom ==true){
                f1out_nom_min << endl;
                f1out_nom_max << endl;
                f1out_nom_ave << endl;
            }
            //DEJONG 2//
            if (DeJong_2 ==true && low ==true){
                f2out_low_min << endl;
                f2out_low_max << endl;
                f2out_low_ave << endl;
            }
            if (DeJong_2 ==true && high ==true){
                f2out_high_min << endl;
                f2out_high_max << endl;
                f2out_high_ave << endl;
            }
            if (DeJong_2 ==true && nom ==true){
                f2out_nom_min << endl;
                f2out_nom_max << endl;
                f2out_nom_ave << endl;
            }
            //DEJONG 3//
            if (DeJong_3 ==true && low ==true){
                f3out_low_min << endl;
                f3out_low_max << endl;
                f3out_low_ave << endl;
            }
            if (DeJong_3 ==true && high ==true){
                f3out_high_min << endl;
                f3out_high_max << endl;
                f3out_high_ave << endl;
            }
            if (DeJong_3 ==true && nom ==true){
                f3out_nom_min << endl;
                f3out_nom_max << endl;
                f3out_nom_ave << endl;
            }
            //DEJONG 4//
            if (DeJong_4 ==true && low ==true){
                f4out_low_min << endl;
                f4out_low_max << endl;
                f4out_low_ave << endl;
            }
            if (DeJong_4 ==true && high ==true){
                f4out_high_min << endl;
                f4out_high_max << endl;
                f4out_high_ave << endl;
            }
            if (DeJong_4 ==true && nom ==true){
                f4out_nom_min << endl;
                f4out_nom_max << endl;
                f4out_nom_ave << endl;
            }
        }
    }
    
}

#endif /* GA_h */
