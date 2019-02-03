# 非递归回溯版本的py代码

# Runtime: 104 ms, faster than 48.13% of Python3 online submissions for N-Queens.
# Memory Usage: 7 MB, less than 87.93% of Python3 online submissions for N-Queens.

class Solution:
    def solveNQueens(self, n):
        if n is 1:
            return [['Q']]
        res = []
        queens = []
        i, j = 0, 0
        while True:
            found = False
            while j < n:
                if self.isSafe(j, queens):
                    found = True
                    queens.append(j)
                    if len(queens) == n:
                        res.append(self.genBoard(queens))
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
    
    def genBoard(self, queens):
        board = []
        for queen in queens:
            temp = ['.' for i in range(len(queens))]
            temp[queen] = 'Q'
            board.append(''.join(temp))
        return board