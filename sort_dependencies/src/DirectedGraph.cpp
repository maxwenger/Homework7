#include "DirectedGraph.h"

DirectedGraph::DirectedGraph(Edge *edges, int size) {
    for (int i = 0; i < size; i++) {

        int src = edges[i].src, dest = edges[i].dest;
        if (nodes.count(src) == 0) {
            nodes[src] = new SingleLinkedList<int>();
        }

        nodes[src]->add(dest);

        if (nodes.count(dest) == 0) {
            nodes[dest] = new SingleLinkedList<int>();
        }
    }
}

DirectedGraph::~DirectedGraph() {
    for (auto it = nodes.begin(); it != nodes.end(); it++) {
        delete (*it).second;
    }
}

void DirectedGraph::printGraph() {
    for (auto it = nodes.begin(); it != nodes.end(); it++) {
        printf("node(%d) has edges: ", (*it).first);
        for (auto itl = (*it).second->begin(); itl != (*it).second->end(); itl++) {
            printf("%d ", (*itl));
        }
        printf("\n");
    }
}

int DirectedGraph::topSortRecur(int vectorIndex, int visitingIndex, vector<int> visited, int currentKey, LinkedStack<int>* sorted) {
	visited.push_back(currentKey);

	vector<int>* dests = nodes[currentKey].toVector(); 
	for(int const& dest : dests) {
		if(!VecContains(visited, dest) {
				topSortRecur(

	return 0;
}

vector<int>* DirectedGraph::topologySort() {
	int size = nodes.size();
	vector<int> visited; 

	LinkedStack<int>* sorted = new LinkedStack<int>;
	int i = size-1; // index for the vector. We are gonna treat it like a stack.

	// maps dont like to be accessed by index, so Im doing this.
	// Another way I could do it (and prob. more corrcet) would be to
	// make a visited map where the key is the nodes key, and the value
	// is a bool. But arrays are smaller and nicer to work with, so ill be a bit
	// hacky about it.
	int curr = 0;
	for(auto const& it : nodes) {
		if(!VecContains(visited, it.first)) {
			i = topSortRecur(i, curr, visited, it.first, sorted);
		}
		curr++;
	}

	return sorted;
}

