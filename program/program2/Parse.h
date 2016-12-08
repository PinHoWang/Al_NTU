
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
using namespace std;

class Parse
{

public:
	
	Parse(string inputFile, string outputFile) {input = inputFile; output = outputFile;}
	~Parse() {}

	int checkFile(string in)
	{

		std::ifstream infile(in.c_str());

		if(!infile)
		{
			cout << "Error: Can't open file." << endl << endl;
			return 0;
		}else return 1;
	}
	
	void mapping()
	{
		string line;
		std::ifstream infile(input.c_str());

		if(!infile)
		{
			cout << "Can't open file." << endl;
		}
		else
		{
			string s, first, second;
			while(getline(infile, line, '\n'))
			{
				stringstream data(line);
				int count = 0;
				first = "-1";
				second = "-1";
				while(getline(data, s, ' '))
				{
					if(count == 0) first = s;
					else second = s;
					count++;
				}

				if(second != "-1")
					_map.insert(pair<int, int>(atoi(first.c_str()), atoi(second.c_str())));
					_OGmap.insert(pair<int, int>(atoi(first.c_str()), atoi(second.c_str())));
			}
		}



		map<int, int>::iterator it;
		for(it = _map.begin(); it != _map.end(); it++)
			_map.insert(pair<int, int>(it->second, it->first));


		infile.close();
	}

	int getVecNum()
	{
		map<int, int>::reverse_iterator iter_r;
		iter_r = _map.rbegin();
		Vectex = iter_r->first + 1;
		return Vectex;
	}

	map<int, int> getData()
	{
		return _map;
	}

	map<int, int> getOGData()
	{
		return _OGmap;
	}

	void writeIn(map<int, int> data, int num)
	{
		ofstream outfile(output.c_str());

		outfile << num << endl;

		map<int, int>::iterator it;
		for(it = data.begin(); it != data.end(); it++)
			outfile << it->first << ' ' << it->second << '\n';

		outfile.close();
	}

private:
	
	string input, output; // Record argv[1] : Input file
	map<int, int> _map;
	map<int, int> _OGmap;
	int Vectex;

};
