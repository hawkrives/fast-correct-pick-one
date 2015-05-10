CXX := g++
CXXFLAGS := -Wall -g --std=c++11

all: fast-test correct-test

fast-test: fast.out
	./$<

correct-test: correct.out
	./$<

fast.out: fast.cpp prettyprint.hpp dimacs.hpp
	$(CXX) $(CXXFLAGS) $< -o $@
correct.out: correct.cpp prettyprint.hpp dimacs.hpp
	$(CXX) $(CXXFLAGS) $< -o $@
