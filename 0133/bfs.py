"""breadth first search"""

from queue import Queue

# Definition for a undirected graph node
class UndirectedGraphNode:
    def __init__(self, x):
        self.label = x
        self.neighbors = []

class Solution:

    # @param node, a undirected graph node
    # @return a undirected graph node
    def cloneGraph(self, node):
        if node is None:
            return None
        # key: node label, value: cloned node
        visited_nodes = {}
        # nodes of next level are queued
        queue = Queue()

        cloned_node = UndirectedGraphNode(node.label)
        visited_nodes[node.label] = cloned_node
        queue.put(node)
        while queue.empty() is False:
            node = queue.get()
            for neighbor_node in node.neighbors:
                if neighbor_node.label not in visited_nodes:
                    cloned_neighbor_node = UndirectedGraphNode(neighbor_node.label)
                    visited_nodes[neighbor_node.label] = cloned_neighbor_node
                    queue.put(neighbor_node)
                visited_nodes[node.label].neighbors.append(
                    visited_nodes[neighbor_node.label])
        return cloned_node

if __name__ == '__main__':
    sol = Solution()

    node1 = UndirectedGraphNode(1)
    node2 = UndirectedGraphNode(2)
    node3 = UndirectedGraphNode(3)
    node1.neighbors.append(node1)
    node1.neighbors.append(node2)
    node1.neighbors.append(node3)
    node2.neighbors.append(node2)
    node2.neighbors.append(node1)
    node2.neighbors.append(node3)
    node3.neighbors.append(node3)
    node3.neighbors.append(node1)
    node3.neighbors.append(node2)
    cloned_node1 = sol.cloneGraph(node1)
    assert [1, 2, 3] == [node.label for node in cloned_node1.neighbors]
    assert [2, 1, 3] == [node.label for node in cloned_node1.neighbors[1].neighbors]
    assert [3, 1, 2] == [node.label for node in cloned_node1.neighbors[2].neighbors]

    node1 = UndirectedGraphNode(1)
    node1.neighbors.append(node1)
    node1.neighbors.append(node1)
    node1.neighbors.append(node1)
    cloned_node1 = sol.cloneGraph(node1)
    assert [1, 1, 1] == [node.label for node in cloned_node1.neighbors]
