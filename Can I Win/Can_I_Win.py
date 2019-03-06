# Runtime: 684 ms, faster than 55.34% of Python3 online submissions for Can I Win.
# Memory Usage: 21.4 MB, less than 54.35% of Python3 online submissions for Can I Win.

class Solution:
    def canIWin(self, maxChoosableInteger: int, desiredTotal: int) -> bool:
        if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal):
            return False
        if (maxChoosableInteger >= desiredTotal):
            return True

        states = ['F' for i in range(maxChoosableInteger)]
        hashmap = dict()

        return self.helper(desiredTotal, states, hashmap)

    def helper(self, desiredTotal, states, hashmap):
        string = ''.join(states)
        if string in hashmap:
            return hashmap[string]

        for i in range(len(states)):
            if states[i] == 'F':
                states[i] = 'T'
                if i + 1 >= desiredTotal or not self.helper(desiredTotal - i - 1, states, hashmap):
                    states[i] = 'F'
                    hashmap[''.join(states)] = True
                    return True
                else:
                    states[i] = 'F'
        
        hashmap[string] = False
        return False