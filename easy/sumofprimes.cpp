#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
int main( int argc, char * argv[] ){
	vector< int > primes;
	int number = 3;
	
	primes.reserve( 1000 );
	primes.push_back(2);

	while( primes.size() < 1000 ){
		bool is_prime = true;
		for( int j = 0; j < primes.size(); j++ ){
			is_prime &= ( ( number % primes[j] ) != 0 );
		}
		if( is_prime ){
			primes.push_back(number);
			//cout << number << " is a prime" << endl;
		}
		number+=2;
	}

	int sum = 0;
	for( int i = 0; i < primes.size(); i++ ){
		sum += primes[i];
	}
	cout << sum << endl;

	return 0;
}
