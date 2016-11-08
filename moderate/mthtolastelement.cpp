#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main( int argc, char** argv ){
	ifstream file( argv[1] );
	string line;

	while( getline( file, line ) ){
		//cout << line << endl;
		if( line.size() ){
			int mth_element = stoi( line.substr( line.find_last_of( " " ) ) );
			string elements( line.substr( 0, line.find_last_of( " " ) + 1 ) );
			if( mth_element * 2 <= elements.size() ){
				cout << line.substr( line.find_last_of( " " ) + 1 - ( mth_element * 2 ),1 ) << endl;
			}
		}
	}
	return 0;
}
