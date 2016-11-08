#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main( int argc, char** argv ){
	ifstream file(argv[1]);
	string bin, alpha;

	while( file >> bin >> alpha ){
		cout << bin << " " << alpha << endl;
		string::size_type pos = 0;
		for( int i = 0; i < bin.size(); i++ ){
			if( bin[i] == "1" )
		}
	}

	return 0;
}
