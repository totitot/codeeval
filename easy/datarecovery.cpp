#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <utility>
#include <algorithm>

using namespace std;

int main( int argc, char** argv ){
	ifstream file(argv[1]);
	string line;
	vector< string > vs;
	vector< unsigned int > vi;
	vector< pair< unsigned int, string > > vp;

	while( getline(file,line) ){
		vp.clear();
		vi.clear();
		vs.clear();
		istringstream sss( line.substr( 0, line.find(";") ) );
		istringstream ssi( line.substr( line.find(";")+1 ) );
		string input_str;
		unsigned int input_int;
		while( sss >> input_str ) vs.push_back( input_str );
		while( ssi >> input_int ) vi.push_back( input_int );
		for( int i = 0; i < vi.size(); i++ ){
			vp.push_back( make_pair(vi[i],vs[i]) );
		}
		sort( vp.begin(), vp.end() );
		for( int i = 0, j=0; i < vs.size(); i++ ){
			if( i-j < vp.size() ){
				if( vp[i-j].first != i+1 ){
					cout << vs[vi.size()+j];
					j++;
				}
				else cout << vp[i-j].second;
			}
			else cout << vs[i];
			if( i != vs.size() -1 ) cout << " ";
		}
		cout << endl;
	}
}
