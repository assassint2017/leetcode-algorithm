# Runtime: 252 ms, faster than 22.67% of Python3 online submissions for Minimum Window Substring.
# Memory Usage: 14.1 MB, less than 100.00% of Python3 online submissions for Minimum Window Substring.

class Solution:
    def minWindow(self, s: 'str', t: 'str') -> 'str':
        if len(s) is 0 or len(t) is 0:
            return 0
        
        remap, curmap = dict(), dict()
        for chr in t:
            curmap[chr] = 0
            if chr in remap:
                remap[chr] += 1
            else:
                remap[chr] = 1

        queue = []
        curnum = 0
        num = len(t)
        minnum = float('inf')
        res = ''

        for i in range(len(s)):
            if s[i] in curmap:
                if (curmap[s[i]] < remap[s[i]]):
                    curnum += 1
                curmap[s[i]] += 1
                queue.append((s[i], i))

                while curnum == num:
                    strlen = queue[-1][1] - queue[0][1] + 1
                    if strlen < minnum:
                        minnum = strlen
                        res = s[queue[0][1]:queue[-1][1] + 1]
                    
                    curmap[queue[0][0]] -= 1
                    if curmap[queue[0][0]] < remap[queue[0][0]]:
                        curnum -= 1
                    queue.pop(0)
        return res