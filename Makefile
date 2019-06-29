OBJS = 0104/dfs.o 0297/bfs.o 0297/dfs.o leetcode/linked_list.o leetcode/tree.o
BINS = 0083/linked_list 0104/dfs 0297/bfs 0297/dfs
TESTS = test/tree_test test/linked_list_test

.PHONY: all
all: $(BINS) $(TESTS)

.PHONY: check
check:
	$(TESTS)

.PHONY: clean
clean:
	rm -f $(OBJS) $(BINS) $(TESTS)

0083/linked_list: 0083/linked_list.cpp leetcode/linked_list.o
	g++ -std=c++11 -o $@ $^

0104/dfs: 0104/dfs.o leetcode/tree.o
	g++ -std=c++11 -o $@ $^

0104/dfs.o: 0104/dfs.cpp
	g++ -std=c++11 -o $@ -c $?

0297/dfs: 0297/dfs.o leetcode/tree.o
	g++ -std=c++11 -o $@ $^

0297/dfs.o: 0297/dfs.cpp
	g++ -std=c++11 -o $@ -c $?

0297/bfs: 0297/bfs.o leetcode/tree.o
	g++ -std=c++11 -o $@ $^

0297/bfs.o: 0297/bfs.cpp
	g++ -std=c++11 -o $@ -c $?

leetcode/tree.o: leetcode/tree.cpp
	g++ -std=c++11 -o $@ -c $?

leetcode/linked_list.o: leetcode/linked_list.cpp
	g++ -std=c++11 -o $@ -c $?

test/linked_list_test: test/linked_list_test.cpp leetcode/linked_list.o
	g++ -std=c++11 -Igtest/include -Lgtest/lib -lgtest -lgtest_main -o $@ $^

test/tree_test: test/tree_test.cpp leetcode/tree.o
	g++ -std=c++11 -Igtest/include -Lgtest/lib -lgtest -lgtest_main -o $@ $^
