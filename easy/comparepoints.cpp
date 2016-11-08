#include <fstream>
#include <iostream>

using namespace std;

int main( int argc, char* argv[] ){
	ifstream stream( argv[1] );
	int x1,y1,x2,y2;

	while( stream >> x1 >> y1 >> x2 >> y2 ){
		if( x1 == x2 && y1 == y2 ) cout << "here" << endl;
		else{
			if( y1 < y2 ) cout << "N";
			if( y1 > y2 ) cout << "S";
			if( x1 < x2 ) cout << "E";
			if( x1 > x2 ) cout << "W";
			cout << endl;
		}
	}

	return 0;
}
