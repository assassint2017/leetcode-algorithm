# BFS
# Runtime: 540 ms, faster than 42.47% of Python3 online submissions for Word Ladder.

# Memory Usage: 13.9 MB, less than 26.91% of Python3 online submissions for Word Ladder.

class Solution:
    def ladderLength(self, beginWord: 'str', endWord: 'str', wordList: 'List[str]') -> 'int':
        hashset = set(wordList)
        candidate = [beginWord]
        minLength = 1
        while candidate:
            for size in range(len(candidate)):
                word = candidate.pop(0)
                if word == endWord:
                    return minLength
                else:
                    self.helper(candidate, hashset, word)
            minLength += 1
        return 0

    def helper(self, candidate, hashset, word):
        for i in range(len(word)):
            for j in range(26):
                new = word[:i] + chr(97 + j) + word[i + 1:]
                if new in hashset:
                    candidate.append(new)
                    hashset.remove(new)

# 使用自带的队列实现
# 结果发现效率还不如就只用列表 badbad

# Runtime: 616 ms, faster than 33.51% of Python3 online submissions for Word Ladder.
# Memory Usage: 14.2 MB, less than 26.55% of Python3 online submissions for Word Ladder.

import queue
class Solution:
    def ladderLength(self, beginWord: 'str', endWord: 'str', wordList: 'List[str]') -> 'int':
        hashset = set(wordList)
        candidate = queue.Queue()
        candidate.put(beginWord)
        minLength = 1
        while not candidate.empty():
            for size in range(candidate.qsize()):
                word = candidate.get()
                if word == endWord:
                    return minLength
                else:
                    self.helper(candidate, hashset, word)
            minLength += 1
        return 0

    def helper(self, candidate, hashset, word):
        for i in range(len(word)):
            for j in range(26):
                new = word[:i] + chr(97 + j) + word[i + 1:]
                if new in hashset:
                    candidate.put(new)
                    hashset.remove(new)