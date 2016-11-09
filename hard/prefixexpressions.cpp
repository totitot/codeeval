#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main( int argc, char** argv ){
	ifstream file(argv[1]);
	string line, thingies;
	vector<unsigned int> vi;
	vector<string> reverse_line;

	while( getline( file, line ) ){
		vi.clear();
		reverse_line.clear();
		istringstream ss(line);
		while( ss >> thingies ) reverse_line.push_back(thingies);
		for( int i = reverse_line.size()-1; i > 0; i-- ){
			if( reverse_line[i] == "*" ){
				unsigned int num = vi.back(); vi.pop_back();
				vi.back() *= num;
			}
			else if( reverse_line[i] == "+" ){
				unsigned int num = vi.back(); vi.pop_back();
				vi.back() += num;
			}
			else if( reverse_line[i] == "/" ){
				unsigned int num = vi.back(); vi.pop_back();
				vi.back() = num / vi.back();
			}
			else{
				vi.push_back(stoi(reverse_line[i]));
			}
			reverse_line.pop_back();
		}
		cout << vi.back() << endl;
	}
}
