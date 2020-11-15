CXX = g++
CXXFLAGS = -std=c++11 -g -fsanitize=address,leak
CPPFLAGS = -I. -Igtest/include
LDFLAGS = -Lgtest/lib
LDLIBS = -lgtest -lgtest_main -lpthread

OBJS =
BINS =
TESTS =

BINS += 0004/merge_and_sort
0004/merge_and_sort: 0004/merge_and_sort.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0011/two_pointers_cpp
0011/two_pointers_cpp: 0011/two_pointers.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0018/brute_force
0018/brute_force: 0018/brute_force.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0018/recursive_2sum
0018/recursive_2sum: 0018/recursive_2sum.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0019/two_pass_cpp
0019/two_pass_cpp: 0019/two_pass.cpp leetcode/linked_list.o
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0019/one_pass_cpp
0019/one_pass_cpp: 0019/one_pass.cpp leetcode/linked_list.o
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0021/solution_cpp
0021/solution_cpp: 0021/solution.cpp leetcode/linked_list.o
	g++ $(CXXFLAGS) -I. -o $@ $^

BINS += 0024/recursion_cpp
0024/recursion_cpp: 0024/recursion.cpp leetcode/linked_list.o
	g++ $(CXXFLAGS) -I. -o $@ $^

BINS += 0031/solution
0031/solution: 0031/solution.cpp
	g++ -std=c++11 -o $@ $^

BINS += 0033/binary_search_cpp
0033/binary_search_cpp: 0033/binary_search.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0035/linear_search_cpp
0035/linear_search_cpp: 0035/linear_search.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0035/binary_search_cpp
0035/binary_search_cpp: 0035/binary_search.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0039/backtracking_cpp
0039/backtracking_cpp: 0039/backtracking.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0039/queue_cpp
0039/queue_cpp: 0039/queue.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0040/backtracking_cpp
0040/backtracking_cpp: 0040/backtracking.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0041/sort_cpp
0041/sort_cpp: 0041/sort.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0046/solution_cpp
0046/solution_cpp: 0046/solution.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0047/solution_cpp
0047/solution_cpp: 0047/solution.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0047/recursion_cpp
0047/recursion_cpp: 0047/recursion.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0049/categorize_by_sorting_cpp
0049/categorize_by_sorting_cpp: 0049/categorize_by_sorting.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0049/categorize_by_count_cpp
0049/categorize_by_count_cpp: 0049/categorize_by_count.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0053/dp
0053/dp: 0053/dp.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0053/dp_rs
0053/dp_rs: 0053/dp.rs
	rustc -o $@ $^

BINS += 0053/dp_constant_space_cpp
0053/dp_constant_space_cpp: 0053/dp_constant_space.cpp
	g++ $(CXXFLAGS) -o $@ $^ -Igtest/include -Lgtest/lib -lgtest -lgtest_main

BINS += 0055/dp_cpp
0055/dp_cpp: 0055/dp.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0055/dp_bottom_up_cpp
0055/dp_bottom_up_cpp: 0055/dp_bottom_up.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0058/one_pass_cpp
0058/one_pass_cpp: 0058/one_pass.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0060/solution_cpp
0060/solution_cpp: 0060/solution.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0061/two_pass_cpp
0061/two_pass_cpp: 0061/two_pass.cpp leetcode/linked_list.o
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0062/dp_matrix
0062/dp_matrix: 0062/dp_matrix.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0062/dp_vector_cpp
0062/dp_vector_cpp: 0062/dp_vector.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0062/dp_two_vec
0062/dp_two_vec: 0062/dp_two_vec.rs
	rustc -o $@ $^

BINS += 0063/dp_matrix
0063/dp_matrix: 0063/dp_matrix.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0063/dp_two_vec
0063/dp_two_vec: 0063/dp_two_vec.rs
	rustc -o $@ $^

BINS += 0064/dp_cpp
0064/dp_cpp: 0064/dp.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0072/dp_cpp
0072/dp_cpp: 0072/dp.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0073/solution_cpp
0073/solution_cpp: 0073/solution.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0073/constant_space_complexity_cpp
0073/constant_space_complexity_cpp: 0073/constant_space_complexity.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0074/linear_search_cpp
0074/linear_search_cpp: 0074/linear_search.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

