
#include <iostream>
#include <vector>
#include <time.h>
#include "Parse.h"
#include "Mpsc.h"

int main(int argc, char* argv[])
{

	if(argc != 3)
	{
		cout << "Wrong Input!" << endl;
		cout << "Usage: <Executive file> <Input file> <Output file>" << endl;
		return 0;
	}
	else
	{
		clock_t start, end;
		start = clock();
		Parse p(argv[1], argv[2]);
		int check = p.checkFile(argv[1]);
		if(check == 0) return 0;
	
		p.mapping();
		//cout << p.getVecNum() << endl;
		Mpsc mps(p.getVecNum(), p.getData(), p.getOGData());
		mps.findMaxPlanar();
		mps.getChords();
		map<int, int> c = mps.returnChords();

		//map<int, int>::iterator it;
		//for(it = c.begin(); it != c.end(); it++) cout << it->first << ' ' << it->second << endl;

		p.writeIn(c, mps.numOfMpsc());
		end = clock();
		cout << "Total program time: " << ((float)(end-start)/CLOCKS_PER_SEC) << " seconds."<< endl; 
	}
}
