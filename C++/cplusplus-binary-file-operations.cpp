#include <fstream>
#include <iostream>

using namespace std;

int main() {
	// open file in binary mode
	string filename = "test.dat";
	fstream fs(filename, ios::binary | ios_base::out);	// with only ios_base::out set, the file will be created automatically

	int data1 = 5;
	int data2 = 7;
	double data3 = 5.5;
	fs.write((char*)&data1, sizeof(int));
	fs.write((char*)&data2, sizeof(int));
	fs.write((char*)&data3, sizeof(double));

	fs.close();

	fs.open(filename, ios::binary | ios_base::in);

	int data1r;
	int data2r;
	double data3r;
	fs.read((char*)&data1r, sizeof(int));
	fs.read((char*)&data2r, sizeof(int));
	fs.read((char*)&data3r, sizeof(double));

	cout<<data1r<<endl;
	cout<<data2r<<endl;
	cout<<data3r<<endl;

	fs.close();

	return 0;
}
