# Runtime: 560 ms, faster than 46.26% of Python3 online submissions for Word Ladder II.
# Memory Usage: 14.5 MB, less than 64.00% of Python3 online submissions for Word Ladder II.

class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        res = []

        candidate = set(wordList)
        memo = set()
        tempmemo = []

        hashmap = dict()

        todo = []
        todo.append(beginWord)

        finished = False
        while todo and not finished:
            for _ in range(len(todo)):
                word = todo.pop(0)
                if self.helper(word, endWord, candidate, hashmap, todo, tempmemo, memo):
                    finished = True
            while tempmemo:
                memo.add(tempmemo.pop())

        if finished:
            stack = []
            stack.append(endWord)
            self.dfs(endWord, hashmap, res, stack)
        
        return res
    
    def helper(self, word, endWord, candidate, hashmap, todo, tempmemo, memo):
        if word in candidate:
            candidate.remove(word)

        for i in range(len(word)):
            for j in range(26):
                new = word[:i] + chr(97 + j) + word[i + 1:]
                if new in candidate and new not in memo:
                    if new not in hashmap:
                        hashmap[new] = [word]
                        todo.append(new)
                        tempmemo.append(new)
                    else:
                        hashmap[new].append(word)
                    if new == endWord:
                        return True
        return False

        
    def dfs(self, endWord, hashmap, res, stack):
        if endWord in hashmap:
            for word in hashmap[endWord]:
                stack.append(word)
                self.dfs(word, hashmap, res, stack)
                stack.pop()
        else:
            tempRes = []
            for i in range(len(stack) - 1, -1, -1):
                tempRes.append(stack[i])
            res.append(tempRes)