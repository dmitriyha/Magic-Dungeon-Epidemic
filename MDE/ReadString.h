#ifndef READSTRING_H
#define READSTRING_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <cstring>
using namespace std;

/** \brief parses a csv file line
 *
 *
 */     


class ReadString{
	
public: 
	ReadString( );
	string readString(string line,int place);
	~ReadString();
};
#endif
