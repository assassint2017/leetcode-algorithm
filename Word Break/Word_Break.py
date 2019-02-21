# Runtime: 36 ms, faster than 98.71% of Python3 online submissions for Word Break.
# Memory Usage: 12.7 MB, less than 18.75% of Python3 online submissions for Word Break.

class Solution:
    def wordBreak(self, s: 'str', wordDict: 'List[str]') -> 'bool':
        visited = [False for i in range(len(s) + 1)]
        
        return self.helper(s, wordDict, visited)

    def helper(self, s, wordDict, visited):
        if visited[len(s)]:
            return False
        else:
            if len(s) is 0:
                return True
            for word in wordDict:
                if s[0:len(word)] == word:
                    if self.helper(s[len(word):], wordDict, visited):
                        return True
            visited[len(s)] = True
            return False