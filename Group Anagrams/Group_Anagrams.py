# 第一种思路，使用字典
# 120ms 97.19%
class Solution:
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        dicts = {}
        for letters in strs:
            temp = ''.join(sorted(letters))
            if temp not in dicts:
                dicts[temp] = [letters]
            else:
                dicts[temp].append(letters)
        return [value for value in dicts.values()]