#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

int main( int argc, char** argv ){
	ifstream file(argv[1]);
	string line;
	vector<unsigned short> vs(26,0);

	while( getline( file, line ) ){
		transform( line.begin(), line.end(), line.begin(), [](unsigned char c){ return tolower(c); } );
		unsigned char target = 'a';
		while( target - 'a' < 26 ){
			vs[target-'a'] = count( line.begin(), line.end(), target);
			target++;
		}
		sort( vs.begin(), vs.end(), [](unsigned short a, unsigned short b){ return a>b; } );
		int sum = 0, index = 0;
		while( vs[index] != 0 ){
			sum += vs[index] * (26-index);
			index++;
		}
		cout << sum << endl;
	}
}
