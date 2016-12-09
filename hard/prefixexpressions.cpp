#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main( int argc, char** argv ){
	ifstream file(argv[1]);
	string line, thingies;
	vector<unsigned long long> vi;
	vector<string> reverse_line;

	while( getline( file, line ) ){
		vi.clear();
		reverse_line.clear();
		istringstream ss(line);
		while( ss >> thingies ) reverse_line.push_back(thingies);
		while( reverse_line.size() ){
			if( reverse_line.back() == "*" ){
				unsigned long long num = vi.back(); vi.pop_back();
				vi.back() *= num;
			}
			else if( reverse_line.back() == "+" ){
				unsigned long long num = vi.back(); vi.pop_back();
				vi.back() += num;
			}
			else if( reverse_line.back() == "/" ){
				unsigned long long num = vi.back(); vi.pop_back();
				vi.back() = num / vi.back();
			}
			else{
				vi.push_back(stoi(reverse_line.back()));
			}
			reverse_line.pop_back();
		}
		cout << vi.back() << endl;
	}
}
