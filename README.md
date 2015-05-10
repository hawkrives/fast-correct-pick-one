# fast-correct-pick-one

This project consists of two phases:

1. Design and implement an algorithm for vertex cover that is fast (but not necessarily correct). That is, first find a way to get an initial rough guess, and then find a way to improve the solution repeatedly.

2. Design and implement an algorithm for vertex cover that is correct (but not necessarily fast). In particular, design a branch-and-bound approach (section 9.1.2) that is quick to reject areas of the solution space that cannot contain an answer better than the best answer found so far. In this way, your algorithm should be designed to run fast on simple instances while still guaranteeing correctness.
