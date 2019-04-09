# Runtime: 536 ms, faster than 78.17% of Python3 online submissions for Open the Lock.
# Memory Usage: 14.2 MB, less than 12.28% of Python3 online submissions for Open the Lock.

class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        
        curState = '0000'

        deadwords = set(deadends)
        hashset = set()

        queue = []
        queue.append(curState)
        hashset.add(curState)

        res = 0
        while queue:
            for _ in range(len(queue)):
                curState = queue.pop(0)
                if curState == target:
                    return res
                elif curState in deadwords:
                    continue
                else:
                    self.candidate(queue, hashset, curState)
            res += 1
        return -1
    
    def candidate(self, queue, hashset, curState):
        for i in range(4):
            temp = '0' if curState[i] == '9' else chr(ord(curState[i]) + 1)
            after = curState[:i] + temp + curState[i + 1:]

            temp = '9' if curState[i] == '0' else chr(ord(curState[i]) - 1)
            before = curState[:i] + temp + curState[i + 1:]

            if after not in hashset:
                queue.append(after)
                hashset.add(after)
            
            if before not in hashset:
                queue.append(before)
                hashset.add(before)