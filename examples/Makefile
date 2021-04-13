CXX = g++
CXXFLAGS = -std=c++11
CPPFLAGS = -I. -I../gtest/include
LDFLAGS = -L../gtest/lib
LDLIBS = -lgtest -lgtest_main -lpthread

BINS =

BINS += binary_search
binary_search: binary_search.cpp

BINS += priority_queue
priority_queue: priority_queue.cpp

.PHONY: all
all: $(BINS) $(TESTS)

.PHONY: clean
clean:
	rm -f $(BINS) $(TESTS)
