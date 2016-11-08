#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

void update_grid(
	  vector<string>& vin
	, vector<string>& vout
){
	for( int x = 0; x < vin.size(); x++ ){
		for( int y = 0; y < vin[x].size(); y++ ){
			if( x == 0 ){
				int alive_count = 0;
				if( y == 0 ){
					for( int z = 0; z < 2; z++ ){
						if( vin[x+1][y+z] == '*' ) alive_count++;
					}
					if( vin[x][y+1] == '*' ) alive_count++;
				}
				else if( y == vin[x].size() - 1 ) {
					for( int z = -1; z < 1; z++ ){
						if( vin[x+1][y+z] == '*' ) alive_count++;
					}
					if( vin[x][y-1] == '*' ) alive_count++;
				}
				else{
					for( int z = -1; z < 2; z++ ){
						if( vin[x+1][y+z] == '*' ) alive_count++;
					}
					if( vin[x][y-1] == '*' ) alive_count++;
					if( vin[x][y+1] == '*' ) alive_count++;
				}
				if( alive_count < 2 ) vout[x][y] = '.';
				if( alive_count > 3 ) vout[x][y] = '.';
				if( alive_count == 3 ) vout[x][y] = '*';
			}
			else if( x == vin.size() - 1 ){
				int alive_count = 0;
				if( y == 0 ){
					for( int z = 0; z < 2; z++ ){
						if( vin[x-1][y+z] == '*' ) alive_count++;
					}
					if( vin[x][y+1] == '*' ) alive_count++;
				}
				else if( y == vin[x].size() - 1 ) {
					for( int z = -1; z < 1; z++ ){
						if( vin[x-1][y+z] == '*' ) alive_count++;
					}
					if( vin[x][y-1] == '*' ) alive_count++;
				}
				else{
					for( int z = -1; z < 2; z++ ){
						if( vin[x-1][y+z] == '*' ) alive_count++;
					}
					if( vin[x][y-1] == '*' ) alive_count++;
					if( vin[x][y+1] == '*' ) alive_count++;
				}
				if( alive_count < 2 ) vout[x][y] = '.';
				if( alive_count > 3 ) vout[x][y] = '.';
				if( alive_count == 3 ) vout[x][y] = '*';
			}
			else{
				int alive_count = 0;
				if( y == 0 ){
					for( int z = 0; z < 2; z++ ){
						if( vin[x-1][y+z] == '*' ) alive_count++;
						if( vin[x+1][y+z] == '*' ) alive_count++;
					}
					if( vin[x][y+1] == '*' ) alive_count++;
				}
				else if( y == vin[x].size() - 1 ) {
					for( int z = -1; z < 1; z++ ){
						if( vin[x-1][y+z] == '*' ) alive_count++;
						if( vin[x+1][y+z] == '*' ) alive_count++;
					}
					if( vin[x][y-1] == '*' ) alive_count++;
				}
				else{
					for( int z = -1; z < 2; z++ ){
						if( vin[x-1][y+z] == '*' ) alive_count++;
						if( vin[x+1][y+z] == '*' ) alive_count++;
					}
					if( vin[x][y-1] == '*' ) alive_count++;
					if( vin[x][y+1] == '*' ) alive_count++;
				}
				if( alive_count < 2 ) vout[x][y] = '.';
				if( alive_count > 3 ) vout[x][y] = '.';
				if( alive_count == 3 ) vout[x][y] = '*';
			}
		}
	}
}

int main( int argc, char** argv ){
	ifstream file(argv[1]);
	string line;
	vector<string> vs;

	while( file >> line ){
		vs.push_back(line);
	}
	vector<string> vsout(vs);
	for( int i = 0; i < 10; i++ ){
		assert(vsout.size() == vs.size());
		if( i % 2 ){
			update_grid( vsout, vs );
			vsout = vs;
		}
		else{
			update_grid( vs, vsout );
			vs = vsout;
		}
	}
	for( string a : vs ){
		cout << a << endl;
	}
	return 0;
}
