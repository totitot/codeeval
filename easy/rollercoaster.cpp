#include <fstream>
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main( int argc, char** argv ){
	ifstream file( argv[1] );
	string line;
	while( getline( file, line ) ){
		int alpha_count = 0;
		for( int i = 0; i < line.size(); i++ ){
			if( isalpha(line[i]) ){
				if( alpha_count%2 ) line[i] = tolower(line[i]);
				else line[i] = toupper(line[i]);
				alpha_count++;
			}
		}
		cout << line << endl;
	}
}
