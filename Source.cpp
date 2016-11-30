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

//global structs
struct splitAddress
{
	string page = "", offset = "";
};

//functions
vector<string> getAddresses(vector<string>& addresses, string filename);


// -----------------[MAIN]----------------- //
int main() {
	getAddresses(addresses, infile);
	vector<splitAddress> splitAddresses;
	
	for (vector<string>::iterator it = addresses.begin(); it < addresses.end(); it++) {
		splitAddress temp;
		temp.page = it->substr(0, 8); //0 to 7 does not store 7 for some reason so using 0 to 8
		temp.offset = it->substr(8, 15);
		splitAddresses.push_back(temp);
		cout << *it << ", "  << temp.page << ", " << temp.offset << endl;
	}

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
		
		//cout << *it << endl;
	}
	
	addresses.pop_back(); //for some reason it keeps storing an extra element 0: this gets rid of it

	ifile.close();
	return addresses;

}
