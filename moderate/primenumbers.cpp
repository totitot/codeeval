#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int main( int argc, char * argv[] ){
	ifstream stream(argv[1]);
	vector< int > primes;
	string line;
	int max_num;
	int prev_max = 3;
	
	primes.push_back(2);
	primes.push_back(3);


	while( stream >> max_num ){
		if( prev_max < max_num ){
			for( int i = primes.back() + 2; i < max_num; i+=2 ){
				bool is_prime = true;
				for( int j = 0; j < primes.size(); j++ ){
					is_prime &= ( ( i % primes[j] ) != 0 );
				}
				if( is_prime ){
					primes.push_back( i );
				}
			}
		}
		for( int i = 0; primes[i] < max_num && i < primes.size(); i++ ){
			if( i > 0 ) cout << ",";
			cout << primes[i];

		}
		cout << endl;
		prev_max = max_num;
	}

	return 0;
}
