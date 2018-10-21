# 228ms 85.47%
class Solution:
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        m, n = len(board), len(board[0])
        if m is 0 or n is 0 or not word:
            return False

        def dfs(temp_word, start_i, start_j, path):
            if board[start_i][start_j] == word[len(temp_word)]:
                temp_word += board[start_i][start_j]
                if temp_word == word:
                    return True
                # 从上下左右四个方向分别进行搜索，这里一定要注意列表的浅拷贝问题
                if start_i + 1 < m and (start_i + 1, start_j) not in path and dfs(temp_word, start_i + 1, start_j, path | {(start_i, start_j)}):
                    return True
                if start_i - 1 >= 0 and (start_i - 1, start_j) not in path and dfs(temp_word, start_i - 1, start_j, path | {(start_i, start_j)}):
                    return True
                if start_j + 1 < n and (start_i, start_j + 1) not in path and dfs(temp_word, start_i, start_j + 1, path | {(start_i, start_j)}):
                    return True
                if start_j - 1 >= 0 and (start_i, start_j - 1) not in path and dfs(temp_word, start_i, start_j - 1, path | {(start_i, start_j)}):
                    return True
            else:
                return False
                    
        for i in range(m):
            for j in range(n):
                if dfs('', i, j, set()):
                    return True
        return False