# Dutch national flag problem
BINS += 0075/counting_sort_cpp
0075/counting_sort_cpp: 0075/counting_sort.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0075/one_pass_cpp
0075/one_pass_cpp: 0075/one_pass.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0077/recursion_cpp
0077/recursion_cpp: 0077/recursion.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0079/recursive_cpp
0079/recursive_cpp: 0079/recursive.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0083/linked_list
0083/linked_list: 0083/linked_list.cpp leetcode/linked_list.o
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0089/recursion
0089/recursion: 0089/recursion.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0094/recursive_cpp
0094/recursive_cpp: 0094/recursive.cpp leetcode/tree.o
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0094/iterative_cpp
0094/iterative_cpp: 0094/iterative.cpp leetcode/tree.o
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0096/recursion_with_memoization_cpp
0096/recursion_with_memoization_cpp: 0096/recursion_with_memoization.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0097/backtracking
0097/backtracking: 0097/backtracking.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0097/backtracking_with_memoization
0097/backtracking_with_memoization: 0097/backtracking_with_memoization.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0099/inorder_cpp
0099/inorder_cpp: 0099/inorder.cpp leetcode/tree.o
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0102/dfs_cpp
0102/dfs_cpp: 0102/dfs.cpp leetcode/tree.o
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0102/bfs_cpp
0102/bfs_cpp: 0102/bfs.cpp leetcode/tree.o
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0104/dfs
0104/dfs: 0104/dfs.cpp leetcode/tree.o
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0108/solution_cpp
0108/solution_cpp: 0108/solution.cpp leetcode/linked_list.o
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0111/bottom_up_dfs_cpp
0111/bottom_up_dfs_cpp: 0111/bottom_up_dfs.cpp leetcode/tree.o
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0111/top_down_dfs_cpp
0111/top_down_dfs_cpp: 0111/top_down_dfs.cpp leetcode/tree.o
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0117/bfs_cpp
0117/bfs_cpp: 0117/bfs.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0121/one_pass_cpp
0121/one_pass_cpp: 0121/one_pass.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0122/one_pass_cpp
0122/one_pass_cpp: 0122/one_pass.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0122/simple_one_pass_cpp
0122/simple_one_pass_cpp: 0122/simple_one_pass.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0123/dp_cpp
0123/dp_cpp: 0123/dp.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0124/dfs_cpp
0124/dfs_cpp: 0124/dfs.cpp leetcode/tree.o
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0125/two_pointers_cpp
0125/two_pointers_cpp: 0125/two_pointers.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0128/union_find_cpp
0128/union_find_cpp: 0128/union_find.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0129/bottom_up_dfs_cpp
0129/bottom_up_dfs_cpp: 0129/bottom_up_dfs.cpp leetcode/tree.o
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0129/top_down_dfs_cpp
0129/top_down_dfs_cpp: 0129/top_down_dfs.cpp leetcode/tree.o
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0130/dfs_cpp
0130/dfs_cpp: 0130/dfs.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0133/bfs_cpp
0133/bfs_cpp: 0133/bfs.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0134/n_squared_cpp
0134/n_squared_cpp: 0134/n_squared.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0136/hash_table_cpp
0136/hash_table_cpp: 0136/hash_table.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0136/bitmanip_cpp
0136/bitmanip_cpp: 0136/bitmanip.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0137/hash_table_cpp
0137/hash_table_cpp: 0137/hash_table.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0139/dfs
0139/dfs: 0139/dfs.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0139/dp
0139/dp: 0139/dp.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0139/dp_with_trie_cpp
0139/dp_with_trie_cpp: 0139/dp_with_trie.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0141/hash_table_cpp
0141/hash_table_cpp: 0141/hash_table.cpp leetcode/linked_list.o
	g++ $(CXXFLAGS) -I. -o $@ $^

BINS += 0142/hash_table_cpp
0142/hash_table_cpp: 0142/hash_table.cpp leetcode/linked_list.o
	g++ $(CXXFLAGS) -I. -o $@ $^

