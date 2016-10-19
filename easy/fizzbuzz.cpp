#include <fstream>
#include <iostream>

using namespace std;
int main( int argc, char * argv[] ){
	ifstream stream(argv[1]);
	int xx = 0, yy = 0, zz = 0;
	bool fizz = false, buzz = false, fizzbuzz = false;

	while( stream >> xx >> yy >> zz ){
		for( int i = 1; i <= zz; i++ ){
			if( ( i % xx ) == 0 ) fizz = true;
			if( ( i % yy ) == 0 ) buzz = true;
			if( fizz && buzz ) cout << "FB";
			else if( fizz ) cout << "F";
			else if( buzz ) cout << "B";
			else cout << i;
			if( i < zz ) cout << " ";
			fizz = buzz = fizzbuzz = false;
		}
		cout << endl;
	}

	return 0;
}
