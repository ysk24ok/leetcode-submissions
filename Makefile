OBJS = 0104/dfs.o leetcode/tree.o
BINS = 0104/dfs

0104/dfs: 0104/dfs.o leetcode/tree.o
	g++ -std=c++11 -o $@ $^

0104/dfs.o: 0104/dfs.cpp
	g++ -std=c++11 -o $@ -c $?

leetcode/tree.o: leetcode/tree.cpp
	g++ -std=c++11 -o $@ -c $?

.PHONY: all
all: $(BINS)

.PHONY: clean
clean:
	rm -f $(OBJS) $(BINS)