BINS += 0142/two_pointers_cpp
0142/two_pointers_cpp: 0142/two_pointers.cpp leetcode/linked_list.o
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0144/dfs_cpp
0144/dfs_cpp: 0144/dfs.cpp leetcode/tree.o
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0144/stack_cpp
0144/stack_cpp: 0144/stack.cpp leetcode/tree.o
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0145/recursive_cpp
0145/recursive_cpp: 0145/recursive.cpp leetcode/tree.o
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0145/iterative_cpp
0145/iterative_cpp: 0145/iterative.cpp leetcode/tree.o
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0146/hashmap_cpp
0146/hashmap_cpp: 0146/hashmap.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0147/solution_cpp
0147/solution_cpp: 0147/solution.cpp leetcode/linked_list.o
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0148/quick_sort_cpp
0148/quick_sort_cpp: 0148/quick_sort.cpp leetcode/linked_list.o
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0151/solution
0151/solution: 0151/solution.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0152/dp_constant_space_cpp
0152/dp_constant_space_cpp: 0152/dp_constant_space.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0153/binary_search
0153/binary_search: 0153/binary_search.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0155/two_stacks_cpp
0155/two_stacks_cpp: 0155/two_stacks.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0155/two_vector_rs
0155/two_vector_rs: 0155/two_vector.rs
	rustc -o $@ $^

BINS += 0165/solution_cpp
0165/solution_cpp: 0165/solution.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0169/hash_table_cpp
0169/hash_table_cpp: 0169/hash_table.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0169/boyer_moore_voting_cpp
0169/boyer_moore_voting_cpp: 0169/boyer_moore_voting.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0174/recursion_with_memoization_cpp
0174/recursion_with_memoization_cpp: 0174/recursion_with_memoization.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0179/sort_cpp
0179/sort_cpp: 0179/sort.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0187/hashmap_cpp
0187/hashmap_cpp: 0187/hashmap.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0188/dp_cpp
0188/dp_cpp: 0188/dp.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0189/inplace_cpp
0189/inplace_cpp: 0189/inplace.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0191/solution
0191/solution: 0191/solution.cpp
	g++ $(CXXFLAGS) -o $@ $?

BINS += 0191/n_AND_n-1
0191/n_AND_n-1: 0191/n_AND_n-1.cpp
	g++ $(CXXFLAGS) -o $@ $?

BINS += 0198/dp_cpp
0198/dp_cpp: 0198/dp.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0198/dp_constant_space_cpp
0198/dp_constant_space_cpp: 0198/dp_constant_space.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0200/dfs_cpp
0200/dfs_cpp: 0200/dfs.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0200/dfs_rs
0200/dfs_rs: 0200/dfs.rs
	rustc -o $@ $^

BINS += 0201/solution_cpp
0201/solution_cpp: 0201/solution.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0202/solution_cpp
0202/solution_cpp: 0202/solution.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0202/solution_rs
0202/solution_rs: 0202/solution.rs
	rustc -o $@ $^

BINS += 0204/solution_cpp
0204/solution_cpp: 0204/solution.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0205/hash_table_cpp
0205/hash_table_cpp: 0205/hash_table.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0206/solution_cpp
0206/solution_cpp: 0206/solution.cpp leetcode/linked_list.o
	g++ $(CXXFLAGS) -I. -o $@ $^

