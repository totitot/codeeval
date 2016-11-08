#include <fstream>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void print_diff( int t1, int t2 ){
	int diff = t1 - t2;
	if( ( diff / 3600 ) < 10 ) cout << 0;
	cout << diff / 3600 << ":";
	if( ( ( diff % 3600 ) / 60 ) < 10 ) cout << 0;
	cout << ( ( diff % 3600 ) / 60 ) << ":" ;
	if( ( ( diff % 3600 ) % 60 ) < 10 ) cout << 0;
	cout << ( ( diff % 3600 ) % 60 ) << endl;
}

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
	string time1, time2;
	int secs1, secs2;

	while( file >> time1 >> time2 ){
		secs1 = getsecs( time1 );
		secs2 = getsecs( time2 );

		if( secs1 > secs2 ) print_diff( secs1, secs2 );
		else if( secs1 < secs2 ) print_diff( secs2, secs1 );
		else cout << "00:00:00" << endl;
	}

	return 0;
}
