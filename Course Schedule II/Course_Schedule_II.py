# Runtime: 64 ms, faster than 25.13% of Python3 online submissions for Course Schedule II.
# Memory Usage: 7.6 MB, less than 91.23% of Python3 online submissions for Course Schedule II.

class Solution:
    def findOrder(self, numCourses, prerequisites):

        inadj = [[] for i in range(numCourses)]
        for edge in prerequisites:
            inadj[edge[0]].append(edge[1])
        
        outadj = [[] for i in range(numCourses)]
        for edge in prerequisites:
            outadj[edge[1]].append(edge[0])

        degree = [len(inadj[i]) for i in range(numCourses)]

        delNode = []
        leftNode = numCourses

        res = []
        for i in range(numCourses):
            if degree[i] is 0:
                degree[i] == -1
                delNode.append(i)
                res.append(item)
                leftNode -= 1
        
        while leftNode > 0:
            if len(delNode) is 0:
                return []
            for i in range(len(delNode)):
                node = delNode.pop(0)
                for item in outadj[node]:
                    degree[item] -= 1
                    if degree[item] is 0:
                        leftNode -= 1
                        degree[item] = -1
                        delNode.append(item)
                        res.append(item)
        return res