// Sierra Gonzales
// sierrag@nevada.unr.edu
// CS776 - HW0-1-1
// Black Box Opt. part 1

#include <iostream>
#include <random>
#include <cstdlib>
#include <assert.h>

using namespace std;

double eval(int *pj);

int main() {

	int vec[100]; //initialize array

	int i;

	double fitness; //ever changing fitness

	double best_fitness = 0; //keeps track of best fitness

	for (i=0; i<100; i++) { // initializes units in array to zero

		vec[i] = 0;

	}

	fitness = eval(vec); // initial fitness

	if (fitness > best_fitness){ 
		best_fitness = fitness;
	}

	
	// CLIMB. THAT. HILL.
	for (int j=0; j<100; j++) {
		vec[j] =1; //lets try this
		fitness = eval(vec);
		if (fitness > best_fitness){ 
			best_fitness = fitness; //always update the best fitness
		}
		else {
			vec[j] = 0; //change it back
		}
	cout << "fitness = " << fitness << endl;
	}
	//Optimize for Chocolate //Didn't work as of 11:15 8/31
	for (int j=0; j<100; j++) {
		if (vec[j] = 1) {
		}
		else {
			vec[j] =1; //lets try this again in combo with our last result
			fitness = eval(vec);
			if (fitness > best_fitness){ 
				best_fitness = fitness; //always update the best fitness
			}
			else {
				vec[j] = 0; //change it back
			}
		}
		
		
	cout << "fitness = " << fitness << endl;
	}

	cout << "best_fitness = " << best_fitness << endl;

}

