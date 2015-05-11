CXX := g++
CXXFLAGS := -Wall -g --std=c++11

all: fast-test correct-test

TESTS = \
	./$< test.col \
	./$< bigger.col \
	./$< size-8.col \
	./$< octo.col

fast-test: fast.out
	time ./$< test.col
	time ./$< bigger.col
	time ./$< size-8.col
	time ./$< octo.col

correct-test: correct.out
	time ./$< test.col
	time ./$< bigger.col
	time ./$< size-8.col
	time ./$< octo.col

fast.out: fast.cpp prettyprint.hpp dimacs.hpp
	$(CXX) $(CXXFLAGS) $< -o $@

correct.out: correct.cpp prettyprint.hpp dimacs.hpp combinations.hpp
	$(CXX) $(CXXFLAGS) $< -o $@

blah.out: blah.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

dimacs-to-svg: dimacs-to-svg.cpp dimacs-to-svg.hpp
	$(CXX) $(CXXFLAGS) $< -o $@