#ifndef READFILE_H
#define READFILE_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
//#include <string>
#include <cstring>
#include "ReadString.h"
using namespace std;

class ReadFile{
	string file;
	int id;
public: 
	ReadFile();
	string readFile(string file,int id,int place);
	~ReadFile();
};
#endif
