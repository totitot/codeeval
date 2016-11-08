#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main( int argc, char** argv ){
	ifstream file(argv[1]);
	string line;
	vector<unsigned int> vi;

	while( file >> line ){
		int index = 0;
		while( index < line.size() ){
			if( count( line.begin(), line.end(), line[index] ) == 1 ) break;
			index++;
		}
		cout << line[index] << endl;
	}
	return 0;
}
