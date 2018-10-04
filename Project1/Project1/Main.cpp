///this programm reads in a number of words from a file and then seaches a second file to see how many times they are used , then displays the results in a new file.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//the number of words being checked and the max words in the 
int NumOfWords = 10;
const int MaxWords = 1024;

//vector for the words from the file and the number of times their found in the other file
vector<string> Words;
vector<int> Occurences;

void main() {
	Words.clear();
	Occurences.clear();

	//open a file for reading 
	ifstream infile1;
	infile1.open("inputfile1.txt");

	// gets the words from the first file and puts them into the corrosponding vector
	for (int i=0; i < NumOfWords; i++) {
		int numofOccurence = 0;

		if (!infile1.eof()) {
			string temp;
			infile1 >> temp;
			Words.push_back(temp);
			cout << temp << endl;

			//opens another file for reading, and then checks the word agaisnt the words in that file
			ifstream infile2;
			infile2.open("inputfile2.txt");
			for (int x = 0; x < MaxWords; x++) {
				if(!infile1.eof())
				{
					string temp2;
					infile2 >> temp2;
					if (temp2 == Words[i]) {
						numofOccurence++;
					}
					
				}
				else if (infile1.eof()) { break; }
			}
			infile2.close();

			// adds the number of times it  was found to the corrosponding vector
			Occurences.push_back(numofOccurence);
		}
	}

	// opens a file for wrighting and adds the words and the ocurences from the two vectors to the new file
	ofstream ofile;
	ofile.open("outputfile.txt");
	for (int i = 0; i < NumOfWords; i++) {
		ofile << Words[i] << " is found : " << Occurences[i] << " number of times." << endl;
		cout << Words[i] << " is found : " << Occurences[i] << " number of times." << endl;
	}
	ofile.close();
	infile1.close();

	system("pause");
 }