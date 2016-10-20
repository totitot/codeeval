#include <cmath>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main( int argc, char* argv[] ){
	ifstream stream( argv[1] );
	string line;

	while( getline( stream, line ) ){
		int num = stoi(line);
		int max_pow = floor(log10(num)) + 1;
		int sum = 0;
		for( size_t i = max_pow; i > 0; i-- ){
			sum += ( num % static_cast<int>(pow(10,i)) ) / ( static_cast<int>(pow(10,i-1)) );
		}
		cout << sum << endl;;
	}
	return 0;
}
