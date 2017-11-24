#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;
int main( int argc, char * argv[] ){
	ifstream stream(argv[1]);
	string line;
	int num, bit1, bit2;
	string str;

	while( getline(stream,line) ){
		string::size_type pos = line.find(",");
		while(pos != string::npos){
			line.replace(pos,1," ");
			pos = line.find(",");
		}

		istringstream iss(line);
		iss >> str;
		num = stoul(str,0,10);
		iss >> str;
		bit1 = stoul(str,0,10);
		bit1 = (num >> (bit1-1))&1;
		iss >> str;
		bit2 = stoul(str,0,10);
		bit2 = (num >> (bit2-1))&1;

		cout << ((bit1 == bit2)?"true":"false") << endl;
	}

}
