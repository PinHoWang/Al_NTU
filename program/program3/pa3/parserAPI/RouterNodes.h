
#include <vector>
using namespace std;

class RouterNodes;

typedef pair<int,int>	Pos;
typedef pair<Pos,Pos> 	NetPos;

class RouterNodes
{

public:

	vector<RouterNodes*> adjList;

	RouterNodes(int id, Pos p) { nodeId = id; position = p; }
	
	pair<int, int> getPosition() { return position; }
	int getNodeId() { return nodeId; }

protected:

	int nodeId;
	Pos position;

};


class NetsNodes : public RouterNodes
{

public:

	NetsNodes(int id, Pos p) : RouterNodes(id, p) { nodeId = id; position = p; }
private:

};