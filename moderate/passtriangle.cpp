#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main( int argc, char* argv[] ){
	ifstream file( argv[1] );
	string line;
	vector< vector<int> >vvi;

	while( getline( file, line ) ){
		vvi.push_back(vector<int>());
		istringstream ss(line);
		int input;
		while( ss >> input ) vvi.back().push_back(input);
	}
	for( int i = vvi.size() - 2; i >= 0; i-- ){
		for( int j = 0; j < vvi[i].size(); j++ ){
			vvi[i][j] += ( vvi[i+1][j] >= vvi[i+1][j+1] ) ?
			vvi[i+1][j] : vvi[i+1][j+1];
		}
	}
	cout << vvi[0][0] << endl;
	return 0;
}
