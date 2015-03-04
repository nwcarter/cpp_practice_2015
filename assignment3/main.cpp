#include <iostream>
#include <string>
#include <vector>
#include "FileReader.h"
#include "StringFunctions.h"
using namespace std;

const int OFFSET = 65;

void readFile(string filename, vector<int>& library);
void initVector(vector<int>& v);
int getCount(vector<int> v, char ch);

int main(int argc, char const *argv[])
{
	vector<int> library(26);
	initVector(library);
	readFile("wordlist.txt", library);
	string input = "";

	while(input != "q")
	{
		cout << "Enter a capital letter from A-Z or q to quit: ";
		getline(cin, input);

		if (input != "q")
		{
			input = StringFunctions::toupper(input);
			cout << "There are " << getCount(library, input[0]) << " words in the file that start with " << input[0] << "." << endl;
		}
		else
		{
			cout << "Bye!" << endl;
		}
	}




	/*
	char ch = 'A';
	for (int x(0); x < library.size(); x++)
	{
		cout << ch << "->" << library[x] << endl;
		ch = ch + 1;
	}
	*/
	return 0;
}
void readFile(string filename, vector<int>& library)
{
	FileReader file(filename);
	string line = "";
	
	while(!file.endOfFile())
	{
		line = StringFunctions::toupper(file.readLine());
		if (!line.empty())
		{
			library[line[0] - OFFSET] += 1;
		}
	}

	
}
void initVector(vector<int>& v)
{
	for(int x(0); x < v.size(); x++)
	{
		v[x] = 0;
	}
}
int getCount(vector<int> v, char ch)
{
	return v[ch - OFFSET];
}
