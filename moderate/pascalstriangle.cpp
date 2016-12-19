#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main( int argc, char** argv ){
	ifstream file(argv[1]);
	string line;
	while( getline( file, line ) ){
		if( line.size() ){
			vector<unsigned int> init(1,1);
			vector<unsigned int> current;
			unsigned int depth = stoi(line);
			for( auto i = 0UL; i < depth; i++ ){
				for( auto j = 0UL; j <= i; j++ ){
					if( j == 0 || j == i ) current.push_back(1);
					else current.push_back( init[j] + init[j-1] );
				}
				for( auto a : current ) cout << a << " ";
				init = current;
				current.clear();
			}
			cout << endl;
		}
	}
	return 0;
}
