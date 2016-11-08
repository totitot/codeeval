#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main( int argc, char* argv[] ){
	ifstream file(argv[1]);
	string line;
	int sum = 0;

	while( getline( file, line ) ){
		sum += stoi( line );
	}
	cout << sum << endl;
	return 0;
}
