#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <map>

#include <algorithm>
using namespace std;

int main( int argc, char** argv ){
	vector<char> vc = {
		 'B'
		,'H'
		,'I'
		,'S'
		,'O'
		,'E'
		,'C'
		,'R'
		,'T'
		,'M'
		,'G'
		,'W'
		,'Y'
		,'V'
		,'A'
		,'L'
		,'U'
		,'Z'
		,'D'
		,'N'
		,'F'
		,'J'
		,'K'
		,'P'
		,'Q'
		,'X'
	};
	vector<char> orig = {
		 'A'
		,'B'
		,'C'
		,'D'
		,'E'
		,'F'
		,'G'
		,'H'
		,'I'
		,'J'
		,'K'
		,'L'
		,'M'
		,'N'
		,'O'
		,'P'
		,'Q'
		,'R'
		,'S'
		,'T'
		,'U'
		,'V'
		,'W'
		,'X'
		,'Y'
		,'Z'
	};

	map< int, char > vpss;
	map< int, char > origss;

	for( int i = 0; i < vc.size() ; i++ ){
		vpss[ i ] = vc[i];
	}
	for( int i = 0; i < orig.size() ; i++ ){
		origss[ i ] = orig[i];
	}
//	sort( vpss.begin(), vpss.end(), []( map<string,string>::iterator a, map<string,string>::iterator b ){ return ( stoi(a->first) ) > ( stoi(b->first) ); } );
	//for( auto& a : vpss ) cout << a.first << " " << a.second << endl;
	for( int i = 0 ; i < vc.size() ; i++ ){
		cout << vc[i] << " " << orig[i] << " " << vc[i] - orig[i] << endl;
	}

	cout << vpss[1] << vpss[22] << vpss[22] << " ";
	cout << vpss[11] << vpss[14] << vpss[14] << vpss[25] << vpss [3] << " ";
	cout << vpss[3] << vpss[13] << vpss[1] << vpss[25] << vpss[13] << " ";
	cout << vpss[3] << vpss[14] << vpss[14] << vpss[18] << vpss[19] << vpss[21] << vpss[2] << " ";
	cout << vpss[1] << vpss[13] << " ";
	cout << vpss[24] << vpss[19] << vpss[18] << vpss[21] << vpss[19] << vpss[2] << vpss[17] << vpss[13] << " " ;
	cout << vpss[6] << vpss[13] << vpss[17] << vpss[15] << vpss[7] << vpss[1] << vpss[19] << endl;
//	for( auto& a : vc ) cout << a << endl;
	
}
