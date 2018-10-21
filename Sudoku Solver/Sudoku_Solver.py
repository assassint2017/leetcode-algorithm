# 532ms 55.56%
class Solution:
    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        self.board = board
        self.solve()
    
    def find_first_unassigned(self):
        """
        
        顺序查找第一个还没有被赋值的坐标
        """
        for i in range(9):
            for j in range(9):
                if self.board[i][j] == '.':
                    return i, j
        # 如果全部被赋值，则返回一个哑变量
        return -1, -1
        
    def judge(self, row, column, value):
        """
        
        用来判断给定坐标的值是否合理
        """
        # 首先判断行
        if value in self.board[row]:
            return False
        # 然后判断列
        for i in range(9):
            if self.board[i][column] == value:
                return False
        # 最后判断宫
        for i in range(row // 3 * 3, row // 3 * 3 + 3):
            for j in range(column // 3 * 3, column // 3 * 3 + 3):
                if self.board[i][j] == value:
                    return False
        # 如果都通过了测试，则返回真
        return True
    
    def solve(self):
        row, column = self.find_first_unassigned()
        if row == - 1 and column == -1:
            return True
        for num in ["1","2","3","4","5","6","7","8","9"]:
            if self.judge(row, column, num):
                self.board[row][column] = num
                if self.solve():
                    return True
                self.board[row][column] = '.'
        return False