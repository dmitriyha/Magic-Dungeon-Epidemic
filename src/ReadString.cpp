#include "ReadString.h"

ReadString::ReadString(){
}

/** \brief reads a string that is fed into the function to find the corrct colm
 *
 * \param line the string to be read
 * \param place the column to be selected
 * \return the substring that we want from the string that was given, or empty if out of bounds
 *
 */     


string ReadString::readString(string line, int place){
	string finalString;
	stringstream ss(line);
	while (getline(ss,finalString,',')){ //searches for ','  in the 'ss' string stream
		place--;						 //decrements the desired place to find...
		if(place==0){ 					 //...until 0 is reached, after which the loop is exited...
			break;
		}
	}
	return finalString;					 //...and the wanted element in the line is returned
}

ReadString::~ReadString(){
}