BINS += 0207/dfs_cpp
0207/dfs_cpp: 0207/dfs.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0208/dfs_cpp
0208/dfs_cpp: 0208/dfs.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0212/recursive_cpp
0212/recursive_cpp: 0212/recursive.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0213/dp_cpp
0213/dp_cpp: 0213/dp.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0213/dp_constant_space_cpp
0213/dp_constant_space_cpp: 0213/dp_constant_space.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0215/min_heap_cpp
0215/min_heap_cpp: 0215/min_heap.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0216/recursive_cpp
0216/recursive_cpp: 0216/recursive.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0221/dp_cpp
0221/dp_cpp: 0221/dp.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0221/dfs_cpp
0221/dfs_cpp: 0221/dfs.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0222/recursive_cpp
0222/recursive_cpp: 0222/recursive.cpp leetcode/tree.o
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0226/recursive_cpp
0226/recursive_cpp: 0226/recursive.cpp leetcode/tree.o
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0226/iterative_cpp
0226/iterative_cpp: 0226/iterative.cpp leetcode/tree.o
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0228/one_pass_cpp
0228/one_pass_cpp: 0228/one_pass.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0229/majority_voting_cpp
0229/majority_voting_cpp: 0229/majority_voting.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0229/hashmap_cpp
0229/hashmap_cpp: 0229/hashmap.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0230/dfs_cpp
0230/dfs_cpp: 0230/dfs.cpp leetcode/tree.o
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0230/dfs_iterative_cpp
0230/dfs_iterative_cpp: 0230/dfs_iterative.cpp leetcode/tree.o
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0231/recursive_cpp
0231/recursive_cpp: 0231/recursive.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0231/bitmanip_cpp
0231/bitmanip_cpp: 0231/bitmanip.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0237/solution_cpp
0237/solution_cpp: 0237/solution.cpp leetcode/linked_list.o
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0238/solution_cpp
0238/solution_cpp: 0238/solution.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0238/solution_rs
0238/solution_rs: 0238/solution.rs
	rustc -o $@ $^

BINS += 0239/deque_cpp
0239/deque_cpp: 0239/deque.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0268/sum
0268/sum: 0268/sum.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0275/binary_search_cpp
0275/binary_search_cpp: 0275/binary_search.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0278/binary_search_cpp
0278/binary_search_cpp: 0278/binary_search.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0279/recursive_cpp
0279/recursive_cpp: 0279/recursive.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0283/solution_cpp
0283/solution_cpp: 0283/solution.cpp
	g++ $(CXXFLAGS) -o $@ $^

# Floyd's Tortoise and Hare
BINS += 0287/constant_space_complexity_cpp
0287/constant_space_complexity_cpp: 0287/constant_space_complexity.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0297/bfs_cpp
0297/bfs_cpp: 0297/bfs.cpp leetcode/tree.o
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0297/dfs_cpp
0297/dfs_cpp: 0297/dfs.cpp leetcode/tree.o
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0299/one_pass_cpp
0299/one_pass_cpp: 0299/one_pass.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0300/dp
0300/dp: 0300/dp.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0300/dp_rs
0300/dp_rs: 0300/dp.rs
	rustc -o $@ $^

BINS += 0300/faster_dp_cpp
0300/faster_dp_cpp: 0300/faster_dp.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0309/dp_cpp
0309/dp_cpp: 0309/dp.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0322/dp_cpp
0322/dp_cpp: 0322/dp.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0328/constant_space_cpp
0328/constant_space_cpp: 0328/constant_space.cpp leetcode/linked_list.o
	g++ $(CXXFLAGS) -I. -o $@ $^ -Igtest/include -Lgtest/lib -lgtest -lgtest_main

BINS += 0332/recursive_cpp
0332/recursive_cpp: 0332/recursive.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0337/dfs_cpp
0337/dfs_cpp: 0337/dfs.cpp leetcode/tree.o
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0338/solution_cpp
0338/solution_cpp: 0338/solution.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0344/recursion_cpp
0344/recursion_cpp: 0344/recursion.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0344/two_pointers_cpp
0344/two_pointers_cpp: 0344/two_pointers.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0367/binary_search_cpp
0367/binary_search_cpp: 0367/binary_search.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0368/recursion_with_memoization_cpp
0368/recursion_with_memoization_cpp: 0368/recursion_with_memoization.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0370/solution_cpp
0370/solution_cpp: 0370/solution.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0376/dp_cpp
0376/dp_cpp: 0376/dp.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0380/hashmap_cpp
0380/hashmap_cpp: 0380/hashmap.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0383/hashmap_cpp
0383/hashmap_cpp: 0383/hashmap.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0387/hashmap_cpp
0387/hashmap_cpp: 0387/hashmap.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0389/hashmap_cpp
0389/hashmap_cpp: 0389/hashmap.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0392/linear_search
0392/linear_search: 0392/linear_search.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0392/follow_up
0392/follow_up: 0392/follow_up.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0399/dfs_cpp
0399/dfs_cpp: 0399/dfs.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0399/bfs_cpp
0399/bfs_cpp: 0399/bfs.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0402/stack_cpp
0402/stack_cpp: 0402/stack.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0406/sort_cpp
0406/sort_cpp: 0406/sort.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0406/heap_cpp
0406/heap_cpp: 0406/heap.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0416/dp_cpp
0416/dp_cpp: 0416/dp.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0416/dp_rs
0416/dp_rs: 0416/dp.rs
	rustc -o $@ $^

