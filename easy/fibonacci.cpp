#include <fstream>
#include <iostream>

using namespace std;

int fibonacci( int n ){
	if( n <= 1 ) return n;
	return fibonacci(n-1) + fibonacci(n-2);
}

int main( int argc, char* argv[] ){
	ifstream file(argv[1]);
	string line;

	while( getline( file, line ) ) cout << fibonacci( stoi( line ) ) << endl;
	return 0;
}
