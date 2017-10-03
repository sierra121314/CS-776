//
//  Policy.hpp
//  Pro-Ant_EA_project
//
//  Created by Sierra Gonzales on 8/21/17.
//  Copyright © 2017 Pro-Ant_EA_project. All rights reserved.
//

#ifndef Policy_hpp
#define Policy_hpp

#include <stdio.h>

using namespace std;


class Policy
{
    friend class EA;
    friend class Parameters;
    friend class Simulator;
    friend class city;
    
protected:
    
    
public:
    Parameters* pP;
    //Include all needed information about any policy here
    vector<double> x_history;
    vector<double> y_history;
    vector<double> city_history;
    vector<city> town;
    //...
    double Total_fitness;
    int age; //how long did it last?
    
    void Init_policy(int num_city); //initializes one policy
    
    
private:
};

/*
void Policy::Init_policy(int num_city) { //where does this get called?
    for (int p = 0; p < num_city; p++) {
        //cout << "Order " << p << endl;
        town.push_back(0);
        
    }
    
}
*/
#endif /* Policy_hpp */
