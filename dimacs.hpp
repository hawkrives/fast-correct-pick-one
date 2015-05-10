#ifndef PULS_DIMACS
#define PULS_DIMACS true

#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
typedef pair<std::string, vector<std::string>> connection;
typedef std::unordered_map<std::string, vector<std::string>> graph;

graph import_dimacs(std::string fname="adlist.txt") {
	std::ifstream fin(fname);
	std::string temp;
	fin >> temp >> temp;

	int vertices, edges;
	fin >> vertices >> edges;

	graph g;
	std::string edge, source, dest;
	while (fin >> edge >> source >> dest) {
		if (g.count(source)) {
			g.at(source).push_back(dest);
		}
		else {
			g.insert({source, {dest}});
		}
	}


	for (auto conc : g) {
		for (const auto node : conc.second) {
			// cout << conc << node << endl;
			if (g.count(node)) {
				if (find(g.at(node).begin(), g.at(node).end(), conc.first) == g.at(node).end()) {
					g.at(node).push_back(conc.first);
				}
			}
			else {
				g.insert({node, {conc.first}});
			}
		}

		// cout << conc.second << endl;
		// std::sort(conc.second.begin(), conc.second.end());
		// cout << conc.second << endl;
		// auto last = std::unique(conc.second.begin(), conc.second.end());
		// conc.second.erase(last, conc.second.end());
	}

	// cout << g << endl;

	return g;
}


#endif // PULS_DIMACS