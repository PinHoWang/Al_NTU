

#include "Router.h"


void
Router::constructGraph()
{

	// Construct Nodes
	vector<NetPos>::iterator it;
	for(int j = 0; j < numVTilesm; j++){
		for(int i = 0; i < numHTilesm; i++){

			// Construct NetsNodes
			int flag = 0;
			int id = (numHTilesm * j) + i;
			for(it = netsPos.begin(); it != netsPos.end(); it++)
			{

				// BUG Double Count Nodes

				flag = 1;
				if(i == ((*it).first).first && j == ((*it).first).second){
					
					NetsNodes* net = new NetsNodes(id, pair<int, int> (i, j));
					nodeList.push_back(net);
				}
				else if(i == ((*it).second).first && j == ((*it).second).second){
					
					NetsNodes* net = new NetsNodes(id, pair<int, int> (i, j));
					nodeList.push_back(net);
				}
				else { break; }
			}

			// Construct Else Nodes
			if( flag == 0){
				RouterNodes* n = new RouterNodes(id, pair<int, int> (i, j));
				nodeList.push_back(n);
			}
		}
	}



	// Contect Nodes
	vector<RouterNodes*>::iterator itLine1;
	vector<RouterNodes*>::iterator itLine2;
	for(itLine1 = nodeList.begin(); itLine1 != nodeList.end(); itLine1++){
		for(itLine2 = nodeList.begin(); itLine2 != nodeList.end(); itLine2++){
			if( (((*itLine1)->getPosition()).first + 1 == ((*itLine2)->getPosition()).first) 
				&&  (((*itLine1)->getPosition()).second  == ((*itLine2)->getPosition()).second)
				)
			{
				((*itLine1))->adjList.push_back((*itLine2));
			}
			else if( (((*itLine1)->getPosition()).first  == ((*itLine2)->getPosition()).first) 
				&&  (((*itLine1)->getPosition()).second + 1 == ((*itLine2)->getPosition()).second)
				)
			{
				((*itLine1)->adjList).push_back((*itLine2));
			}
			else if( (((*itLine1)->getPosition()).first - 1 == ((*itLine2)->getPosition()).first) 
				&&  (((*itLine1)->getPosition()).second  == ((*itLine2)->getPosition()).second)
				)
			{
				((*itLine1)->adjList).push_back((*itLine2));
			}
			else if( (((*itLine1)->getPosition()).first  == ((*itLine2)->getPosition()).first) 
				&&  (((*itLine1)->getPosition()).second - 1 == ((*itLine2)->getPosition()).second)
				)
			{
				((*itLine1)->adjList).push_back((*itLine2));
			}
			
		}
	}
}

