#include "ReadString.h"

ReadString::ReadString(){
}

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
