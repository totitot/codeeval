#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main( int argc, char* argv[] ){
	ifstream file(argv[1]);
	string line;

	while( getline( file, line ) ){
		int num_arrows = 0;
		string::size_type pos = 0;
		pos = line.find("<");
		while (pos != string::npos){
			if( line.substr(pos,5) == "<--<<" ) num_arrows++;
			pos = line.find("<",pos+1);
		}
		pos = line.find(">");
		while (pos != string::npos){
			if( line.substr(pos,5) == ">>-->" ) num_arrows++;
			pos = line.find(">",pos+1);
		}
		cout << num_arrows << endl;
	}
	return 0;
}
