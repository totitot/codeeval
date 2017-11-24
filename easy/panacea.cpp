#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;
int main( int argc, char * argv[] ){
	ifstream stream(argv[1]);
	string line;
	int i,j;
	string str;

	while( getline(stream,line) ){
		i = j = 0;
		istringstream iss(line.substr(0,line.find("|")));
		istringstream iss2(line.substr(line.find("|")+2));
		
		while( iss >> str ){
			i += stoull(str,0,16);
		}

		while( iss2 >> str ){
			j += stoull(str,0,2);
		}

		cout << (i<=j?"True":"False") << endl;

	}

}
