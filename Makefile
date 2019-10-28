OBJS =
BINS =
TESTS =

BINS += 0004/merge_and_sort
0004/merge_and_sort: 0004/merge_and_sort.cpp
	g++ -std=c++11 -o $@ $^

BINS += 0018/brute_force
0018/brute_force: 0018/brute_force.cpp
	g++ -std=c++11 -o $@ $^

BINS += 0018/recursive_2sum
0018/recursive_2sum: 0018/recursive_2sum.cpp
	g++ -std=c++11 -o $@ $^

BINS += 0049/solution
0049/solution: 0049/solution.cpp
	g++ -std=c++11 -o $@ $^

BINS += 0053/dp
0053/dp: 0053/dp.cpp
	g++ -std=c++11 -o $@ $^

BINS += 0062/dp_matrix
0062/dp_matrix: 0062/dp_matrix.cpp
	g++ -std=c++11 -o $@ $^

BINS += 0062/dp_two_vec
0062/dp_two_vec: 0062/dp_two_vec.rs
	rustc -o $@ $^

BINS += 0063/dp_matrix
0063/dp_matrix: 0063/dp_matrix.cpp
	g++ -std=c++11 -o $@ $^

BINS += 0063/dp_two_vec
0063/dp_two_vec: 0063/dp_two_vec.rs
	rustc -o $@ $^

BINS += 0083/linked_list
0083/linked_list: 0083/linked_list.cpp leetcode/linked_list.o
	g++ -std=c++11 -o $@ $^

BINS += 0089/recursion
0089/recursion: 0089/recursion.cpp
	g++ -std=c++11 -o $@ $^

BINS += 0104/dfs
0104/dfs: 0104/dfs.cpp leetcode/tree.o
	g++ -std=c++11 -g -fsanitize=address,leak -o $@ $^

BINS += 0139/dp
0139/dp: 0139/dp.cpp
	g++ -std=c++11 -o $@ $^

BINS += 0129/dfs
0129/dfs: 0129/dfs.cpp leetcode/tree.o
	g++ -std=c++11 -o $@ $^

BINS += 0139/dfs
0139/dfs: 0139/dfs.cpp
	g++ -std=c++11 -o $@ $^

BINS += 0151/solution
0151/solution: 0151/solution.cpp
	g++ -std=c++11 -o $@ $^

BINS += 0153/binary_search
0153/binary_search: 0153/binary_search.cpp
	g++ -std=c++11 -o $@ $^

BINS += 0268/sum
0268/sum: 0268/sum.cpp
	g++ -std=c++11 -o $@ $^

BINS += 0297/bfs
0297/bfs: 0297/bfs.cpp leetcode/tree.o
	g++ -std=c++11 -o $@ $^

BINS += 0297/dfs
0297/dfs: 0297/dfs.cpp leetcode/tree.o
	g++ -std=c++11 -o $@ $^

BINS += 0300/dp
0300/dp: 0300/dp.cpp
	g++ -std=c++11 -o $@ $^

BINS += 0849/linear_search
0849/linear_search: 0849/linear_search.cpp
	g++ -std=c++11 -o $@ $^

BINS += 1221/solution
1221/solution: 1221/solution.cpp
	g++ -std=c++11 -o $@ $^

BINS += 1222/solution
1222/solution: 1222/solution.cpp
	g++ -std=c++11 -o $@ $^

BINS += 1223/solution
1223/solution: 1223/solution.cpp
	g++ -std=c++11 -o $@ $^

BINS += 1224/solution
1224/solution: 1224/solution.cpp
	g++ -std=c++11 -o $@ $^

OBJS += leetcode/tree.o
leetcode/tree.o: leetcode/tree.cpp
	g++ -std=c++11 -o $@ -c $?

OBJS += leetcode/linked_list.o
leetcode/linked_list.o: leetcode/linked_list.cpp
	g++ -std=c++11 -o $@ -c $?

TESTS += test/linked_list_test
test/linked_list_test: test/linked_list_test.cpp leetcode/linked_list.o
	g++ -o $@ $^ -std=c++11 -Igtest/include -Lgtest/lib -lgtest -lgtest_main -lpthread

TESTS += test/tree_test
test/tree_test: test/tree_test.cpp leetcode/tree.o
	g++ -o $@ $^ -std=c++11 -Igtest/include -Lgtest/lib -lgtest -lgtest_main -lpthread

.PHONY: all
all: $(BINS) $(TESTS)

.PHONY: check
check: $(TESTS)
	@$(foreach TEST,$(TESTS),$(TEST);)

.PHONY: clean
clean:
	rm -f $(OBJS) $(BINS) $(TESTS)
