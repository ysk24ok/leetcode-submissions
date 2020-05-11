CFLAGS = -std=c++11 -g -fsanitize=address,leak

OBJS =
BINS =
TESTS =

BINS += 0004/merge_and_sort
0004/merge_and_sort: 0004/merge_and_sort.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0011/two_pointers_cpp
0011/two_pointers_cpp: 0011/two_pointers.cpp
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

BINS += 0024/recursion_cpp
0024/recursion_cpp: 0024/recursion.cpp leetcode/linked_list.o
	g++ $(CFLAGS) -I. -o $@ $^

BINS += 0033/binary_search_cpp
0033/binary_search_cpp: 0033/binary_search.cpp leetcode/assert.hpp
	g++ $(CFLAGS) -I. -o $@ $<

BINS += 0035/linear_search_cpp
0035/linear_search_cpp: 0035/linear_search.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0039/backtracking_cpp
0039/backtracking_cpp: 0039/backtracking.cpp
	g++ $(CFLAGS) -I. -o $@ $^

BINS += 0040/backtracking_cpp
0040/backtracking_cpp: 0040/backtracking.cpp
	g++ $(CFLAGS) -I. -o $@ $^

BINS += 0046/solution_cpp
0046/solution_cpp: 0046/solution.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0047/solution_cpp
0047/solution_cpp: 0047/solution.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0049/categorize_by_sorting_cpp
0049/categorize_by_sorting_cpp: 0049/categorize_by_sorting.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0049/categorize_by_count_cpp
0049/categorize_by_count_cpp: 0049/categorize_by_count.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0053/dp
0053/dp: 0053/dp.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0053/dp_rs
0053/dp_rs: 0053/dp.rs
	rustc -o $@ $^

BINS += 0055/dp_cpp
0055/dp_cpp: 0055/dp.cpp
	g++ $(CFLAGS) -I. -o $@ $^

BINS += 0055/dp_bottom_up_cpp
0055/dp_bottom_up_cpp: 0055/dp_bottom_up.cpp
	g++ $(CFLAGS) -I. -o $@ $^

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

BINS += 0064/dp_cpp
0064/dp_cpp: 0064/dp.cpp leetcode/assert.hpp
	g++ $(CFLAGS) -I. -o $@ $<

BINS += 0073/solution_cpp
0073/solution_cpp: 0073/solution.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0073/constant_space_complexity_cpp
0073/constant_space_complexity_cpp: 0073/constant_space_complexity.cpp
	g++ $(CFLAGS) -I. -o $@ $^

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

BINS += 0094/recursive_cpp
0094/recursive_cpp: 0094/recursive.cpp leetcode/tree.o
	g++ $(CFLAGS) -I. -o $@ $^

BINS += 0094/iterative_cpp
0094/iterative_cpp: 0094/iterative.cpp leetcode/tree.o
	g++ $(CFLAGS) -I. -o $@ $^

BINS += 0097/backtracking
0097/backtracking: 0097/backtracking.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0097/backtracking_with_memoization
0097/backtracking_with_memoization: 0097/backtracking_with_memoization.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0102/dfs_cpp
0102/dfs_cpp: 0102/dfs.cpp leetcode/tree.o
	g++ $(CFLAGS) -I. -o $@ $^

BINS += 0102/bfs_cpp
0102/bfs_cpp: 0102/bfs.cpp leetcode/tree.o
	g++ $(CFLAGS) -I. -o $@ $^

BINS += 0104/dfs
0104/dfs: 0104/dfs.cpp leetcode/tree.o
	g++ $(CFLAGS) -o $@ $^

BINS += 0121/one_pass_cpp
0121/one_pass_cpp: 0121/one_pass.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0122/one_pass_cpp
0122/one_pass_cpp: 0122/one_pass.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0122/simple_one_pass_cpp
0122/simple_one_pass_cpp: 0122/simple_one_pass.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0123/dp_cpp
0123/dp_cpp: 0123/dp.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0124/dfs_cpp
0124/dfs_cpp: 0124/dfs.cpp leetcode/tree.o
	g++ $(CFLAGS) -I. -o $@ $^

