#ifndef STACK_DIRECTEDGRAPH_H
#define STACK_DIRECTEDGRAPH_H

#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include "SingleLinkedList.h"
#include "LinkedStack.h"

using namespace std;

struct Edge {
    int src;
    int dest;
};

class DirectedGraph {
private:
    // A node is represented with a map entry
    // The key of the map entry is the node value
    // The value of the map entry is the "neighbours" of this node.
    // Here a node B is considered a "neighbour" of a node A when there is a edge that goes from A to B
    map<int, SingleLinkedList<int>*> nodes;

	bool VecContains(vector<int>* victor, int key) {
		return find(victor->begin(), victor->end(), key) != victor->end();
	}

	void topSortRecur(int currNode, vector<int>* sorted); 
    void topologySort(int val, LinkedStack<int> &, set<int> &);

public:
    explicit DirectedGraph(Edge *edges, int size);

    void printGraph();

    virtual ~DirectedGraph();

    vector<int> *topologySort();
};

#endif //STACK_DIRECTEDGRAPH_H
