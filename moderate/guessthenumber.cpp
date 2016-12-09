#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main( int argc, char** argv ){
	ifstream file( argv[1] );
	string line;

	while( getline( file, line ) ){
		istringstream iss( line );
		unsigned int upper_bound = 0;
		unsigned int lower_bound = 0;
		unsigned int predict = 0;
		iss >> upper_bound;
		predict = ( upper_bound + lower_bound + 1 ) / 2;
		string high_low;
		while( iss >> high_low ){
			if( high_low == "Lower" ){
				upper_bound = predict-1;
		predict = ( upper_bound + lower_bound + 1 ) / 2;
			}
			if( high_low == "Higher" ){
				lower_bound = predict+1;
		predict = ( upper_bound + lower_bound + 1 ) / 2;
			}
		}
		cout << predict << endl;
	}
}
