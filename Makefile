CFLAGS = -std=c++11 -g -fsanitize=address,leak

OBJS =
BINS =
TESTS =

BINS += 0004/merge_and_sort
0004/merge_and_sort: 0004/merge_and_sort.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0018/brute_force
0018/brute_force: 0018/brute_force.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0018/recursive_2sum
0018/recursive_2sum: 0018/recursive_2sum.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0049/solution
0049/solution: 0049/solution.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0053/dp
0053/dp: 0053/dp.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0062/dp_matrix
0062/dp_matrix: 0062/dp_matrix.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0062/dp_two_vec
0062/dp_two_vec: 0062/dp_two_vec.rs
	rustc -o $@ $^

BINS += 0063/dp_matrix
0063/dp_matrix: 0063/dp_matrix.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0063/dp_two_vec
0063/dp_two_vec: 0063/dp_two_vec.rs
	rustc -o $@ $^

BINS += 0083/linked_list
0083/linked_list: 0083/linked_list.cpp leetcode/linked_list.o
	g++ $(CFLAGS) -o $@ $^

BINS += 0089/recursion
0089/recursion: 0089/recursion.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0104/dfs
0104/dfs: 0104/dfs.cpp leetcode/tree.o
	g++ $(CFLAGS) -o $@ $^

BINS += 0139/dp
0139/dp: 0139/dp.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0129/dfs
0129/dfs: 0129/dfs.cpp leetcode/tree.o
	g++ $(CFLAGS) -o $@ $^

BINS += 0139/dfs
0139/dfs: 0139/dfs.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0151/solution
0151/solution: 0151/solution.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0153/binary_search
0153/binary_search: 0153/binary_search.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0191/solution
0191/solution: 0191/solution.cpp
	g++ $(CFLAGS) -o $@ $?

BINS += 0191/n_AND_n-1
0191/n_AND_n-1: 0191/n_AND_n-1.cpp
	g++ $(CFLAGS) -o $@ $?

BINS += 0268/sum
0268/sum: 0268/sum.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0297/bfs
0297/bfs: 0297/bfs.cpp leetcode/tree.o
	g++ $(CFLAGS) -o $@ $^

BINS += 0297/dfs
0297/dfs: 0297/dfs.cpp leetcode/tree.o
	g++ $(CFLAGS) -o $@ $^

BINS += 0300/dp
0300/dp: 0300/dp.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0392/linear_search
0392/linear_search: 0392/linear_search.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0392/follow_up
0392/follow_up: 0392/follow_up.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0799/dp
0799/dp: 0799/dp.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0849/linear_search
0849/linear_search: 0849/linear_search.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 1221/solution
1221/solution: 1221/solution.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 1222/solution
1222/solution: 1222/solution.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 1223/solution
1223/solution: 1223/solution.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 1224/solution
1224/solution: 1224/solution.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 1252/solution
1252/solution: 1252/solution.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 1253/solution
1253/solution: 1253/solution.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 1254/solution
1254/solution: 1254/solution.cpp
	g++ $(CFLAGS) -o $@ $?

BINS += 1255/backtracking
1255/backtracking: 1255/backtracking.cpp
	g++ $(CFLAGS) -o $@ $^

OBJS += leetcode/tree.o
leetcode/tree.o: leetcode/tree.cpp
	g++ $(CFLAGS) -o $@ -c $?

OBJS += leetcode/linked_list.o
leetcode/linked_list.o: leetcode/linked_list.cpp
	g++ $(CFLAGS) -o $@ -c $?

TESTS += test/linked_list_test
test/linked_list_test: test/linked_list_test.cpp leetcode/linked_list.o
	g++ -o $@ $^ $(CFLAGS) -Igtest/include -Lgtest/lib -lgtest -lgtest_main -lpthread

TESTS += test/tree_test
test/tree_test: test/tree_test.cpp leetcode/tree.o
	g++ -o $@ $^ $(CFLAGS) -Igtest/include -Lgtest/lib -lgtest -lgtest_main -lpthread

.PHONY: all
all: $(BINS) $(TESTS)

.PHONY: runall
runall: $(BINS)
	@$(foreach BIN,$(BINS),$(BIN);)

.PHONY: check
check: $(TESTS)
	@$(foreach TEST,$(TESTS),$(TEST);)

.PHONY: clean
clean:
	rm -f $(OBJS) $(BINS) $(TESTS)
