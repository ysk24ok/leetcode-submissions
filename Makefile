OBJS = 0104/dfs.o leetcode/tree.o
BINS = 0104/dfs
TESTS = test/tree_test

.PHONY: all
all: $(BINS) $(TESTS)

.PHONY: check
check:
	$(TESTS)

.PHONY: clean
clean:
	rm -f $(OBJS) $(BINS) $(TESTS)

0104/dfs: 0104/dfs.o leetcode/tree.o
	g++ -std=c++11 -o $@ $^

0104/dfs.o: 0104/dfs.cpp
	g++ -std=c++11 -o $@ -c $?

leetcode/tree.o: leetcode/tree.cpp
	g++ -std=c++11 -o $@ -c $?

test/tree_test: test/tree_test.cpp leetcode/tree.o
	g++ -std=c++11 -Igtest/include -Lgtest/lib -lgtest -lgtest_main -o $@ $^
