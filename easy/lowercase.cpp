#include <fstream>
#include <iostream>
#include <string>
#include <locale>

using namespace std;
int main( int argc, char * argv[] ){
	ifstream stream(argv[1]);
	string line;

	auto& f = use_facet<ctype<char> >(locale());

	while( getline( stream, line ) ){
		f.tolower(&line[0],&line[0]+line.size());
		cout << line << endl;
	}

	return 0;
}
