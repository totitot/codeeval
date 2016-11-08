#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main( int argc, char** argv ){
	ifstream file(argv[1]);
	string line;
	vector<unsigned int> vi;

	while( getline( file, line ) ){
		vi.clear();
		istringstream ss(line);
		unsigned int input;
		while( ss >> input ){
			vi.push_back(input);
		}

	}
}
