# 60ms 99.71%

# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        intervals.sort(key=lambda x:x.start)
        res_list = []
        
        for interval in intervals:
            if not res_list or res_list[-1].end < interval.start:
                res_list.append(interval)
            else:
                res_list[-1].end = max(res_list[-1].end, interval.end)
        return res_list