#include <fstream>
#include <iostream>
#include <string>
#include <regex>
#include <locale>

using namespace std;
int main( int argc, char * argv[] ){
	ifstream stream(argv[1]);
	string line;
	string newline;
	regex not_letters("[^a-zA-Z]");
	regex lead_ws("^\\s+");
	regex trail_ws("\\s+$");
	regex mulitple_ws("[ ]{2,}");

	auto& f = use_facet<ctype<char> >(locale());

	while( getline( stream, line ) ){
		newline = regex_replace(
			  line
			, not_letters
			, " "
		);
		newline = regex_replace(
			  newline
			, lead_ws
			, ""
		);
		newline = regex_replace(
			  newline
			, trail_ws
			, ""
		);
		newline = regex_replace(
			  newline
			, mulitple_ws
			, " "
		);
		f.tolower(&newline[0],&newline[0]+newline.size());
		cout << newline << endl;
	}
	
	return 0;
}
