//
//  EA.hpp
//  Pro-Ant_EA_project
//
//  Created by Sierra Gonzales on 8/21/17.
//  Copyright © 2017 Pro-Ant_EA_project. All rights reserved.
//

#ifndef EA_hpp
#define EA_hpp

#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <time.h>
#include <stdio.h>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <ctime>
#include <random>
using namespace std;



class EA
{
    friend class Parameters;
    friend class Policy;
    friend class city;
    
    
protected:
    
    
public:
    Parameters* pP;
    
    vector<Policy> pol;
    vector<double> best_fitness;
    
    void Build_Population();
    void Run_Simulation();
    void Evaluate();
    int Binary_Select();
    void Downselect();
    void Mutation(Policy &M);
    void Repopulate();
    struct Less_Than_Policy_Fitness;
    void Sort_Policies_By_Fitness();
    void EA_Process();
    void Run_Program();
    void Graph();
    
    int lines;
    string file;
    
    //int num_weights = 5;
    
private:
};


//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//////////////////////////////////////////////////////////////////////////////
//Builds population of policies
void EA::Build_Population()
{
    Policy pro; //instance of a tour
    pol.push_back(pro);
    pol.at(0).age = 0;
    pol.at(0).Total_fitness = 0;
    
    file = "berlin52.tsp";
    pP->num_city = 52+1;
    
    string s1;
    ifstream data(file);
    //insert if statement
    if (file == "burma14.tsp"){
        lines = 8;
    }
    else {
        lines = 6;
    }
    
    
    
    for (int c=0; c<pP->num_city; c++) {
        city C;
        pol.at(0).town.push_back(C);
    }

    
    for (int i=0; i < lines; i++){ //change line from 6 to 8 for BERMA
        getline(data,s1);
        //cout << s1 << endl;
    }
    
    //for that policy have a vector of weights || for that tour have a vector of cities
    for (int w=0; w < pP->num_city-1; w++){
        
        data >> pol.at(0).town.at(w).origin;
        data >> pol.at(0).town.at(w).x;
        data >> pol.at(0).town.at(w).y;
        
    }
    //LAST CITY EQUALS FIRST CITY
    pol.at(0).town.at(pP->num_city-1).origin = pol.at(0).town.at(0).origin;
    pol.at(0).town.at(pP->num_city-1).x = pol.at(0).town.at(0).x;
    pol.at(0).town.at(pP->num_city-1).y = pol.at(0).town.at(0).y;
    
    
    // SET UP THE REST OF THE POLICIES
    for (int i=1; i<pP->num_pol; i++) {
        pol.push_back(pol.at(0));
        
    }
    
    for (int i = 0; i < pP->num_pol; i++){
        random_shuffle(pol.at(i).town.begin()+1,pol.at(i).town.end()-1);
        assert(pol.at(i).town.at(0).origin == 1);
        assert(pol.at(i).town.at(pP->num_city-1).origin == 1);
    }
    
    
    assert(pol.size() == pP->num_pol); // check to make sure that the policy sizes are the same
}





//////////////////////////////////////////////////////////////////////////////
//Evaluates each policies fitness scores for each objective
void EA::Evaluate()
{
    //might not need
    for (int i=0; i< pP->num_pol; i++) {
        double fitness = 0;
        for (int j=1; j<pP->num_city; j++){
            double xd = pol.at(i).town.at(j-1).x - pol.at(i).town.at(j).x;
            double yd = pol.at(i).town.at(j-1).y - pol.at(i).town.at(j).y;
            double dxy = round(sqrt(xd*xd + yd*yd));
            fitness += dxy;
        }
        pol.at(i).Total_fitness = fitness;
    }
}


//////////////////////////////////////////////////////////////////////////////
//Randomly selects two tours and decides which one will die based on their fitness
int EA::Binary_Select() //BINARY TOURNAMENT
{
    int loser;
    int index_1 = rand() % pol.size();
    int index_2 = rand() % pol.size();
    while (index_1 == index_2)
    {
        index_2 = rand() % pol.size();
    }
    
    //winner is one with lower fitness
    if(pol.at(index_1).Total_fitness < pol.at(index_2).Total_fitness)
    {
        loser = index_2;
        //cout << "loser" << "\t" <<  "agent" << "\t" << index_2 << endl;
    }
    else
    {
        loser = index_1;
        //cout << "loser" << "\t" <<  "agent" << "\t" << index_1 << endl;
    }
    return loser;
}




//-------------------------------------------------------------------------
//Policies are compared to determine the optimal policies for a given generation
void EA::Downselect()
{
    int pro_kill;

    for(int k=0; k<pP->to_kill; k++)
    {
        pro_kill = Binary_Select();               //Protagonist
        pol.erase(pol.begin() + pro_kill);
    }
    assert(pol.size() == pP->to_kill);

    for(int i=0; i<pP->to_kill; i++)
    {
        pol.at(i).age += 1;
    }
}