BINS += 0125/two_pointers_cpp
0125/two_pointers_cpp: 0125/two_pointers.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0128/union_find_cpp
0128/union_find_cpp: 0128/union_find.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0129/dfs
0129/dfs: 0129/dfs.cpp leetcode/tree.o
	g++ $(CFLAGS) -o $@ $^

BINS += 0136/hash_table_cpp
0136/hash_table_cpp: 0136/hash_table.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0136/bitmanip_cpp
0136/bitmanip_cpp: 0136/bitmanip.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0139/dfs
0139/dfs: 0139/dfs.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0139/dp
0139/dp: 0139/dp.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0141/hash_table_cpp
0141/hash_table_cpp: 0141/hash_table.cpp leetcode/linked_list.o
	g++ $(CFLAGS) -I. -o $@ $^

BINS += 0142/hash_table_cpp
0142/hash_table_cpp: 0142/hash_table.cpp leetcode/linked_list.o
	g++ $(CFLAGS) -I. -o $@ $^

BINS += 0144/dfs_cpp
0144/dfs_cpp: 0144/dfs.cpp leetcode/tree.o
	g++ $(CFLAGS) -I. -o $@ $^

BINS += 0144/stack_cpp
0144/stack_cpp: 0144/stack.cpp leetcode/tree.o
	g++ $(CFLAGS) -I. -o $@ $^

BINS += 0145/recursive_cpp
0145/recursive_cpp: 0145/recursive.cpp leetcode/tree.o
	g++ $(CFLAGS) -I. -o $@ $^

BINS += 0145/iterative_cpp
0145/iterative_cpp: 0145/iterative.cpp leetcode/tree.o
	g++ $(CFLAGS) -I. -o $@ $^

BINS += 0146/hashmap_cpp
0146/hashmap_cpp: 0146/hashmap.cpp
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

BINS += 0155/two_vector_rs
0155/two_vector_rs: 0155/two_vector.rs
	rustc -o $@ $^

BINS += 0169/hash_table_cpp
0169/hash_table_cpp: 0169/hash_table.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0169/boyer_moore_voting_cpp
0169/boyer_moore_voting_cpp: 0169/boyer_moore_voting.cpp
	g++ $(CFLAGS) -I. -o $@ $^

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

BINS += 0200/dfs_cpp
0200/dfs_cpp: 0200/dfs.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0200/dfs_rs
0200/dfs_rs: 0200/dfs.rs
	rustc -o $@ $^

BINS += 0201/solution_cpp
0201/solution_cpp: 0201/solution.cpp
	g++ $(CFLAGS) -I. -o $@ $^

BINS += 0202/solution_cpp
0202/solution_cpp: 0202/solution.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0202/solution_rs
0202/solution_rs: 0202/solution.rs
	rustc -o $@ $^

BINS += 0204/solution_cpp
0204/solution_cpp: 0204/solution.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0205/hash_table_cpp
0205/hash_table_cpp: 0205/hash_table.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0206/solution_cpp
0206/solution_cpp: 0206/solution.cpp leetcode/linked_list.o
	g++ $(CFLAGS) -I. -o $@ $^

BINS += 0208/dfs_cpp
0208/dfs_cpp: 0208/dfs.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0213/dp_cpp
0213/dp_cpp: 0213/dp.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0215/min_heap_cpp
0215/min_heap_cpp: 0215/min_heap.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0221/dp_cpp
0221/dp_cpp: 0221/dp.cpp
	g++ $(CFLAGS) -I. -o $@ $^

BINS += 0221/dfs_cpp
0221/dfs_cpp: 0221/dfs.cpp
	g++ $(CFLAGS) -I. -o $@ $^

BINS += 0229/majority_voting_cpp
0229/majority_voting_cpp: 0229/majority_voting.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0231/recursive_cpp
0231/recursive_cpp: 0231/recursive.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0231/bitmanip_cpp
0231/bitmanip_cpp: 0231/bitmanip.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0230/dfs_cpp
0230/dfs_cpp: 0230/dfs.cpp leetcode/tree.o
	g++ $(CFLAGS) -I. -o $@ $^

BINS += 0238/solution_cpp
0238/solution_cpp: 0238/solution.cpp leetcode/assert.hpp
	g++ $(CFLAGS) -I. -o $@ $<

