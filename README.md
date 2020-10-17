leetcode-submissions
===

My submissons for LeetCode OJ (https://leetcode.com/ysk24ok/)

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
