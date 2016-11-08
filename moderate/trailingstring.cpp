#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main( int argc, char** argv ){
	ifstream file( argv[1] );
	string line;

	while( getline( file, line ) ){
		if( line.size() ){
			string comparee = line.substr(0,line.find(",")); 
			string comparer = line.substr(line.find(",")+1,line.size()); 
			
			if( comparee.size() >= comparer.size() )
			cout << ( comparee.substr( comparee.size() - comparer.size(), comparee.size() ) == comparer ) << endl;
			else
			cout << 0 << endl;
		}
	}
	return 0;
}
