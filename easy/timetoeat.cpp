#include <utility>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int getsecs( string & str ){
	size_t prev_pos = 0;
	size_t pos = 0;
	int secs = 0;
	int i = 2;
	while( pos != string::npos && i >= 0 ){
		pos = str.find(":",prev_pos);
		secs += pow( 60, i ) * stoi( str.substr(prev_pos,pos-prev_pos) );
		i--;
		prev_pos = pos+1;
	}
	return secs;
}

int main( int argc, char* argv[] ){
	ifstream file( argv[1] );
	string line, dummy;
	vector< pair<int,string> > vt;

	while( getline( file, line ) ){
		vt.clear();
		istringstream ss(line);
		while( ss >> dummy ) vt.push_back( make_pair( getsecs(dummy), dummy ) );
		sort( vt.begin(), vt.end() );
		for( int i = vt.size()-1; i > -1; i-- ){
			cout << vt[i].second;
			if( i != 0 ) cout << " ";
		}
		cout << endl;
	}
	return 0;
}

