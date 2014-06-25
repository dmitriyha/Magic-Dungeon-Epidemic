#include "RNG.h"

RNG::RNG(){
	srand(chrono::system_clock::now().time_since_epoch().count()); 
}

int RNG::generate(int start,int amount){//generates a number from start to start+amount
	if(first_run){
		
		first_run=false;
	}
	return rand()%amount+start;
}

RNG::~RNG(){
}
