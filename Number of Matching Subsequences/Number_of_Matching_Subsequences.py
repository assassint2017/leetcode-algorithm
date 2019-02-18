# Runtime: 2132 ms, faster than 2.71% of Python3 online submissions for Number of Matching Subsequences.
# Memory Usage: 15 MB, less than 100.00% of Python3 online submissions for Number of Matching Subsequences.

class Solution:
    def numMatchingSubseq(self, S: 'str', words: 'List[str]') -> 'int':
        memo = [[] for i in range(128)]
        for i in range(len(S)):
            memo[ord(S[i])].append(i)

        res = 0
        for word in words:
            found = True
            pos = 0
            for i in range(len(word)):
                if not memo[ord(word[i])]:
                    found = False
                    break
                leftPtr, rightPtr = 0, len(memo[ord(word[i])]) - 1
                while leftPtr < rightPtr:
                    midPtr = (leftPtr + rightPtr) // 2
                    if memo[ord(word[i])][midPtr] < pos:
                        leftPtr = midPtr + 1
                    else:
                        rightPtr = midPtr
                if memo[ord(word[i])][leftPtr] >= pos:
                    pos = memo[ord(word[i])][leftPtr] + 1
                else:
                    found = False
                    break
            if found:
                res += 1
        return res