from collections import defaultdict
from typing import *


class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        neighbors = defaultdict(list)
        visited = [0 for i in range(numCourses)]
        for curr_course, pre_course in prerequisites:
            neighbors[pre_course].append(curr_course)
        ret = []
        for course in range(numCourses):
            if not self.dfs(neighbors, visited, course, ret):
                return []
        return ret

    def dfs(self, neighbors, visited, curr_course, ret):
        if visited[curr_course] == -1:
            return False
        if visited[curr_course] == 1:
            return True
        visited[curr_course] = -1
        for neighbor in neighbors[curr_course]:
            if not self.dfs(neighbors, visited, neighbor, ret):
                return False
        ret.insert(0, curr_course)
        visited[curr_course] = 1
        return True


if __name__ == '__main__':
    sol = Solution()

    numCourses, prerequisites = 2, [[1,0]]
    expected = [0,1]
    assert sol.findOrder(numCourses, prerequisites) == expected

    numCourses, prerequisites = 4, [[1,0],[2,0],[3,1],[3,2]]
    expected = ([0,1,2,3], [0,2,1,3])
    assert sol.findOrder(numCourses, prerequisites) in expected
