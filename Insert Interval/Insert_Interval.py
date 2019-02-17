# 思路二的py代码
# 这样的代码，会导致列表中的对象是共享的，所以还是有一点问题的，但是懒得修改了

# Runtime: 56 ms, faster than 86.15% of Python3 online submissions for Insert Interval.
# Memory Usage: 15.8 MB, less than 100.00% of Python3 online submissions for Insert Interval.

# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[Interval]
        :type newInterval: Interval
        :rtype: List[Interval]
        """
        res = []
        insert = False
        index = 0
        while index != len(intervals):
            if intervals[index].end < newInterval.start:
                res.append(intervals[index])
            elif intervals[index].start > newInterval.end:
                insert = True
                res.append(newInterval)
                res.append(intervals[index])
                break
            else:
                newInterval.start = min(intervals[index].start, newInterval.start)
                newInterval.end = max(intervals[index].end, newInterval.end)
            index += 1
        
        
        if not insert:
            res.append(newInterval)
        else:
            index += 1
            while index != len(intervals):
                res.append(intervals[index])
                index += 1
        return res