BINS += 0416/recursion_rs
0416/recursion_rs: 0416/recursion.rs
	rustc -o $@ $^

BINS += 0416/recursion_without_memoization_rs
0416/recursion_without_memoization_rs: 0416/recursion_without_memoization.rs
	rustc -o $@ $^

BINS += 0421/brute_force_cpp
0421/brute_force_cpp: 0421/brute_force.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0421/trie_cpp
0421/trie_cpp: 0421/trie.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0438/tle_cpp
0438/tle_cpp: 0438/tle.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0438/sliding_window_cpp
0438/sliding_window_cpp: 0438/sliding_window.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0445/reverse_cpp
0445/reverse_cpp: 0445/reverse.cpp leetcode/linked_list.o
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0450/recursive_cpp
0450/recursive_cpp: 0450/recursive.cpp leetcode/tree.o
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0451/heap_cpp
0451/heap_cpp: 0451/heap.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0452/sort_cpp
0452/sort_cpp: 0452/sort.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0456/n_squared_cpp
0456/n_squared_cpp: 0456/n_squared.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0458/solution_cpp
0458/solution_cpp: 0458/solution.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0467/dp_cpp
0467/dp_cpp: 0467/dp.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0468/solution_cpp
0468/solution_cpp: 0468/solution.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0476/solution_cpp
0476/solution_cpp: 0476/solution.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0495/one_pass_cpp
0495/one_pass_cpp: 0495/one_pass.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0516/dp_cpp
0516/dp_cpp: 0516/dp.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0518/dp_cpp
0518/dp_cpp: 0518/dp.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0518/recursion_with_memoization_cpp
0518/recursion_with_memoization_cpp: 0518/recursion_with_memoization.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0520/solution_cpp
0520/solution_cpp: 0520/solution.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0525/dp_cpp
0525/dp_cpp: 0525/dp.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0525/dp_rs
0525/dp_rs: 0525/dp.rs
	rustc -o $@ $^

BINS += 0528/binary_search_cpp
0528/binary_search_cpp: 0528/binary_search.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0532/sort_cpp
0532/sort_cpp: 0532/sort.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0540/binary_search_cpp
0540/binary_search_cpp: 0540/binary_search.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0542/dfs_cpp
0542/dfs_cpp: 0542/dfs.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0542/bfs_cpp
0542/bfs_cpp: 0542/bfs.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0543/dfs_cpp
0543/dfs_cpp: 0543/dfs.cpp leetcode/tree.o
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0547/union_find_without_rank_cpp
0547/union_find_without_rank_cpp: 0547/union_find_without_rank.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0560/dp_cpp
0560/dp_cpp: 0560/dp.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0560/hashmap_cpp
0560/hashmap_cpp: 0560/hashmap.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0563/dfs_cpp
0563/dfs_cpp: 0563/dfs.cpp leetcode/tree.o
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0567/sliding_window_cpp
0567/sliding_window_cpp: 0567/sliding_window.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0630/greedy_cpp
0630/greedy_cpp: 0630/greedy.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0668/binary_search_cpp
0668/binary_search_cpp: 0668/binary_search.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0673/dp_cpp
0673/dp_cpp: 0673/dp.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0678/stack_cpp
0678/stack_cpp: 0678/stack.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0700/recursive_cpp
0700/recursive_cpp: 0700/recursive.cpp leetcode/tree.o
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0701/recursive_cpp
0701/recursive_cpp: 0701/recursive.cpp leetcode/tree.o
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0703/min_heap_cpp
0703/min_heap_cpp: 0703/min_heap.cpp
	g++ -std=c++11 -o $@ $^

