# 56ms 97.89%
class Solution:
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        # 首先判断行
        for row in board:
            if self.judge(row) is False:
                return False
        # 然后判断列
        for i in range(9):
            column = [row[i] for row in board]
            if self.judge(column) is False:
                return False
        # 最后判断宫
        for i in range(0, 9, 3):
            for j in range(0, 9, 3):
                sub_box = [item[j:j + 3] for item in board[i:i + 3]]
                sub_box = sub_box[0] + sub_box[1] + sub_box[2]
                if self.judge(sub_box) is False:
                    return False
        return True

    def judge(self, num_list):
        temp_list = [num for num in num_list if num is not '.']
        if len(temp_list) == len(set(num_list)) - 1:
            return True
        else:
            return False