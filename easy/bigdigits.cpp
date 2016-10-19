#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;
int main( int argc, char * argv[] ){
	ifstream stream(argv[1]);
	string line;
	string nummag[10][6];
	vector< int > numline;

	nummag[0][0] = "-**--";
	nummag[1][0] = "--*--";
	nummag[2][0] = "***--";
	nummag[3][0] = "***--";
	nummag[4][0] = "-*---";
	nummag[5][0] = "****-";
	nummag[6][0] = "-**--";
	nummag[7][0] = "****-";
	nummag[8][0] = "-**--";
	nummag[9][0] = "-**--";

	nummag[0][1] = "*--*-";
	nummag[1][1] = "-**--";
	nummag[2][1] = "---*-";
	nummag[3][1] = "---*-";
	nummag[4][1] = "*--*-";
	nummag[5][1] = "*----";
	nummag[6][1] = "*----";
	nummag[7][1] = "---*-";
	nummag[8][1] = "*--*-";
	nummag[9][1] = "*--*-";

	nummag[0][2] = "*--*-";
	nummag[1][2] = "--*--";
	nummag[2][2] = "-**--";
	nummag[3][2] = "-**--";
	nummag[4][2] = "****-";
	nummag[5][2] = "***--";
	nummag[6][2] = "***--";
	nummag[7][2] = "--*--";
	nummag[8][2] = "-**--";
	nummag[9][2] = "-***-";

	nummag[0][3] = "*--*-";
	nummag[1][3] = "--*--";
	nummag[2][3] = "*----";
	nummag[3][3] = "---*-";
	nummag[4][3] = "---*-";
	nummag[5][3] = "---*-";
	nummag[6][3] = "*--*-";
	nummag[7][3] = "-*---";
	nummag[8][3] = "*--*-";
	nummag[9][3] = "---*-";

	nummag[0][4] = "-**--";
	nummag[1][4] = "-***-";
	nummag[2][4] = "****-";
	nummag[3][4] = "***--";
	nummag[4][4] = "---*-";
	nummag[5][4] = "***--";
	nummag[6][4] = "-**--";
	nummag[7][4] = "-*---";
	nummag[8][4] = "-**--";
	nummag[9][4] = "-**--";

	nummag[0][5] = "-----";
	nummag[1][5] = "-----";
	nummag[2][5] = "-----";
	nummag[3][5] = "-----";
	nummag[4][5] = "-----";
	nummag[5][5] = "-----";
	nummag[6][5] = "-----";
	nummag[7][5] = "-----";
	nummag[8][5] = "-----";
	nummag[9][5] = "-----";

	while( getline(stream,line) ){
		for( int i = 0; i < line.length(); i++ ){
			int num = line[i] - '0';
			if( num >= 0 && num < 10 ){
			//	cout << num;
				numline.push_back(num);
			}
		}
		//cout << endl;
		for( int j = 0; j < 6; j++ ){
			for( int i = 0; i < numline.size(); i++ ){
				cout << nummag[numline[i]][j];
			}
			cout << endl;
		}
		numline.clear();
	}

}