BINS += 0704/solution_cpp
0704/solution_cpp: 0704/solution.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0705/array_cpp
0705/array_cpp: 0705/array.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0705/linked_list_without_rehashing_cpp
0705/linked_list_without_rehashing_cpp: 0705/linked_list_without_rehashing.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0706/linked_list_without_rehashing_cpp
0706/linked_list_without_rehashing_cpp: 0706/linked_list_without_rehashing.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0713/two_pointers_cpp
0713/two_pointers_cpp: 0713/two_pointers.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0714/dp_cpp
0714/dp_cpp: 0714/dp.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0733/bfs_cpp
0733/bfs_cpp: 0733/bfs.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0735/stack_cpp
0735/stack_cpp: 0735/stack.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0743/dijkstra_cpp
0743/dijkstra_cpp: 0743/dijkstra.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0763/greedy_cpp
0763/greedy_cpp: 0763/greedy.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0771/hashmap_cpp
0771/hashmap_cpp: 0771/hashmap.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0771/hashset_cpp
0771/hashset_cpp: 0771/hashset.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0785/bfs_cpp
0785/bfs_cpp: 0785/bfs.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0787/bellman_ford_cpp
0787/bellman_ford_cpp: 0787/bellman_ford.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0787/dijkstra_cpp
0787/dijkstra_cpp: 0787/dijkstra.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0799/dp
0799/dp: 0799/dp.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0799/dp_lower_space_complexity_cpp
0799/dp_lower_space_complexity_cpp: 0799/dp_lower_space_complexity.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0802/dfs_cpp
0802/dfs_cpp: 0802/dfs.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0832/solution_cpp
0832/solution_cpp: 0832/solution.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0835/brute_force_cpp
0835/brute_force_cpp: 0835/brute_force.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0844/stack_cpp
0844/stack_cpp: 0844/stack.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0849/linear_search
0849/linear_search: 0849/linear_search.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0849/group_by_zero_cpp
0849/group_by_zero_cpp: 0849/group_by_zero.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0854/backtracking_cpp
0854/backtracking_cpp: 0854/backtracking.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0856/linear_search_with_recursion
0856/linear_search_with_recursion: 0856/linear_search_with_recursion.cpp
	g++ $(CXXFLAGS) -o $@ $?

BINS += 0859/one_pass_cpp
0859/one_pass_cpp: 0859/one_pass.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0871/priority_queue_cpp
0871/priority_queue_cpp: 0871/priority_queue.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0876/two_pointers_cpp
0876/two_pointers_cpp: 0876/two_pointers.cpp leetcode/linked_list.o
	g++ $(CXXFLAGS) -I. -o $@ $^

BINS += 0886/backtracking_cpp
0886/backtracking_cpp: 0886/backtracking.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0886/dfs_cpp
0886/dfs_cpp: 0886/dfs.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0901/linear_search_cpp
0901/linear_search_cpp: 0901/linear_search.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0901/stack_cpp
0901/stack_cpp: 0901/stack.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0914/gcd_cpp
0914/gcd_cpp: 0914/gcd.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0918/dp_cpp
0918/dp_cpp: 0918/dp.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0930/prefix_sum_cpp
0930/prefix_sum_cpp: 0930/prefix_sum.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0938/bottom_up_dfs_cpp
0938/bottom_up_dfs_cpp: 0938/bottom_up_dfs.cpp leetcode/tree.o
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0948/two_pointers_cpp
0948/two_pointers_cpp: 0948/two_pointers.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0950/solution
0950/solution: 0950/solution.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0950/queue_rs
0950/queue_rs: 0950/queue.rs
	rustc -o $@ $^

BINS += 0973/heap_cpp
0973/heap_cpp: 0973/heap.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0974/prefix_sum_cpp
0974/prefix_sum_cpp: 0974/prefix_sum.cpp
	g++ $(CXXFLAGS) -I. -o $@ $^ -Igtest/include -Lgtest/lib -lgtest -lgtest_main

