// Sierra Gonzales
// sierrag@nevada.unr.edu
// CS766 - HW0-0
// 9/11/2017
// MISSIONARIES & CANNIBALS

#include <vector>
#include <queue>
#include <iostream>
#include <cstdlib>

using namespace std;

// No more than 2 in the boat at a time
int MAX_BOAT = 2;

struct GameState {

	int canni_L;
	int missi_L;
	int canni_R;
	int missi_R;

	bool rule_check();
	bool solution_check();
	bool Boat_L = true;
	void print();
	bool history_check(vector<GameState> h);
	bool operator==(const GameState& other);//to tell compiler how to compare the Gamespaces
	bool operator!=(const GameState& other);
};


GameState GenerateChildren(GameState p, int num_missi, int num_canni){

	GameState child = p;

	if(child.Boat_L = true) {
		child.Boat_L = false;
		for(int i = 0; i < num_missi; i++) { 
			child.missi_L--;
			child.missi_R++;
		}
		for(int j = 0; j < num_canni; j++){
			child.canni_L--;
			child.canni_R++;
		}

	}
	else { //do reverse
		child.Boat_L = true;
		for(int i = 0; i < num_missi; i++) { 
			child.missi_L++;
			child.missi_R--;
		}
		for(int j = 0; j < num_canni; j++){
			child.canni_L++;
			child.canni_R--;
		}		
	}	
	
	if (child.missi_R <0 || child.missi_L<0 || child.canni_R<0 || child.canni_L <0 || num_missi > MAX_BOAT || num_canni > MAX_BOAT || num_missi <0 || num_canni<0) {
		return p;
	}
	else {
		return child;
	}

}

void GameState::print() {
	cout << "Cannibals on Right: \t" << canni_R << endl;
	cout << "Cannibals on Left: \t" << canni_L << endl;
	cout << "Missionaries on Right: \t" << missi_R << endl;
	cout << "Missionaries on Left: \t" << missi_L << endl;
	
}

bool GameState::rule_check() {


	// Missi's must be greater or equal to canni's OR zero.
	if (canni_L > missi_L && missi_L > 0) {
		//move invalid
		return false;
	}

	if (canni_R > missi_R && missi_R > 0) {
		//move invalid
		return false;
	}
	return true;
}

bool GameState::solution_check() {
	// Must get all cannibals and missionaries from the left to the right
	if(canni_L == 0 && missi_L ==0) {
		//you win
		return true;
	}
	return false;
}

bool GameState::history_check(vector<GameState> h) {
	for(int t=0; t < h.size(); t++){
		if(h[t] == (*this)){
			return false;
		}
	}
	return true;
}

bool GameState::operator==(const GameState& other) {
	if(missi_L != other.missi_L){
		return false;
	}

	if(missi_R != other.missi_R){
		return false;
	}
	if(canni_L != other.canni_L){
		return false;
	}
	if(canni_R != other.canni_R){
		return false;
	}
}

bool GameState::operator!=(const GameState& other) {
	return !((*this)==other);
}

int main () {

//----------------------------------------------------------------------------------
	// INITIALIZE GAME STARTING STATES //
	
	queue<GameState> q;
	vector<GameState> h;

	GameState root, state, new_state;

	root.canni_L = 3;
	root.missi_L = 3;
	root.canni_R = 0;
	root.canni_R = 0;

	root.Boat_L = true;

//----------------------------------------------------------------------------------
	// LETS FIND A SOLUTION //
	
	q.push(root);
	bool SolutionFound = false;

	while (!SolutionFound && q.size() > 0){ //until the solution is found or the queue is not empty

		state = q.front(); //looks at the first guy
		q.pop(); //delete that first guy
		state.print();
		//cout << "q-stuff" <<q.size() << endl;
		for(int num_Occupants = MAX_BOAT; num_Occupants > 0; num_Occupants--) {
			for(int people = 0; people <= num_Occupants; people++) {

				new_state = GenerateChildren(state, people, num_Occupants-people);
				//cout<< "poop" << endl;
				//new_state.print();

				if(new_state != state && state.history_check(h)){ //if its a new state
					if(state.rule_check()){
						if(state.solution_check()){
							cout << "Solution Found!" << endl;
							SolutionFound = true;
							new_state.print();
							people = num_Occupants+1; //break the loop!
							num_Occupants = 0;
						}
						else {
							q.push(new_state); //put it in the queue
							cout << "push into q" << endl;
						}
					}
				}


			}
		}
	}


}



