#include "RNG.h"

/** \brief constructs the random number generator
 *
 *
 */     


RNG::RNG(){
	srand(chrono::system_clock::now().time_since_epoch().count()); 
}

/** \brief Generates a pseudo random number
 *
 * \param start the lower bound or our random range
 * \param amount the amount of numbers required from the start param will be the upper bound
 * \return the pseudo random number
 *
 */     


int RNG::generate(int start,int amount){//generates a number from start to start+amount
	if(first_run){
		
		first_run=false;
	}
	return rand()%amount+start;
}

RNG::~RNG(){
}