BINS += 0976/solution_cpp
0976/solution_cpp: 0976/solution.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 0980/recursion_cpp
0980/recursion_cpp: 0980/recursion.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

# TLE
BINS += 0986/linear_search_cpp
0986/linear_search_cpp: 0986/linear_search.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0986/two_pointers_cpp
0986/two_pointers_cpp: 0986/two_pointers.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0988/bottom_up_dfs_cpp
0988/bottom_up_dfs_cpp: 0988/bottom_up_dfs.cpp leetcode/tree.o
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0988/top_down_dfs_cpp
0988/top_down_dfs_cpp: 0988/top_down_dfs.cpp leetcode/tree.o
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0993/dfs_cpp
0993/dfs_cpp: 0993/dfs.cpp leetcode/tree.o
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0997/solution_cpp
0997/solution_cpp: 0997/solution.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 1008/top_down_cpp
1008/top_down_cpp: 1008/top_down.cpp leetcode/tree.o
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 1008/dfs_cpp
1008/dfs_cpp: 1008/dfs.cpp leetcode/tree.o
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 1009/one_pass_cpp
1009/one_pass_cpp: 1009/one_pass.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 1022/bfs_cpp
1022/bfs_cpp: 1022/bfs.cpp leetcode/tree.o
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 1026/top_down_dfs_cpp
1026/top_down_dfs_cpp: 1026/top_down_dfs.cpp leetcode/tree.o
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 1029/heap_cpp
1029/heap_cpp: 1029/heap.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 1029/sort_cpp
1029/sort_cpp: 1029/sort.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 1035/dp_cpp
1035/dp_cpp: 1035/dp.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 1041/one_pass_cpp
1041/one_pass_cpp: 1041/one_pass.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 1044/binary_search_cpp
1044/binary_search_cpp: 1044/binary_search.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 1046/heap_cpp
1046/heap_cpp: 1046/heap.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 1071/gcd_cpp
1071/gcd_cpp: 1071/gcd.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 1077/brute_force_cpp
1077/brute_force_cpp: 1077/brute_force.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 1091/bfs_cpp
1091/bfs_cpp: 1091/bfs.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 1094/count_passengers_at_all_locations_cpp
1094/count_passengers_at_all_locations_cpp: 1094/count_passengers_at_all_locations.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 1094/count_passengers_at_start_and_end_cpp
1094/count_passengers_at_start_and_end_cpp: 1094/count_passengers_at_start_and_end.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 1143/dp_cpp
1143/dp_cpp: 1143/dp.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 1143/dp_rs
1143/dp_rs: 1143/dp.rs
	rustc -o $@ $^

BINS += 0962/tle_cpp
0962/tle_cpp: 0962/tle.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 0962/sort_cpp
0962/sort_cpp: 0962/sort.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 1217/solution_cpp
1217/solution_cpp: 1217/solution.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 1221/solution
1221/solution: 1221/solution.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 1222/solution
1222/solution: 1222/solution.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 1223/solution
1223/solution: 1223/solution.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 1224/solution
1224/solution: 1224/solution.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 1232/solution_cpp
1232/solution_cpp: 1232/solution.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 1252/solution
1252/solution: 1252/solution.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 1253/solution
1253/solution: 1253/solution.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 1254/solution
1254/solution: 1254/solution.cpp
	g++ $(CXXFLAGS) -o $@ $?

