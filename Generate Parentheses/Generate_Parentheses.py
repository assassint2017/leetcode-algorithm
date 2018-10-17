# 40ms 90.62%
class Solution:
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        res_list = []
        def gen(strs, num_open, num_close):
            """
            num_open: 左括号的数量
            num_close: 右括号的数量
            """
            if len(strs) == 2 * n:
                res_list.append(strs)
            if num_open < n:
                gen(strs + '(', num_open + 1, num_close)
            if num_open > num_close:
                gen(strs + ')', num_open, num_close + 1)
        
        gen('', 0, 0)
        return res_list