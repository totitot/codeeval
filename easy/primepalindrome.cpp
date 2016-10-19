#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
int main( int argc, char * argv[] ){
	vector< int > primes;
	int range = 1000;
	
	primes.push_back(2);

	for( int i = 3; i < range; i+=2 ){
		bool is_prime = true;
		for( int j = 0; j < primes.size(); j++ ){
			is_prime &= ( ( i % primes[j] ) != 0 );
		}
		if( is_prime ){
			primes.push_back( i );
		}
	}

	for( int i = primes.size() - 1; i > -1; i-- ){
		bool is_symmetric = ( ( static_cast<int>( floor( log10( primes[i] ) ) ) % 2 ) == 0 ) || ( primes[i] == 11 );
		if(
			( 	
					primes[i] % static_cast<int>( pow( 10, ( floor( log10( primes[i] ) ) / 2 ) ) )
				==	primes[i] / static_cast<int>( pow( 10, floor( log10( primes[i] ) ) ) )
			)
			&& is_symmetric
		){
			cout << primes[i] << endl;
			break;
		}
	}

	return 0;
}
