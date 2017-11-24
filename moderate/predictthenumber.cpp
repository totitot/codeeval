#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

int main(int argc, char** argv){
	ifstream file(argv[1]);
	string line;

	while( getline(file,line) ){

		uint32_t num = stoi(line);
		uint32_t log2num = log2(num);
		uint32_t pow2 = pow(2,log2num);

		cout
		<< num
		<< " "
		<< log2num
		<< " "
		<< pow2
		<< " "
		<< log2(num)
		<< " "
		<< int(num - (pow2-1))
		<< " "
		<< pow(2,log2(num))
		<< endl;
	}

	return 0;
}