BINS += 0238/solution_rs
0238/solution_rs: 0238/solution.rs
	rustc -o $@ $^

BINS += 0268/sum
0268/sum: 0268/sum.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0278/binary_search_cpp
0278/binary_search_cpp: 0278/binary_search.cpp
	g++ $(CFLAGS) -I. -o $@ $^

BINS += 0283/solution_cpp
0283/solution_cpp: 0283/solution.cpp
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

BINS += 0300/dp_rs
0300/dp_rs: 0300/dp.rs
	rustc -o $@ $^

BINS += 0300/faster_dp_cpp
0300/faster_dp_cpp: 0300/faster_dp.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0309/dp_cpp
0309/dp_cpp: 0309/dp.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0322/dp_cpp
0322/dp_cpp: 0322/dp.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0337/dfs_cpp
0337/dfs_cpp: 0337/dfs.cpp leetcode/tree.o
	g++ $(CFLAGS) -o $@ $^

BINS += 0344/recursion_cpp
0344/recursion_cpp: 0344/recursion.cpp
	g++ $(CFLAGS) -I. -o $@ $^

BINS += 0367/binary_search_cpp
0367/binary_search_cpp: 0367/binary_search.cpp
	g++ $(CFLAGS) -I. -o $@ $^

BINS += 0376/dp_cpp
0376/dp_cpp: 0376/dp.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0383/hashmap_cpp
0383/hashmap_cpp: 0383/hashmap.cpp
	g++ $(CFLAGS) -I. -o $@ $^

BINS += 0387/hashmap_cpp
0387/hashmap_cpp: 0387/hashmap.cpp
	g++ $(CFLAGS) -I. -o $@ $^

BINS += 0392/linear_search
0392/linear_search: 0392/linear_search.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0392/follow_up
0392/follow_up: 0392/follow_up.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0399/dfs_cpp
0399/dfs_cpp: 0399/dfs.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0406/solution_cpp
0406/solution_cpp: 0406/solution.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0416/dp_cpp
0416/dp_cpp: 0416/dp.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0416/dp_rs
0416/dp_rs: 0416/dp.rs
	rustc -o $@ $^

BINS += 0416/recursion_rs
0416/recursion_rs: 0416/recursion.rs
	rustc -o $@ $^

BINS += 0416/recursion_without_memoization_rs
0416/recursion_without_memoization_rs: 0416/recursion_without_memoization.rs
	rustc -o $@ $^

BINS += 0467/dp_cpp
0467/dp_cpp: 0467/dp.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0476/solution_cpp
0476/solution_cpp: 0476/solution.cpp
	g++ $(CFLAGS) -I. -o $@ $^

BINS += 0516/dp_cpp
0516/dp_cpp: 0516/dp.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0518/dp_cpp
0518/dp_cpp: 0518/dp.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0520/solution_cpp
0520/solution_cpp: 0520/solution.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0525/dp_cpp
0525/dp_cpp: 0525/dp.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0525/dp_rs
0525/dp_rs: 0525/dp.rs
	rustc -o $@ $^

BINS += 0542/dfs
0542/dfs: 0542/dfs.cpp
	g++ $(CFLAGS) -o $@ $?

BINS += 0542/bfs
0542/bfs: 0542/bfs.cpp
	g++ $(CFLAGS) -o $@ $?

BINS += 0543/dfs_cpp
0543/dfs_cpp: 0543/dfs.cpp leetcode/tree.o
	g++ $(CFLAGS) -I. -o $@ $^

BINS += 0547/union_find_without_rank_cpp
0547/union_find_without_rank_cpp: 0547/union_find_without_rank.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0560/dp_cpp
0560/dp_cpp: 0560/dp.cpp leetcode/assert.hpp
	g++ $(CFLAGS) -I. -o $@ $<

BINS += 0560/hashmap_cpp
0560/hashmap_cpp: 0560/hashmap.cpp leetcode/assert.hpp
	g++ $(CFLAGS) -I. -o $@ $<

