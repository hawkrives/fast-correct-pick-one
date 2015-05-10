#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <unordered_map>
using std::unordered_map;

#include "prettyprint.hpp"
#include "dimacs.hpp"

// Design and implement an algorithm for vertex cover that is fast (but not
// necessarily correct). That is, first find a way to get an initial rough
// guess, and then find a way to improve the solution repeatedly.

// Since VERTEX COVER is a special case of SET COVER , we know from Chapter 5
// that it can be approximated within a factor of O(log n) by the greedy
// algorithm: repeatedly delete the vertex of highest degree and include it in
// the vertex cover. And there are graphs on which the greedy algorithm
// returns a vertex cover that is indeed log n times the optimum.

// A better approximation algorithm for VERTEX COVER is based on the notion of
// a match- ing, a subset of edges that have no vertices in common (Figure
// 9.4). A matching is maximal if no more edges can be added to it. Maximal
// matchings will help us find good vertex covers, and moreover, they are easy
// to generate: repeatedly pick edges that are disjoint from the ones chosen
// already, until this is no longer possible.

graph vertex_cover(graph g) {
	return g;
}

int main(int argc, char const *argv[]) {
	graph g = import_dimacs("test.dimacs");
	cout << g << endl;
	return 0;
}
