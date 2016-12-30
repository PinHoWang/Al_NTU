
#include <vector>
#include <limits.h>
using namespace std;


class RouterNodes;

typedef pair<int,int>	Pos;
typedef pair<Pos,Pos> 	NetPos;



/*==========//
//	Router  //
//==========*/
class RouterNodes
{

public:

	vector<RouterNodes*> adjList;

	RouterNodes(int id, Pos p) { nodeId = id; position = p; d = INT_MAX; }
	
	pair<int, int> getPosition() { return position; }
	int getNodeId() { return nodeId; }

protected:

	int nodeId;
	Pos position;
	int d;
	RouterNodes*	preDecessor;


};


/*=============//
//	NetsNodes  //
//=============*/
class NetsNodes : public RouterNodes
{

public:

	NetsNodes(int id, Pos p, Pos corP) : RouterNodes(id, p) 
		{ nodeId = id; position = p; d = INT_MAX; corrNet = corP; }
	Pos getCorrNet() { return corrNet; }

private:

	Pos corrNet;
};