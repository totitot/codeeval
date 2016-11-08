#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main( int argc, char* argv[] ){
	ifstream stream( argv[1] );
	string line, newline;

	while( getline( stream, line ) ){
		newline = "";
		for( size_t i = 0; i < line.size(); i++ ){
			if( i == 0 ) newline += line[i];
			else if( line[i] != line[i-1] ) newline += line[i];
		}
		cout << newline << endl;
	}

	return 0;
}
