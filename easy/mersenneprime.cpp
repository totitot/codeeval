#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
int main( int argc, char * argv[] ){
	ifstream stream(argv[1]);
	vector< int > primes;
	vector< int > mprimes;
	int range = 3000;
	int max_num = 0;
	int two_pow = 0;
	
	//primes.reserve( ceil( range / log( range ) ) );
	primes.push_back(2);

	//mprimes.reserve( log( primes.capacity() ) );

	for( int i = 3; i < range; i+=2 ){
		bool is_prime = true;
		for( int j = 0; j < primes.size(); j++ ){
			is_prime &= ( ( i % primes[j] ) != 0 );
		}
		if( is_prime ){
			primes.push_back( i );
		}
	}

	for( int i = 0; i < primes.size(); i++ ){
		two_pow = exp2( primes[i] ) - 1;
		if( two_pow >= range ) break;
		vector<int>::iterator p = find( primes.begin(), primes.end(), two_pow );
		if( p != primes.end() ){
			mprimes.push_back( two_pow );
		}
	}

	while( stream >> max_num ){
		int i = 0;
		while( i < mprimes.size() ){
			if( mprimes[i] >= max_num ){
				break;
			}
			else{
				if( i ) cout << ", ";
				cout << mprimes[i];
				i++;
			}
		}
		cout << endl;
	}

	return 0;
}
