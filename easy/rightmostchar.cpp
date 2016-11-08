#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main( int argc, char ** argv ){
	ifstream file(argv[1]);
	string line;

	while( getline( file, line ) ){
		if( line.size() ){
			char target = line[line.size()-1];
			line.erase(line.find(','),string::npos);
			cout << int(line.find_last_of( target )) << endl;
		}
	}
}
