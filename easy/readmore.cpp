#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main( int argc, char** argv ){
	ifstream file(argv[1]);
	string line;
	string msg("... <Read More>");

	while( getline( file, line ) ){
		if( line.size() <= 55 )
			cout << line << endl;
		else{
			line.erase(40,string::npos);
			cout << line.substr(0,line.find_last_of(' ')) + msg << endl;
		}
	}

	return 0;
}
