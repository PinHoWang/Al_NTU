
#include <iostream>
#include <vector>
#include "RouterNodes.h"
using namespace std;

typedef pair<int,int>	Pos;
typedef pair<Pos,Pos> 	NetPos;


class Router
{

public:

	Router(int numH, int numV, int c, int numN, vector<NetPos> nP)
		{ numHTilesm = numH;  numVTilesm = numV; capacity = c; numNets = numN;
			netsPos = nP; }
	
	void constructGraph();




	/*==================//
	//	Test Functions	//
	//==================*/

	void printNodes() 
	{
		vector<RouterNodes*>::iterator it;
		int count = 0;
		for(it = nodeList.begin(); it != nodeList.end(); it++)
		{
			cout << "Node ID: " << (*it)->getNodeId() << endl
			<< "Node Position: (" << ((*it)->getPosition()).first << ", " 
			<< ((*it)->getPosition()).second << ")" << endl;
			count++;
		}

		cout << endl << "# of Nodes: " << count << endl;
	}

private:

	int numHTilesm, numVTilesm, capacity, numNets;
    vector<NetPos> 		netsPos;
    vector<RouterNodes*> nodeList;

};

