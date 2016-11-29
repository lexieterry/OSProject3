#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <bitset>

using namespace std;

//globals
string infile = "addresses.txt";
vector<string> addresses;

//functions
vector<string> getAddresses(vector<string>& addresses, string filename);


// -----------------[MAIN]----------------- //
int main() {
	getAddresses(addresses, infile);

	system("pause");
	return 0;
}


// -----------------[FUNCTIONS]----------------- //
vector<string> getAddresses(vector<string>& addresses, string filename)
{
	ifstream ifile;
	string r;
	 
	//int n;

	ifile.open(filename);

	while (!ifile.eof()) //collect addresses and store them as strings
	{
		string temp;
		ifile >> temp;
		addresses.push_back(temp);
	}	
	
	//int i = 0; //counter
	for (vector<string>::iterator it = addresses.begin(); it < addresses.end(); it++) //convert to 16 bit binary
	{
		unsigned int temp = 0;
		stringstream convert(*it);
		convert >> temp;
		*it = bitset<16>(temp).to_string();

	}
	
	
	//mask
	/*

		fun masking code goes here
	
	*/


	ifile.close();
	return addresses;

}
