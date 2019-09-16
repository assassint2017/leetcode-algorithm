# Runtime: 760 ms, faster than 81.43% of Python3 online submissions for Find Eventual Safe States.
# Memory Usage: 20.5 MB, less than 7.69% of Python3 online submissions for Find Eventual Safe States.

class Solution:
    def eventualSafeNodes(self, outadj: List[List[int]]) -> List[int]:
        
        res = []
        numOfNode = len(outadj)
        memo = [0 for i in range(numOfNode)]

        for i in range(numOfNode):
            if self.dfs(outadj, i, memo) is True:
                res.append(i)
        
        return res

    def dfs(self, outadj, startNode, memo):

        if memo[startNode] is not 0:
            if memo[startNode] is 1:
                return False
            elif memo[startNode] is 2:
                return True
            else:
                memo[startNode] = 1
                return False
        
        memo[startNode] = 3
        for node in outadj[startNode]:
            if self.dfs(outadj, node, memo) is False:
                memo[startNode] = 1
                return False
        
        memo[startNode] = 2
        return True
