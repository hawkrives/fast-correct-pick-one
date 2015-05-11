#ifndef PULS_DIMACS
#define PULS_DIMACS true

#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <utility>
typedef pair<std::string, vector<std::string>> connection;
typedef std::unordered_map<std::string, vector<std::string>> graph;
typedef std::vector<std::pair<std::string, std::string>> list;
typedef std::pair<std::string, std::string> edge;

graph import_dimacs(std::string fname="adlist.txt") {
	std::ifstream fin(fname);
	std::string temp;
	fin >> temp >> temp;

	std::string vertices, edges;
	fin >> vertices >> edges;

	graph g;
	std::string type, source, dest;
	while (fin >> type >> source >> dest) {
		if (g.count(source)) {
			g.at(source).push_back(dest);
		}
		else {
			g.insert({source, {dest}});
		}
	}

	for (auto conc : g) {
		for (const auto node : conc.second) {
			if (g.count(node)) {
				if (find(g.at(node).begin(), g.at(node).end(), conc.first) == g.at(node).end()) {
					g.at(node).push_back(conc.first);
				}
			}
			else {
				g.insert({node, {conc.first}});
			}
		}
	}

	return g;
}

list to_list(graph g) {
	list l;
	for (const connection c : g) {
		for (const string vertex : c.second) {
			l.push_back({c.first, vertex});
		}
	}
	std::sort(l.begin(), l.end(), [](std::pair<std::string, std::string> a, std::pair<std::string, std::string> b) {
		return a.first < b.first;
	});
	return l;
}

#endif // PULS_DIMACS