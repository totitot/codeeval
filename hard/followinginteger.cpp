#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool doSwap(unsigned int& a, unsigned int& b ){
	if( b < a ){
		swap( a, b );
		return true;
	}
	return false;
}

void addZero( vector<unsigned int>& vui ){
	sort( vui.begin(), vui.end(), []( unsigned int a, unsigned int b ){
		return ( ( b > a ) && ( b > 0 ) && ( a > 0 ) );
	});
	vui.push_back(0);
	auto srf = vui.begin();
	auto srl = vui.end();
	auto dsf = vui.end();
	srf++; srl--;

	move_backward( srf, srl, dsf );
	vui[1] = 0;
}

int main( int argc, char** argv ){
	ifstream file( argv[1] );
	string line;
	vector<unsigned int> num;

	while( getline( file, line ) ){
		for( int i = 0; i < line.size(); i++ ) num.push_back(stoi(line.substr(i,1)));
		bool done_swap = false;
		for( int i = num.size()-1; i >= 0 && !done_swap; i-- )
			done_swap = doSwap( num[i], num[i-1] );
		if( !done_swap ) addZero( num );
		for( auto& i : num ) cout << i;
		cout << endl;
		num.clear();
	}
}
