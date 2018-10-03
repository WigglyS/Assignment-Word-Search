#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int NumOfWords = 10;
const int MaxWords = 1024;
vector<string> Words;

void main() {
	Words.clear();
	
	ofstream ofile;

	ifstream infile1;
	infile1.open("inputfile1.txt");
	for (int i=0; i < NumOfWords; i++) {
		int numofOccurence = 0;

		if (!infile1.eof()) {
			string temp;
			infile1 >> temp;
			Words.push_back(temp);
			cout << temp << endl;

			ifstream infile2;
			infile2.open("inputfile2.txt");
			for (int x = 0; x < MaxWords; x++) {

				string temp;
				infile2 >> temp;
				if (temp == Words[i]) {
					numofOccurence++;
				}
				 
			}
			infile2.close();

			ofile.open("outputfile.txt",ofstream::app);
			ofile << Words[i] << " is found : " << numofOccurence << " number of times." << endl;
			cout << Words[i] << " is found : " << numofOccurence << " number of times." << endl;
			
		}
	}
	ofile.close();
	infile1.close();
	system("pause");
 }