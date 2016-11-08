#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
#include <cctype>

using namespace std;

int main( int argc, char* argv[] ){
	ifstream stream( argv[1] );
	string line;

	while( getline( stream, line ) ){
		int n_size = sqrt( ( line.size() + 1 ) / 2 );
		if( n_size > 1 ){
			string newline( line.size(), ' ' );
			for( size_t i = 0; i < n_size; i++ ){
				for( size_t j = 0; j < n_size; j++ ){
					newline[(i*n_size+j)*2] = line[((n_size-1-j)*n_size+i)*2];
				}
			}
			cout << newline << endl;
		}
		else{
			cout << line << endl;
		}
	}

	return 0;
}
