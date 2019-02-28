# 思路三的py代码
# 这道题目对于python而言其实是很简单的，因为python中字符串是不可更改的对象，所以就没有inplace的操作

# Runtime: 36 ms, faster than 100.00% of Python3 online submissions for Reverse Words in a String.
# Memory Usage: 13.4 MB, less than 100.00% of Python3 online submissions for Reverse Words in a String.

class Solution:
    def reverseWords(self, s: str) -> str:
        templist = s.split()
        templist.reverse()
        return ' '.join(templist,)
        