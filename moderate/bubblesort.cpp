#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main( int argc, char* argv[] ){
	ifstream file( argv[1] );
	string line;
	vector<int> vi;
	int input, num_iter;

	while( getline( file, line ) ){
		istringstream ss(line.substr(0,line.find("|")));
		while( ss >> input ) vi.push_back(input);
		istringstream fl( line.substr(line.find("|")+1) );
		fl >> num_iter;
		for( int i = 0; i < num_iter && i < vi.size(); i++ ){
			for( int j = 0; j < vi.size()-1-i; j++ ){
				if( vi[j] > vi[j+1] ){
					//cout << "before: " << vi[j] << " " << vi[j+1] << endl;
					swap( vi[j], vi[j+1] );
					//cout << "after: " << vi[j] << " " << vi[j+1] << endl;
				}
			}
		}
		cout << vi[0];
		for( int i = 1; i < vi.size(); i++ ){
			cout << " " << vi[i];
		}
		cout << endl;
		vi.clear();
	}
	return 0;
}
