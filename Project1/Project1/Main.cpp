#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int NumOfWords = 10;
const int MaxWords = 1024;
vector<string> Words;
vector<int> Occurences;

void main() {
	Words.clear();
	Occurences.clear();
	
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

				string temp2;
				infile2 >> temp2;
				if (temp2 == Words[i]) {
					numofOccurence++;
				}
				 
			}
			infile2.close();
			Occurences.push_back(numofOccurence);
		}
	}

	ofile.open("outputfile.txt");
	for (int i = 0; i < NumOfWords; i++) {
		ofile << Words[i] << " is found : " << Occurences[i] << " number of times." << endl;
		cout << Words[i] << " is found : " << Occurences[i] << " number of times." << endl;
	}
	ofile.close();
	infile1.close();
	system("pause");
 }