BINS += 0630/greedy_cpp
0630/greedy_cpp: 0630/greedy.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0668/binary_search_cpp
0668/binary_search_cpp: 0668/binary_search.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0678/stack_cpp
0678/stack_cpp: 0678/stack.cpp leetcode/assert.hpp
	g++ $(CFLAGS) -I. -o $@ $<

BINS += 0703/min_heap_cpp
0703/min_heap_cpp: 0703/min_heap.cpp
	g++ -std=c++11 -o $@ $^

BINS += 0704/solution_cpp
0704/solution_cpp: 0704/solution.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0705/array_cpp
0705/array_cpp: 0705/array.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0705/linked_list_without_rehashing_cpp
0705/linked_list_without_rehashing_cpp: 0705/linked_list_without_rehashing.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0706/linked_list_without_rehashing_cpp
0706/linked_list_without_rehashing_cpp: 0706/linked_list_without_rehashing.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0714/dp_cpp
0714/dp_cpp: 0714/dp.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0733/bfs_cpp
0733/bfs_cpp: 0733/bfs.cpp
	g++ $(CFLAGS) -I. -o $@ $^

BINS += 0743/dijkstra_cpp
0743/dijkstra_cpp: 0743/dijkstra.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0771/hashmap_cpp
0771/hashmap_cpp: 0771/hashmap.cpp
	g++ $(CFLAGS) -I. -o $@ $^

BINS += 0771/hashset_cpp
0771/hashset_cpp: 0771/hashset.cpp
	g++ $(CFLAGS) -I. -o $@ $^

BINS += 0785/bfs_cpp
0785/bfs_cpp: 0785/bfs.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0787/bellman_ford_cpp
0787/bellman_ford_cpp: 0787/bellman_ford.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0799/dp
0799/dp: 0799/dp.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0802/dfs_cpp
0802/dfs_cpp: 0802/dfs.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0844/stack_cpp
0844/stack_cpp: 0844/stack.cpp
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

BINS += 0871/priority_queue_cpp
0871/priority_queue_cpp: 0871/priority_queue.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0876/two_pointers_cpp
0876/two_pointers_cpp: 0876/two_pointers.cpp leetcode/linked_list.o
	g++ $(CFLAGS) -I. -o $@ $^

BINS += 0914/gcd_cpp
0914/gcd_cpp: 0914/gcd.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0930/prefix_sum_cpp
0930/prefix_sum_cpp: 0930/prefix_sum.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0950/solution
0950/solution: 0950/solution.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0950/queue_rs
0950/queue_rs: 0950/queue.rs
	rustc -o $@ $^

BINS += 0976/solution_cpp
0976/solution_cpp: 0976/solution.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 0988/bottom_up_dfs
0988/bottom_up_dfs: 0988/bottom_up_dfs.cpp leetcode/tree.o
	g++ $(CFLAGS) -o $@ $^

BINS += 0988/top_down_dfs
0988/top_down_dfs: 0988/top_down_dfs.cpp leetcode/tree.o
	g++ $(CFLAGS) -o $@ $^

BINS += 0993/dfs_cpp
0993/dfs_cpp: 0993/dfs.cpp leetcode/tree.o
	g++ $(CFLAGS) -I. -o $@ $^

BINS += 0997/solution_cpp
0997/solution_cpp: 0997/solution.cpp
	g++ $(CFLAGS) -I. -o $@ $^

BINS += 1008/top_down_cpp
1008/top_down_cpp: 1008/top_down.cpp leetcode/tree.o
	g++ $(CFLAGS) -I. -o $@ $^

BINS += 1008/dfs_cpp
1008/dfs_cpp: 1008/dfs.cpp leetcode/tree.o
	g++ $(CFLAGS) -I. -o $@ $^

BINS += 1046/heap_cpp
1046/heap_cpp: 1046/heap.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 1071/gcd_cpp
1071/gcd_cpp: 1071/gcd.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 1091/bfs_cpp
1091/bfs_cpp: 1091/bfs.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 1094/solution_cpp
1094/solution_cpp: 1094/solution.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 1143/dp_cpp
1143/dp_cpp: 1143/dp.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 1143/dp_rs
1143/dp_rs: 1143/dp.rs
	rustc -o $@ $^

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

