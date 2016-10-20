#include <fstream>
#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main( int argc, char * argv[] ){
	ifstream stream(argv[1]);
	string line;

	while( getline( stream, line ) ){
		int num_of_zeros = 0;
		int range = 0;
		int running_num = 0;
		int zero_count = 0;

		if( line.find(" ") != string::npos ){
			num_of_zeros = stoi( line.substr( 0, line.find(" ") ) );
			range = stoi( line.substr( line.find(" ") + 1, line.size() ) );
		}

		for( int i = 1; i <= range; i++ ){
			bitset<10> bin_num(i);
			zero_count = 0;
			bool first_one = false;
			for( int ii = bin_num.size(); ii >= 0; ii-- ){
				first_one |= bin_num[ii];
				if( first_one && !bin_num[ii] ) zero_count++;
			}
			if( zero_count == num_of_zeros ){
				running_num++;
			}
		}
		cout << running_num << endl;
	}

	return 0;
}