//-------------------------------------------------------------------------
//Mutates the copies of the winning individuals
void EA::Mutation(Policy &M)
{
    //This is where the policy is slightly mutated
    //MANIPULATE CITY ORDER
    //int rand1 = rand() % (pP->num_city-2);
    double rand2 = (double)rand()/RAND_MAX;
    
    if (rand2 < 0.5){
        int rand1 =1;
        for (int x = 0; x < rand1; x++) {
            int random = 1 + rand() % (pP->num_city-2); //choose 2 random spots
            int random2 = 1 + rand() %(pP->num_city-2);
            //cout << "\t" << M.town.at(random).origin << "\t" << M.town.at(random2).origin << endl;
            swap(M.town.at(random),M.town.at(random2));
            //cout << "\t" << M.town.at(random).origin << "\t" << M.town.at(random2).origin << endl;
            assert(M.town.at(0).origin == 1);
            assert(M.town.at(pP->num_city-1).origin == 1);
            
        }
    }
}


//-------------------------------------------------------------------------
//The population is repopulated based on small mutations of the remaining policies
void EA::Repopulate()
{
    int to_replicate = pP->to_kill;
    for (int rep=0; rep<to_replicate; rep++) {
        Policy M;
        int spot = rand() % pol.size();
        M = pol.at(spot);
        //cout << "cp" << endl;
        Mutation(M);
        pol.push_back(M);
        pol.at(pol.size()-1).age = 0; //how long it has survived
    }
    assert(pol.size() == pP->num_pol);
}


//-------------------------------------------------------------------------
//Runs the entire EA loop process
void EA::EA_Process() {
    Evaluate();
    Sort_Policies_By_Fitness();
    //cout << "BEST POLICY PRO-FITNESS" << "\t" << pol.at(0).Total_fitness << endl;
    best_fitness.push_back(pol.at(0).Total_fitness);
    Downselect();
    Repopulate();
}


//-------------------------------------------------------------------------
//Sorts the population based on their fitness from lowest to highest
struct EA::Less_Than_Policy_Fitness
{
    inline bool operator() (const Policy& struct1, const Policy& struct2)
    {
        return (struct1.Total_fitness < struct2.Total_fitness);
    }
};



//-------------------------------------------------------------------------
//Sorts population
void EA::Sort_Policies_By_Fitness()
{
    for (int i=0; i<pP->num_pol; i++)
    {
        sort(pol.begin(), pol.end(), Less_Than_Policy_Fitness());
        
    }

}
//-------------------------------------------------------------------------
void EA::Graph(){
    ofstream fout;
    
    fout.open("x_history.txt", std::ofstream::out | ofstream::trunc);
    //fout << "vector spot" << "\t" << "x" << "\t" << "x_dot" << "\t" << "x_dd" << endl;
    for (int f =0; f < pP->total_time; f++){
        fout << pol.at(0).x_history.at(f) << "\t";
    }
    fout.close();
    
    fout.open("y_history.txt", std::ofstream::out | ofstream::trunc);
    //fout << "vector spot" << "\t" << "x" << "\t" << "x_dot" << "\t" << "x_dd" << endl;
    for (int f =0; f < pP->total_time; f++){
        fout << pol.at(0).y_history.at(f) << "\t";
    }
    fout.close();

    fout.open("P_best_fitness_history.txt",std::ofstream::out | ofstream::trunc);
    for (int h =0; h < pP->gen_max; h++){
        fout << best_fitness.at(h) << "\t";
    }
    fout.close();

    
}


//-------------------------------------------------------------------------
//Runs the entire program
void EA::Run_Program()
{
    
    
    ofstream rand_start;
    rand_start.open("random_starting_variables.txt", ofstream::out | ofstream::trunc);
    
    Build_Population(); //Builds all tours of cities with coordinates
    for (int gen=0; gen<pP->gen_max; gen++) {
        
        if (gen %10 ==0) {
            cout << "GENERATION \t" << gen << endl;
        }
        if (gen < pP->gen_max-1) {
            EA_Process();
        }
        else {
            
            Evaluate();
            Sort_Policies_By_Fitness();
            cout << "BEST POLICY PRO-FITNESS" << "\t" << pol.at(0).Total_fitness << endl;
            cout << "BEST PATH" << endl;
            for (int c=0; c< pP->num_city; c++)
            {
                cout << pol.at(0).town.at(c).origin << "\t";
            }
            cout << endl;
            best_fitness.push_back(pol.at(0).Total_fitness);      // best fitness per generation
            
        }
        
        
    }
    
    //Graph();
    rand_start.close();
}


#endif /* EA_hpp */
