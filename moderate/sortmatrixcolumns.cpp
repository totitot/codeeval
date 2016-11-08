#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main( int argc, char** argv ){
	ifstream file( argv[1] );
	string line;
	vector< vector<int> > vvi;
	vector< pair<int,int> > vp;

	while( getline( file, line ) ){
		vvi.clear();
		int pos = 0;
		int prev_pos = 0;
		while( pos != string::npos ){
			pos = line.find("|",prev_pos);
			vvi.push_back(vector<int>());
			istringstream ss( line.substr(prev_pos, pos-prev_pos) );
			int input = 0;
			while( ss >> input ){
				vvi.back().push_back(input);
			}
			prev_pos = pos+1;
		}
		while( !is_sorted( vvi[0].begin(), vvi[0].end() ) ){
			for( int i = 0; i < vvi[0].size() - 1; i++ ){
				int depth = 0;
				while( ( vvi[depth][i] == vvi[depth][i+1] ) && ( depth < vvi.size() ) ){
					depth++;
				}
				if( depth != vvi.size() && ( vvi[depth][i] > vvi[depth][i+1] ) ){
					for( int j = 0; j < vvi.size(); j++ ){
						swap( vvi[j][i], vvi[j][i+1] );
					}
				}
			}
		}
		for( int i = 0; i < vvi[0].size() - 1; i++ ){
			int depth = 0;
			while( ( vvi[depth][i] == vvi[depth][i+1] ) && ( depth < vvi.size() ) ){
				depth++;
			}
			if( depth != vvi.size() && ( vvi[depth][i] > vvi[depth][i+1] ) ){
				for( int j = 0; j < vvi.size(); j++ ){
					swap( vvi[j][i], vvi[j][i+1] );
				}
			}
		}
		for( int i = 0; i < vvi.size(); i++ ){
			for( int j = 0; j < vvi[i].size(); j++ ){
				cout << vvi[i][j];
				if( i == vvi.size() - 1 && j == vvi.size() - 1 ){}else cout << " ";
			}
			if( i != vvi.size() - 1 ) cout << "| ";
		}
		cout << endl;
	}
	return 0;
}
