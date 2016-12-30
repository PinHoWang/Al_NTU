

#include "Router.h"


void
Router::constructGraph()
{

	// Construct Nodes
	for(int j = 0; j < numVTilesm; j++){
		for(int i = 0; i < numHTilesm; i++){

			// Construct NetsNodes
			int flag = 0;
			int id = (numHTilesm * j) + i;
			for(int idNet = 0; idNet < numNets; idNet++)
			{
				NetPos p = netsPos[ idNet ]; 
				// BUG Double Count Nodes
				
				if(i == (p.first).first && j == (p.first).second){
					
					flag = 1;
					NetsNodes* net = new NetsNodes(id, pair<int, int> (i, j), pair<int, int> ( (p.second).first, (p.second).second) );
					netNodesList.push_back(net);
					nodeListAll.push_back(net);
					break;
				}
				else if(i == (p.second).first && j == (p.second).second){
					
					flag = 1;
					NetsNodes* net = new NetsNodes( id, pair<int, int> (i, j), pair<int, int> ( (p.first).first, (p.first).second) );
					netNodesList.push_back(net);
					nodeListAll.push_back(net);
					break;
				}
				

				//cout << "(" << (it->first).first << ", " << (it->first).second << ")" << " "
				//	<< "(" << (it->second).first << ", " << (it->second).second << ")" << endl;
			}

			// Construct Else Nodes
			if(flag == 0){
				RouterNodes* n = new RouterNodes(id, pair<int, int> (i, j));
				nodeList.push_back(n);
				nodeListAll.push_back(n);
			}
		}
	}



	// Contect Nodes
	vector<RouterNodes*>::iterator itLine1;
	vector<RouterNodes*>::iterator itLine2;
	for(itLine1 = nodeListAll.begin(); itLine1 != nodeListAll.end(); itLine1++){
		for(itLine2 = nodeListAll.begin(); itLine2 != nodeListAll.end(); itLine2++){
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


void minOverFlow()
{
	
}

void
Router::Dijkstra()
{

}
