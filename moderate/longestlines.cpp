#include <string>
#include <deque>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main( int argc, char* argv[] ){
	ifstream file( argv[1] );
	string line;
	deque<string> vs;
	int num_lines;

	while( getline( file, line ) ){
		vs.push_back(line);	
	}
	num_lines = stoi( vs.front() );
	vs.pop_front();
	sort(vs.begin(),vs.end(),[](string a, string b){
		return b.size() < a.size();
	});
	for( int i = 0; i < num_lines; i++ ){
		cout << vs[i] << endl;
	}
}
