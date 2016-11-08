#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main( int argc, char* argv[] ){
	ifstream file(argv[1]);
	string dummy;
	vector<vector<int> > vvi;
	string line;

	while( getline( file, line ) ){
		vvi.erase(vvi.begin(),vvi.end());
		string::size_type prev_pos = 0;
		string::size_type pos = 0;
		while( pos != string::npos ){
			pos = line.find("|",prev_pos);
			istringstream ss(line.substr(prev_pos,pos-prev_pos));
			int input;
			int index = 0;
			while( ss >> input ){
				if( prev_pos == 0 ) vvi.push_back(vector<int>());
				vvi[index].push_back(input);
				index++;
			}
			prev_pos = pos + 1;
		}

		for( int i = 0; i < vvi.size(); i++ ){
			sort( vvi[i].begin(), vvi[i].end() );
			cout << vvi[i].back();
			if( i != vvi.size() - 1 ) cout << " ";
		}
		cout << endl;
	}

	return 0;
}
