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

BINS += 0019/two_pass_cpp
0019/two_pass_cpp: 0019/two_pass.cpp leetcode/linked_list.o
	g++ $(CFLAGS) -o $@ $^

BINS += 0021/solution_cpp
0021/solution_cpp: 0021/solution.cpp leetcode/linked_list.o
	g++ $(CFLAGS) -I. -o $@ $^

BINS += 0035/linear_search_cpp
0035/linear_search_cpp: 0035/linear_search.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0046/solution_cpp
0046/solution_cpp: 0046/solution.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0047/solution_cpp
0047/solution_cpp: 0047/solution.cpp
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

BINS += 0073/solution_cpp
0073/solution_cpp: 0073/solution.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0075/counting_sort_cpp
0075/counting_sort_cpp: 0075/counting_sort.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0077/recursion_cpp
0077/recursion_cpp: 0077/recursion.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0083/linked_list
0083/linked_list: 0083/linked_list.cpp leetcode/linked_list.o
	g++ $(CFLAGS) -o $@ $^

BINS += 0089/recursion
0089/recursion: 0089/recursion.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0097/backtracking
0097/backtracking: 0097/backtracking.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0097/backtracking_with_memoization
0097/backtracking_with_memoization: 0097/backtracking_with_memoization.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0104/dfs
0104/dfs: 0104/dfs.cpp leetcode/tree.o
	g++ $(CFLAGS) -o $@ $^

BINS += 0139/dp
0139/dp: 0139/dp.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0125/two_pointers_cpp
0125/two_pointers_cpp: 0125/two_pointers.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0129/dfs
0129/dfs: 0129/dfs.cpp leetcode/tree.o
	g++ $(CFLAGS) -o $@ $^

BINS += 0139/dfs
0139/dfs: 0139/dfs.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0141/hash_table_cpp
0141/hash_table_cpp: 0141/hash_table.cpp leetcode/linked_list.o
	g++ $(CFLAGS) -I. -o $@ $^

BINS += 0151/solution
0151/solution: 0151/solution.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0153/binary_search
0153/binary_search: 0153/binary_search.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0155/two_stacks_cpp
0155/two_stacks_cpp: 0155/two_stacks.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0169/hash_table_cpp
0169/hash_table_cpp: 0169/hash_table.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0187/map_cpp
0187/map_cpp: 0187/map.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0191/solution
0191/solution: 0191/solution.cpp
	g++ $(CFLAGS) -o $@ $?

BINS += 0191/n_AND_n-1
0191/n_AND_n-1: 0191/n_AND_n-1.cpp
	g++ $(CFLAGS) -o $@ $?

BINS += 0198/dp_cpp
0198/dp_cpp: 0198/dp.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0202/solution_cpp
0202/solution_cpp: 0202/solution.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0213/dp_cpp
0213/dp_cpp: 0213/dp.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0215/min_heap_cpp
0215/min_heap_cpp: 0215/min_heap.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0221/dp_cpp
0221/dp_cpp: 0221/dp.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0229/majority_voting_cpp
0229/majority_voting_cpp: 0229/majority_voting.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0230/dfs_cpp
0230/dfs_cpp: 0230/dfs.cpp leetcode/tree.o
	g++ $(CFLAGS) -I. -o $@ $^

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

BINS += 0337/dfs_cpp
0337/dfs_cpp: 0337/dfs.cpp leetcode/tree.o
	g++ $(CFLAGS) -o $@ $^

BINS += 0392/linear_search
0392/linear_search: 0392/linear_search.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0392/follow_up
0392/follow_up: 0392/follow_up.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0406/solution_cpp
0406/solution_cpp: 0406/solution.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0416/dp_cpp
0416/dp_cpp: 0416/dp.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0525/dp_cpp
0525/dp_cpp: 0525/dp.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0542/dfs
0542/dfs: 0542/dfs.cpp
	g++ $(CFLAGS) -o $@ $?

BINS += 0542/bfs
0542/bfs: 0542/bfs.cpp
	g++ $(CFLAGS) -o $@ $?

BINS += 0668/binary_search_cpp
0668/binary_search_cpp: 0668/binary_search.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0704/solution_cpp
0704/solution_cpp: 0704/solution.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0799/dp
0799/dp: 0799/dp.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0802/dfs_cpp
0802/dfs_cpp: 0802/dfs.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0849/linear_search
0849/linear_search: 0849/linear_search.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0854/backtracking_cpp
0854/backtracking_cpp: 0854/backtracking.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0856/linear_search_with_recursion
0856/linear_search_with_recursion: 0856/linear_search_with_recursion.cpp
	g++ $(CFLAGS) -o $@ $?

BINS += 0930/prefix_sum_cpp
0930/prefix_sum_cpp: 0930/prefix_sum.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0950/solution
0950/solution: 0950/solution.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0950/queue_rs
0950/queue_rs: 0950/queue.rs
	rustc -o $@ $^

BINS += 0988/bottom_up_dfs
0988/bottom_up_dfs: 0988/bottom_up_dfs.cpp leetcode/tree.o
	g++ $(CFLAGS) -o $@ $^

BINS += 0988/top_down_dfs
0988/top_down_dfs: 0988/top_down_dfs.cpp leetcode/tree.o
	g++ $(CFLAGS) -o $@ $^

BINS += 1094/solution_cpp
1094/solution_cpp: 1094/solution.cpp
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

BINS += 1281/solution_cpp
1281/solution_cpp: 1281/solution.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 1282/solution_cpp
1282/solution_cpp: 1282/solution.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 1283/linear_search_cpp
1283/linear_search_cpp: 1283/linear_search.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 1283/binary_search_cpp
1283/binary_search_cpp: 1283/binary_search.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 1284/solution_cpp
1284/solution_cpp: 1284/solution.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0703/min_heap_cpp
0703/min_heap_cpp: 0703/min_heap.cpp
	g++ -std=c++11 -o $@ $^

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
