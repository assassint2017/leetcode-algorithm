# 这里要注意python中的 // 运算符的问题所在

# Runtime: 36 ms, faster than 100.00% of Python3 online submissions for Evaluate Reverse Polish Notation.
# Memory Usage: 12.9 MB, less than 24.06% of Python3 online submissions for Evaluate Reverse Polish Notation.

class Solution:
    def evalRPN(self, tokens: 'List[str]') -> 'int':
        memo = []

        for token in tokens:
            if '0' <= token <= '9' or len(token) > 1:
                memo.append(int(token))
            else:
                op1 = memo.pop()
                op2 = memo.pop()

                if token == '+':
                    memo.append(op2 + op1)
                elif token == '-':
                    memo.append(op2 - op1)
                elif token == '*':
                    memo.append(op2 * op1)
                else:
                    memo.append(int(op2 / op1))
                
        return memo.pop();
