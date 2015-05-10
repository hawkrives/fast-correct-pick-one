#ifndef PULS_DIMACS
#define PULS_DIMACS true

#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
typedef unordered_map<std::string, vector<std::string>> graph;

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

	return g;
}

#endif // PULS_DIMACS