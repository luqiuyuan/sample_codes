#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main()
{

	// open file
	string filename = "test.txt";
	fstream fs(filename, ios_base::in | ios_base::out);	// with only ios_base::out set, the file will be created automatically

	// check if the file is successfully opened
	if(!fs.is_open()){	// opening failed
		cout<<"fail open failed."<<endl;
		return 1;
	}

	// read lines from file
	string line;
	while(getline(fs, line)){	// none of eofbit, failbit and badbit is set
		cout<<line<<endl;
	}
 
	// close file
	fs.close();

	return 0;
}