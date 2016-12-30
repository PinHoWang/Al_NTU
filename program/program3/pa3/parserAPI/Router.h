
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
			netsPos = nP;
			weight = new float*[numH];
			for(int i = 0; i < numH; i++) weight[i] = new float[numV];

			for(int i = 0; i < numH; i++)
				for(int j = 0; j < numV; j++) weight[i][j] = 0;
		}
	
	~Router() { delete [] weight; }

	void constructGraph();
	void minOverFlow();
	void Dijkstra();
	 


	/*==================//
	//	Test Functions	//
	//==================*/
	/*
	void printNodes() 
	{
		vector<NetsNodes*>::iterator it;
		int count = 0;
		for(it = netNodesList.begin(); it != netNodesList.end(); it++)
		{
			cout << "Node ID: " << (*it)->getNodeId() << endl
			<< "Node Position: (" << ((*it)->getPosition()).first << ", " 
			<< ((*it)->getPosition()).second << ")" << endl;

			int size = ((*it)->adjList).size();
			cout <<  "AdjList: "; 
			for(int i=0; i<size; i++) 
				cout << ((*it)->adjList)[i]->getNodeId() << " ";
			Pos p = (*it)->getCorrNet();
			cout << endl << "Corresponding Net: (" << p.first << ", " << p.second << ")" << endl;
			count++;
			cout << endl << endl;
		}

		cout << endl << "# of Nodes: " << count << endl;
	}
	*/

private:

	int numHTilesm, numVTilesm, capacity, numNets;
    vector<NetPos> 			netsPos;
    vector<RouterNodes*>	nodeList;
    vector<RouterNodes*>	nodeListAll;
    vector<NetsNodes*>		netNodesList;
    float**	weight;

};

