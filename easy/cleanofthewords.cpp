#include <fstream>
#include <iostream>
#include <string>
#include <locale>
#include <cctype>

using namespace std;
int main( int argc, char * argv[] ){
	ifstream stream(argv[1]);
	string line;
	string newline;

	auto& f = use_facet<ctype<char> >(locale());

	while( getline( stream, line ) ){
		newline = "";
		f.tolower(&line[0],&line[0]+line.size());
		bool is_letter = false;
		for( int i = 0; i < line.size(); i++ ){
			if( isalpha(line[i]) ){
				if( !is_letter && newline.size() != 0 ) newline += " ";
				newline += line[i];
				is_letter = true;
			}
			else is_letter = false;
		}
		cout << newline << endl;
	}

	return 0;
}
