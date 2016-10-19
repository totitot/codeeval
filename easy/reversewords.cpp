#include <fstream>
#include <iostream>
#include <string>

using namespace std;
int main( int argc, char * argv[] ){
	ifstream stream(argv[1]);
	string line;
	string newline;

	while( getline(stream,line) ){
		newline = "";
		while( line.find_last_of(" ") != string::npos ){
			size_t pos = line.find_last_of(" ");
			newline += line.substr(pos+1) + " ";
			line = line.substr(0,pos);
		}
		cout << newline << line << endl;
	}

	return 0;
}
