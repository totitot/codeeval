#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main( int argc, char* argv[] ){
	ifstream stream( argv[1] );
	string line;

	while( getline( stream, line ) ){
		size_t prev_pos = 0;
		size_t pos = 0;
		while( pos != string::npos ){
			pos = line.find(";",prev_pos);
			string num = line.substr(prev_pos,pos-prev_pos);
			if( num == "zero" ) cout << 0;
			if( num == "one" ) cout << 1;
			if( num == "two" ) cout << 2;
			if( num == "three" ) cout << 3;
			if( num == "four" ) cout << 4;
			if( num == "five" ) cout << 5;
			if( num == "six" ) cout << 6;
			if( num == "seven" ) cout << 7;
			if( num == "eight" ) cout << 8;
			if( num == "nine" ) cout << 9;
			prev_pos = pos+1;
		}
		cout << endl;
	}

	return 0;
}
