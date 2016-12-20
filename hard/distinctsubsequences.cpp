#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main( int argc, char ** argv ){
	ifstream file(argv[1]);
	string line;

	while( getline( file, line ) ){
		if( line.size() ){
			vector<vector<string::size_type>> vi;
			string seq = line.substr( 0, line.find(",") );
			string sub = line.substr( line.find(",")+1 );
			for(int i = 0; i < sub.size() i++ ){ 
				string::size_type pos = 0;
				for(; pos!=string::npos ;){
			}
		}
	}
}
