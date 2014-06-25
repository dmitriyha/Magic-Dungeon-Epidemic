#ifndef WRITEFILE_H
#define WRITEFILE_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
//#include <string>
#include <cstring>
using namespace std;

class WriteFile{
	string file;
	int append;
public: 
	WriteFile();
	void writeFile(string file, int append);
	~WriteFile();
};
#endif
