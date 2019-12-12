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

void DirectedGraph::topSortRecur(int currNode, vector<int>* sorted) {
	vector<int> edges = nodes[currNode]->toVector();
	for(auto const& edge : edges) {
		if(!VecContains(sorted, edge)) {
			topSortRecur(edge, sorted);
		}
	}

	sorted->push_back(currNode);
}

vector<int>* DirectedGraph::topologySort() {
	vector<int>* sorted = new vector<int>;

	for(auto const& it : nodes) {
		if(!VecContains(sorted, it.first)) {
			topSortRecur(it.first, sorted);
		}
	}

	reverse(sorted->begin(), sorted->end());

	return sorted;
}

