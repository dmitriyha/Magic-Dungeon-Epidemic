#include "WriteFile.h"

WriteFile::WriteFile(){
}

void WriteFile::writeFile(string file, int append){
	int count;
	
	//writes to file
	ofstream write;
	if(append){									//should the user want to append a file, "append" should be set to 1... 
	
		write.open (file.c_str(),ios::app);		//opens stream and sets the 'ios::app' append property
		if (write.is_open()){
	
			for(count=100;count>>0;count--){
				write<<count;
				write<<"\n";
			}
			write.close();
		}
		else{
			cout<<"unable to open";				//prints error message because file was not located
		}
	}
	else{										//...for an overwrite, any other value goes
		write.open (file.c_str());				//opens stream
		if (write.is_open()){
	
			for(count=100;count>>0;count--){
				write<<count;
				write<<"\n";
			}
			write.close();
		}
		else{
			cout<<"unable to open";				//prints error message because file was not located
		}
	}
}

WriteFile::~WriteFile(){
}
