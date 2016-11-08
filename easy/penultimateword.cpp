#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main( int argc, char* argv[] ){
	ifstream file(argv[1]);
	string line, dummy;
	vector<string> vs;

	while( getline( file, line ) ){
		istringstream ss(line);
		while( ss >> dummy ) vs.push_back(dummy);
		cout << vs[vs.size()-2] << endl;
	}

	return 0;
}
