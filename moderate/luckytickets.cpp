#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
class Bignum{
	vector<unsigned short> vs;

	void store( long long input ){
		int pow10 = 1;
		vs.clear();
		while( input > 0 ){
			vs.push_back(input%10);
			input /= 10;
		}
	}

	void add( Bignum & other ){
		
	}

	void print_value(){
		for( int i = vs.size()-1; i >= 0; i-- ){
			cout << vs.at(i);
		}
		cout << endl;
	}
public:
	Bignum(const long long& input){
		store(input);
	}

	Bignum ( const Bignum& rhs ) : vs(rhs.vs){}

	void operator = (long long input){
		store(input);
	}

	Bignum operator * ( const Bignum& rhs ){
	}
};

double binomial_coeff( unsigned int n, unsigned int k ){
	double up = 1;
	double down = 1;
	if( k > 0 && k < n ) for( unsigned int i = 1; i <= k; i++ ){
		up *= ( n + 1 - i );
		down *= i;
	}
	return up/down;
}

int main( int argc, char** argv ){
	ifstream file( argv[1] );
	int num_digits;
	const int base = 10;

	Bignum bs(100);
	Bignum bs1 = bs;

	while( file >> num_digits ){
		num_digits /= 2;
		double final_sum = 0;
		for( unsigned int i = 0; i <= 9*num_digits; i++ ){
			long long sum = 0;
			for( unsigned int j = 0; j <= i/base; j++ ){
				sum += pow(-1,j)
					*binomial_coeff(num_digits,j)
					*binomial_coeff((i+num_digits-1-(base*j)),num_digits-1);
			}
			final_sum += sum*sum;
		}
		cout << final_sum << endl;
	}
	return 0;
}
