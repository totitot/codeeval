#include <fstream>
#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main( int argc, char* argv[] ){
	ifstream file(argv[1]);
	string line;

	while( getline( file, line ) ){
		int num = stoi( line );
		bitset<32> bin_num(num);
		int one_count = 0;
		bool first_one = false;
		for( int ii = bin_num.size(); ii >= 0; ii-- ){
			first_one |= bin_num[ii];
			if( first_one && bin_num[ii] ) one_count++;
		}
		cout << one_count << endl;
	}
	return 0;
}
