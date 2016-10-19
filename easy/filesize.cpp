#include <fstream>
#include <iostream>

using namespace std;
int main( int argc, char * argv[] ){
	ifstream stream(argv[1]);

	stream.seekg(0,std::ios_base::end);
	std::ios_base::streampos end_pos = stream.tellg();
	cout << end_pos;

	return 0;
}
