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
#include <algorithm>
using std::sort;
using std::distance;
using std::max_element;
using std::copy;
using std::remove_if;
#include <iterator>
using std::back_inserter;
#include <utility>
using std::pair;

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
// a matching, a subset of edges that have no vertices in common (Figure
// 9.4). A matching is maximal if no more edges can be added to it. Maximal
// matchings will help us find good vertex covers, and moreover, they are easy
// to generate: repeatedly pick edges that are disjoint from the ones chosen
// already, until this is no longer possible.



vector<string> vertex_cover(const graph g) {
	vector<connection> list;
	copy(g.begin(), g.end(), back_inserter(list));

	sort(list.begin(), list.end(), [](connection a, connection b) {
		return a.second.size() > b.second.size();
	});

	// cout << list << endl;

	vector<string> cover;
	while (list.size()) {
		connection max = list.at(0);
		cover.push_back(max.first);

		list.erase(list.begin());
		// cout << "here " << list << endl;

		for (string conc : max.second) {
			// cout << "here 2 " << list << " " << conc << endl;
			if (!list.size())
				break;

			auto to_remove = find_if(list.begin(), list.end(), [conc](connection c) {
				// cout << conc << " " << c.first << endl;
				return c.first == conc;
			});

			if (to_remove != list.end()) {
				list.erase(to_remove);
			}
			// cout << "here 3 " << list << endl;
		}

		// cout << list << endl;
	}

	return cover;
}

int main(int argc, char const *argv[]) {
	if (argc < 2) {
		cerr << "Usage: " << argv[0] << " dimacs_file" << endl;
		return 0;
	}

	graph g = import_dimacs(argv[1]);
	// cout << "graph " << g << endl;
	vector<string> cover = vertex_cover(g);
	cout << cover << endl;
	return 0;
}
