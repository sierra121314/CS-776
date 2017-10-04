//
//  Parameters.hpp
//  Pro-Ant_EA_project
//
//  Created by Sierra Gonzales on 8/21/17.
//  Copyright © 2017 Pro-Ant_EA_project. All rights reserved.
//

#ifndef Parameters_hpp
#define Parameters_hpp

#include <stdio.h>

using namespace std;


class Parameters
{
    friend class EA;
    friend class Simulator;
    friend class Policy;
    
protected:
    
    
public:
    int num_pol = 100;                  //number of policies
    int to_kill = num_pol/2;
    int gen_max = 1000;                  //number of generations
    double total_time = 500;            //total time
    int num_city;             //number of cities in file

    
    // RANDOMIZING STARTS //
    bool rand_start_gen = true;
    void random_variables();
    
    double P_force;     //Protagonist force
    

    
    
private:
};

void Parameters::random_variables(){
    
    if (rand_start_gen == true){
        //double r = rand() %num_city;
        //pol.x = city.at(r);
        //pol.y = city.at(r);
    }
}





#endif /* Parameters_hpp */
