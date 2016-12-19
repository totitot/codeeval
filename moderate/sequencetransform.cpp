#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main( int argc, char** argv ){
	ifstream file(argv[1]);
	string bin, alpha;

	while( file >> bin >> alpha ){
		cout << bin << " " << alpha << endl;
		string::size_type prev_pos = 0;
		string::size_type pos = 0;
		vector< string > v_alpha;
		while( prev_pos != string::npos ){
			if( alpha[prev_pos] == 'A' ){
				pos = alpha.find('B',prev_pos);
				
				prev_pos = pos;
			}
			if( alpha[prev_pos] == 'B' ){
				pos = alpha.find('A',prev_pos);
				v_alpha.push_back(alpha.substr(prev_pos,pos-prev_pos) );
				prev_pos = pos;
			}
		}
	}

	return 0;
}
