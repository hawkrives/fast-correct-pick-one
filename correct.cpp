#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <set>
using std::set;
#include <unordered_map>
using std::unordered_map;
#include <algorithm>
using std::remove_if;
using std::remove;
using std::next_permutation;
#include <utility>
using std::pair;

#include "combinations.hpp"
#include "prettyprint.hpp"
#include "dimacs.hpp"

// Design and implement an algorithm for vertex cover that is correct (but not
// necessarily fast). In particular, design a branch-and-bound approach
// (section 9.1.2) that is quick to reject areas of the solution space that
// cannot contain an answer better than the best answer found so far. In this
// way, your algorithm should be designed to run fast on simple instances
// while still guaranteeing correctness.

pair<int, int> maximal_match(list l) {
	int edges = 0;
	while (l.size()) {
		edges++;
		// cout << l << endl;
		pair<string, string> outer = l.at(0);
		// cout << outer << endl;
		l.erase(remove(l.begin(), l.end(), outer), l.end());
		for (pair<string, string> inner : l) {
			l.erase(remove_if(l.begin(), l.end(), [outer](pair<string, string> inner) {
				return (outer.first == inner.first) || (outer.second == inner.first) || (outer.first == inner.second) || (outer.second == inner.second);
			}), l.end());
		}
	}
	int min = edges;
	int max = edges * 2;
	return {min, max};
}

bool is_cover(const vector<string> vertices, list l) {
	for (const string v : vertices) {
		for (pair<string, string> inner : l) {
			l.erase(remove_if(l.begin(), l.end(), [v](pair<string, string> inner) {
				return (v == inner.first) || (v == inner.second);
			}), l.end());
		}
	}
	return !l.size();
}

vector<string> get_vertices(const list l) {
	set<string> vertices;
	for (const auto v : l)
		vertices.insert(v.first);
	vector<string> vs;
	for (const auto v : vertices)
		vs.push_back(v);
	return vs;
}

int main(int argc, char const *argv[]) {
	if (argc < 2) {
		cerr << "Usage: " << argv[0] << " dimacs_file" << endl;
		return 0;
	}

	list l = to_list(import_dimacs(argv[1]));
	vector<string> vertices = get_vertices(l);

	pair<int, int> minmax = maximal_match(l);
	for (int i = minmax.first; i <= minmax.second; i++) {
		auto combos = Combinations<string>(vertices, i);
		for (const vector<string> combo : combos) {
			if (is_cover(combo, l)) {
				cout << combo << endl;
				cout << "SUCCESS!!!" << endl;
				return 0;
			}
		}
	}

	return 0;
}
