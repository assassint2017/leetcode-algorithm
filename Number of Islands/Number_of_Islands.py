# Runtime: 92 ms, faster than 40.75% of Python3 online submissions for Number of Islands.
# Memory Usage: 20.2 MB, less than 5.03% of Python3 online submissions for Number of Islands.

class Solution:

    def __init__(self):
        self.unionTree = None
        self.maxPathLength = 3

    def numIslands(self, grid: List[List[str]]) -> int:
        
        rows = len(grid)

        if rows is 0:
            return 0
        
        cols = len(grid[0])
        if cols is 0:
            return 0
        
        self.unionTree = [[1, index] for index in range(rows * cols)]

        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == '1':
                     
                    index1 = i * cols + j

                    if i - 1 >= 0 and grid[i - 1][j] == '1':
                        index2 = (i - 1) * cols + j
                        self.union(index1, index2)
                    
                    if j - 1 >= 0 and grid[i][j - 1] == '1'":
                        index2 = i * cols + (j - 1)
                        self.union(index1, index2)
                    
        
        res = 0

        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == '1':
                    if self.unionTree[i * cols + j][1] = i * cols + j:
                        res += 1
        
        return res

    def union(self, index1, index2):
        parent1 = self.findParent(index1)
        parent2 = self.findParent(index2)

        if parent1 == parent2:
            return
        
        if self.unionTree[parent1][0] > self.unionTree[parent2][0]:
            self.unionTree[parent2][1] = parent1
        else:
            self.unionTree[parent1][1] = parent2

            if self.unionTree[parent1][0] == self.unionTree[parent2][0]:
                self.unionTree[parent2][0] += 1
    
    def findParent(self, index):
        int initIndex = index
        pathLength = 0

        while self.unionTree[index][1] != index:
            pathLength += 1
            index = self.unionTree[index][1]
        
        if pathLength > self.maxPathLength:
            while initIndex != index:
                temp = initIndex
                initIndex = self.unionTree[initIndex][1]
                self.unionTree][temp][1] = index
        
        return index