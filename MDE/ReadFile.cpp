#include "ReadFile.h"

ReadFile::ReadFile(){
}

/** \brief Reads the given file until id, or EOF is reached
 *
 * \param file the file that needs to be read
 * \param id the line you want to be read
 * \param place the column to be read
 * \return returns the string required from the file, "-1" in string form if EOF is reached, and "0" in string form if unable to open the file 
 *
 */     


string ReadFile::readFile(string file, int id, int place){
	int count;
	string line;
	
	//reads file until id  and prints the line or until end of file is reached
	ifstream read;
	read.open(file.c_str());
	if (read.is_open()){	
		for(count=id;count>0;count--){
			getline(read,line);
			if(count==1){
				ReadString *read=new ReadString();
				line=read->readString(line,place);
				delete read;
				if (line == ""){
					return "-1";
				}
				return line;
				//converts strings to integers
				//istringstream buffer(line);
				//buffer >>Result;
			}
			if(read.eof()){
				line="-1";
				return line;
			}
		}
	}
	else{
		//cout<<"unable to open";	//prints error message because file was not located
		return "0";
	}
}


ReadFile::~ReadFile(){
}
