#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main( int argc, char * argv[] ){
	ifstream stream(argv[1]);
	string line;

	while( getline( stream, line ) ){
		int target_num = 0;
		int num_to_use = 0;
		int running_num = 0;

		target_num = stoi( line.substr( 0, line.find(",") ) );
		num_to_use = stoi( line.substr( line.find(",") + 1, line.size() ) );

		while( target_num > running_num ){
			running_num += num_to_use;
		}
		cout << running_num << endl;
	}

	return 0;
}
