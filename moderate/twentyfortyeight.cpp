#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main( int argc, char** argv ){
	ifstream file( argv[1] );
	string line;

	while( getline( file, line ) ){
		if( line.size() == 0 ) continue;
		string direction = line.substr(0,line.find(";"));
		string dimension = line.substr(line.find(";")+2,line.find_last_of(";")-1);
		cout << direction << endl;
		cout << dimension << endl;
	}
}
