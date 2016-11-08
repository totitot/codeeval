#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main( int argc, char* argv[] ){
	ifstream file(argv[1]);
	string line;
	int row, value, col;
	vector< vector<int> > vvi(256, vector<int>(256,0));

	while( file >> line ){
		if( line.find("Set") != string::npos ){
			if( line.find("Col") != string::npos ){
				file >> col >> value;
				for( int i = 0; i < 256; i++ ){
					vvi[i][col] = value;
				}
			}
			if( line.find("Row") != string::npos ){
				file >> row >> value;
				for( int i = 0; i < 256; i++ ){
					vvi[row][i] = value;
				}
			}
		}
		if( line.find("Query") != string::npos ){
			int sum = 0;
			if( line.find("Col") != string::npos ){
				file >> col;
				for( int i = 0; i < 256; i++ ){
					sum += vvi[i][col];
				}
			}
			if( line.find("Row") != string::npos ){
				file >> row;
				for( int i = 0; i < 256; i++ ){
					sum += vvi[row][i];
				}
			}
			cout << sum << endl;
		}
	}
	return 0;
}
