#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main( int argc, char** argv ){
	ifstream file(argv[1]);
	string line;
	vector<unsigned int> vi;

	while( getline( file, line ) ){
		vi.clear();
		istringstream ss(line);
		unsigned int input;
		while( ss >> input ){
			vi.push_back(input);
		}

		int distance = vi.size()-1;
		unsigned int iter = 0;
		do{
			//cout << distance << endl;
			for( int i = 0, j = distance; j < vi.size(); i++, j++ ){
				if( vi[i] > vi[j] ) swap(vi[i],vi[j]);
			}
			distance /= 1.25;
			if( distance == 0 ) distance = 1;
			iter++;
		}
		while( !is_sorted( vi.begin(), vi.end() ) );
		cout << iter << endl;
		//for( auto i : vi ) cout << i << " ";
		//cout << endl;
	}

}
