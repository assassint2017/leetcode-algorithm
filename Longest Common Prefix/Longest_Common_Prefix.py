# 36ms 99.78%
class Solution:
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        index, prefix = 0, ''
        while True:
            try:
                letters = [string[index] for string in strs]
                if len(set(letters)) is 1:
                    prefix += letters[0]
                else:
                    break
                index += 1
            except Exception as e:
                break
        return prefix