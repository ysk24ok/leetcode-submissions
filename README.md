leetcode-submissions
===

My submissions for LeetCode (https://leetcode.com/ysk24ok/)

## Setup

Build gtest.

```console
$ export GTEST_VERSION=1.8.1
$ curl -OL https://github.com/google/googletest/archive/release-${GTEST_VERSION}.tar.gz
$ tar zxvf release-${GTEST_VERSION}.tar.gz
$ pushd googletest-release-${GTEST_VERSION}/googletest
$ mkdir mybuild
$ cd mybuild
$ cmake ..
$ make
$ popd
$ mkdir -p gtest/lib
$ cp -R googletest-release-${GTEST_VERSION}/googletest/include gtest
$ cp googletest-release-${GTEST_VERSION}/googletest/mybuild/libgtest* gtest/lib
$ rm -rf googletest-release-${GTEST_VERSION}
$ rm -f release-${GTEST_VERSION}.tar.gz
```

## Execution

### C++

```console
$ bin/new cpp 1234 solution
$ make 1234/solution && 1234/solution
```

### Rust

```console
$ bin/new cpp 1234 solution
$ cargo run --bin 1234_solution
```

### Go

```console
$ bin/new go 1234 solution
$ go run 1234/solution.go
```

### Python

```console
$ bin/new py 1234 solution
$ python 1234/solution.py
```
