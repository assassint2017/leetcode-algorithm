# Runtime: 40 ms, faster than 100.00% of Python3 online submissions for Bag of Tokens.
# Memory Usage: 6.5 MB, less than 76.92% of Python3 online submissions for Bag of Tokens.

class Solution:
    def bagOfTokensScore(self, tokens, P):

        sortTokens = tokens[:]
        sortTokens.sort()

        minPtr, maxPtr = 0, len(sortTokens) - 1
        score = 0

        while True:
            while minPtr <= maxPtr and P >= sortTokens[minPtr]:
                P -= sortTokens[minPtr]
                score += 1
                minPtr += 1
            if maxPtr - minPtr < 2:
                return score
            if score > 0:
                score -= 1
                P += sortTokens[maxPtr]
                maxPtr -= 1
            else:
                return 0
        