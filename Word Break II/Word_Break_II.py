# 思路二的py代码

# Runtime: 48 ms, faster than 79.80% of Python3 online submissions for Word Break II.
# Memory Usage: 12.6 MB, less than 92.11% of Python3 online submissions for Word Break II.

class Solution:
    def wordBreak(self, s: 'str', wordDict: 'List[str]') -> 'List[str]':
        hashmap = dict()
        return self.helper(s, wordDict, hashmap)
    def helper(self, s, wordDict, hashmap):
        if len(s) not in hashmap:
            res = []
            for word in wordDict:
                if s[0:len(word)] == word:
                    nextstr = s[len(word):]
                    if nextstr == '':
                        res.append(word)
                    else:
                        for string in self.helper(nextstr, wordDict, hashmap):
                            res.append(word + ' ' + string)
            hashmap[len(s)] = res
        return hashmap[len(s)]
        