# Runtime: 88 ms, faster than 76.14% of Python3 online submissions for Minimum Height Trees.
# Memory Usage: 10 MB, less than 100.00% of Python3 online submissions for Minimum Height Trees.

class Solution:
    def findMinHeightTrees(self, n, edges):
        adj = [[] for i in range(n)]
        for edge in edges:
            adj[edge[0]].append(edge[1])
            adj[edge[1]].append(edge[0])
        
        degree = [len(adj[i]) for i in range(n)]

        leftNode = n
        queue = []

        if leftNode > 2:
            for i in range(n):
                if degree[i] == 1:
                    degree[i] = -1
                    leftNode -= 1
                    queue.append(i)

        while leftNode > 2:
            size = len(queue)
            for i in range(size):
                node = queue.pop(0)
                for item in adj[node]:
                    degree[item] -= 1
                    if degree[item] == 1:
                        queue.append(item)
                        degree[item] = -1
                        leftNode -= 1

        return [i for i in range(n) if degree[i] >= 0]