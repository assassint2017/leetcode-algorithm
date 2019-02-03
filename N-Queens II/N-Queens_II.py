# 非递归回溯版本的py代码
# Runtime: 100 ms, faster than 43.16% of Python3 online submissions for N-Queens II.
# Memory Usage: 6.5 MB, less than 50.00% of Python3 online submissions for N-Queens II.

class Solution:
    def totalNQueens(self, n):
        if n is 1:
            return 1
        res = 0
        queens = []
        i, j = 0, 0
        while True:
            found = False
            while j < n:
                if self.isSafe(j, queens):
                    found = True
                    queens.append(j)
                    if len(queens) == n:
                        res += 1
                        queens.pop()
                        found = False
                    else:
                        break
                j += 1
            if found:
                i += 1
                j = 0
            else:
                i -= 1
                j = queens.pop() + 1
                if (i is 0 and j == n):
                    return res

    def isSafe(self, curCol, queens):
        curRow = len(queens)
        for i in range(len(queens)):
            queenRow = i
            queenCol = queens[i]
            if curCol == queenCol:
                return False
            if curRow - queenRow == abs(curCol - queenCol):
                return False
        return True