BINS += 1255/backtracking
1255/backtracking: 1255/backtracking.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 1277/recursion_with_memoization_cpp
1277/recursion_with_memoization_cpp: 1277/recursion_with_memoization.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 1281/solution_cpp
1281/solution_cpp: 1281/solution.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 1282/solution_cpp
1282/solution_cpp: 1282/solution.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 1283/linear_search_cpp
1283/linear_search_cpp: 1283/linear_search.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 1283/binary_search_cpp
1283/binary_search_cpp: 1283/binary_search.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 1284/solution_cpp
1284/solution_cpp: 1284/solution.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 1288/sort_cpp
1288/sort_cpp: 1288/sort.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 1291/brute_force_cpp
1291/brute_force_cpp: 1291/brute_force.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 1305/dfs_cpp
1305/dfs_cpp: 1305/dfs.cpp leetcode/tree.o
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 1334/warshall_floyd_cpp
1334/warshall_floyd_cpp: 1334/warshall_floyd.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 1374/solution_cpp
1374/solution_cpp: 1374/solution.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 1375/solution_cpp
1375/solution_cpp: 1375/solution.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 1376/solution_cpp
1376/solution_cpp: 1376/solution.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 1377/solution_cpp
1377/solution_cpp: 1377/solution.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 1389/solution_cpp
1389/solution_cpp: 1389/solution.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 1390/solution_cpp
1390/solution_cpp: 1390/solution.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 1391/solution_cpp
1391/solution_cpp: 1391/solution.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 1392/rolling_hash_cpp
1392/rolling_hash_cpp: 1392/rolling_hash.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 1394/solution_cpp
1394/solution_cpp: 1394/solution.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 1395/solution_cpp
1395/solution_cpp: 1395/solution.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 1395/brute_force_cpp
1395/brute_force_cpp: 1395/brute_force.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 1395/dp_cpp
1395/dp_cpp: 1395/dp.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 1396/solution_cpp
1396/solution_cpp: 1396/solution.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 1396/hash_table_and_pair_cpp
1396/hash_table_and_pair_cpp: 1396/hash_table_and_pair.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 1408/solution_cpp
1408/solution_cpp: 1408/solution.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 1408/solution_after_contest_cpp
1408/solution_after_contest_cpp: 1408/solution_after_contest.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 1409/solution_cpp
1409/solution_cpp: 1409/solution.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 1410/solution_cpp
1410/solution_cpp: 1410/solution.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 1411/solution_cpp
1411/solution_cpp: 1411/solution.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 1417/solution_cpp
1417/solution_cpp: 1417/solution.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 1418/solution_cpp
1418/solution_cpp: 1418/solution.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 1419/solution_cpp
1419/solution_cpp: 1419/solution.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 1420/solution_cpp
1420/solution_cpp: 1420/solution.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 1426/sorting_cpp
1426/sorting_cpp: 1426/sorting.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 1426/hash_table_cpp
1426/hash_table_cpp: 1426/hash_table.cpp
	g++ $(CXXFLAGS) -o $@ $^

BINS += 1427/solution_cpp
1427/solution_cpp: 1427/solution.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 1428/binary_search_cpp
1428/binary_search_cpp: 1428/binary_search.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 1429/queue_cpp
1429/queue_cpp: 1429/queue.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 1429/linked_list_cpp
1429/linked_list_cpp: 1429/linked_list.cpp leetcode/linked_list.o
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 1430/dfs_cpp
1430/dfs_cpp: 1430/dfs.cpp leetcode/tree.o
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 1441/solution_cpp
1441/solution_cpp: 1441/solution.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 1442/solution_cpp
1442/solution_cpp: 1442/solution.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 1443/solution_cpp
1443/solution_cpp: 1443/solution.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 1444/solution_cpp
1444/solution_cpp: 1444/solution.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

BINS += 1446/linear_search_cpp
1446/linear_search_cpp: 1446/linear_search.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

OBJS += leetcode/tree.o
leetcode/tree.o: leetcode/tree.cpp
	g++ $(CXXFLAGS) -o $@ -c $?

OBJS += leetcode/linked_list.o
leetcode/linked_list.o: leetcode/linked_list.cpp
	g++ $(CXXFLAGS) -o $@ -c $?

TESTS += test/linked_list_test
test/linked_list_test: test/linked_list_test.cpp leetcode/linked_list.o
	g++ -o $@ $^ $(CXXFLAGS) -Igtest/include -Lgtest/lib -lgtest -lgtest_main -lpthread

TESTS += test/tree_test
test/tree_test: test/tree_test.cpp leetcode/tree.o
	g++ -o $@ $^ $(CXXFLAGS) -Igtest/include -Lgtest/lib -lgtest -lgtest_main -lpthread

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