BINS += 1232/solution_cpp
1232/solution_cpp: 1232/solution.cpp
	g++ $(CFLAGS) -I. -o $@ $^

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

BINS += 1334/warshall_floyd_cpp
1334/warshall_floyd_cpp: 1334/warshall_floyd.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 1374/solution_cpp
1374/solution_cpp: 1374/solution.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 1375/solution_cpp
1375/solution_cpp: 1375/solution.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 1376/solution_cpp
1376/solution_cpp: 1376/solution.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 1377/solution_cpp
1377/solution_cpp: 1377/solution.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 1389/solution_cpp
1389/solution_cpp: 1389/solution.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 1390/solution_cpp
1390/solution_cpp: 1390/solution.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 1391/solution_cpp
1391/solution_cpp: 1391/solution.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 1392/rolling_hash_cpp
1392/rolling_hash_cpp: 1392/rolling_hash.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 1394/solution_cpp
1394/solution_cpp: 1394/solution.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 1395/solution_cpp
1395/solution_cpp: 1395/solution.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 1395/brute_force_cpp
1395/brute_force_cpp: 1395/brute_force.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 1395/dp_cpp
1395/dp_cpp: 1395/dp.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 1396/solution_cpp
1396/solution_cpp: 1396/solution.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 1396/hash_table_and_pair_cpp
1396/hash_table_and_pair_cpp: 1396/hash_table_and_pair.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 1408/solution_cpp
1408/solution_cpp: 1408/solution.cpp leetcode/assert.hpp
	g++ $(CFLAGS) -I. -o $@ $<

BINS += 1408/solution_after_contest_cpp
1408/solution_after_contest_cpp: 1408/solution_after_contest.cpp leetcode/assert.hpp
	g++ $(CFLAGS) -I. -o $@ $<

BINS += 1409/solution_cpp
1409/solution_cpp: 1409/solution.cpp leetcode/assert.hpp
	g++ $(CFLAGS) -I. -o $@ $<

BINS += 1410/solution_cpp
1410/solution_cpp: 1410/solution.cpp leetcode/assert.hpp
	g++ $(CFLAGS) -I. -o $@ $<

BINS += 1411/solution_cpp
1411/solution_cpp: 1411/solution.cpp leetcode/assert.hpp
	g++ $(CFLAGS) -I. -o $@ $<

BINS += 1417/solution_cpp
1417/solution_cpp: 1417/solution.cpp leetcode/assert.hpp
	g++ $(CFLAGS) -I. -o $@ $<

BINS += 1418/solution_cpp
1418/solution_cpp: 1418/solution.cpp leetcode/assert.hpp
	g++ $(CFLAGS) -I. -o $@ $<

BINS += 1419/solution_cpp
1419/solution_cpp: 1419/solution.cpp leetcode/assert.hpp
	g++ $(CFLAGS) -I. -o $@ $<

BINS += 1420/solution_cpp
1420/solution_cpp: 1420/solution.cpp leetcode/assert.hpp
	g++ $(CFLAGS) -I. -o $@ $<

BINS += 5000/sorting_cpp
5000/sorting_cpp: 5000/sorting.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 5000/hash_table_cpp
5000/hash_table_cpp: 5000/hash_table.cpp
	g++ $(CFLAGS) -o $@ $^

BINS += 5001/solution_cpp
5001/solution_cpp: 5001/solution.cpp leetcode/assert.hpp
	g++ $(CFLAGS) -I. -o $@ $<

BINS += 5002/binary_search_cpp
5002/binary_search_cpp: 5002/binary_search.cpp leetcode/assert.hpp
	g++ $(CFLAGS) -I. -o $@ $<

BINS += 5003/queue_cpp
5003/queue_cpp: 5003/queue.cpp
	g++ $(CFLAGS) -I. -o $@ $^

BINS += 5003/linked_list_cpp
5003/linked_list_cpp: 5003/linked_list.cpp leetcode/linked_list.o
	g++ $(CFLAGS) -I. -o $@ $^

BINS += 5004/dfs_cpp
5004/dfs_cpp: 5004/dfs.cpp leetcode/tree.o
	g++ $(CFLAGS) -I. -o $@ $^

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
