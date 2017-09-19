// Sierra Gonzales
// sierrag@nevada.unr.edu
// CS776 - HW2

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <numeric>
#include <random>
#include <cstdlib>
#include <assert.h>


using namespace std;

double eval(int *pj);
//int array_size = 150;

int main() {
	ofstream fout;
	fout.open("CPP1_best_vector.txt", std::ofstream::out | ofstream::trunc);
	ofstream newout;
	newout.open("CPP1_stat_statistics.txt", std::ofstream::out | ofstream::trunc);

	for (int stat_run = 0; stat_run<10; stat_run++){

		srand(time(NULL));

		int vec[150]; //initialize array

		int i;

		double fitness; //ever changing fitness

		double best_fitness = 0; //keeps track of best fitness

		for (int i=0; i<150; i++) { // initializes units in array to zero

			vec[i] = 0;

		}

		fitness = eval(vec); // initial fitness

		if (fitness > best_fitness){ 
			best_fitness = fitness;
		}

		newout << fitness << "\t";
		
		// CLIMB. THAT. HILL.
		
		for (int j=0; j<150; j++) {
			vec[j] =1; //lets try this
			fitness = eval(vec);
			if (fitness >= best_fitness){ 
				best_fitness = fitness; //always update the best fitness
			}
			else {
				vec[j] = 0; //change it back
			}
			newout << fitness << "\t";
		}
		
		for (int j=0; j<100000; j++) {
			int r;
			int s;
			for (int x = 0; x < rand()%1000; x++) {
				r = rand() % 150; //pick 2 random spots in the array
				s = rand() % 150;
				while (r == s) {
					s = rand() %150;
				}
				// flip those 2 spots in the array
		
				if (vec[r] == 0) {
					vec[r]=1;
				}
				else{
					vec[r] = 0;
				}
				if (vec[s] == 0) {
					vec[s]=1;
				}
				else{
					vec[s] = 0;
				}
			}

			//evaluate fitness
			fitness = eval(vec);
			newout <<  fitness << "\t";
			// if fitness is > OR equal to the last fitness, keep changes
			if (fitness >= best_fitness){ 
				best_fitness = fitness; 
			}
			else {
				if (vec[r] == 0) {
					vec[r]=1;
				}
				else{
					vec[r] = 0;
				}
				if (vec[s] == 0) {
					vec[s]=1;
				}
				else{
					vec[s] = 0;
				}
			}	
			newout <<  fitness << "\t";
		}
		newout << endl;
		newout << endl;
		cout << "best_fitness = " << best_fitness << endl;
	
		for (int f =0; f < 150; f++){
        		fout << vec[f] << "\t";
    		}
		fout << endl;
		fout << endl;
	}
	fout.close();
	newout.close();

return 0;
}

