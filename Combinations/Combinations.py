# 第一种思路
# 740ms 45.65%
class Solution:
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        def mycombine(num_list, temp_list):
            if len(temp_list) == k - 1:
                for num in num_list:
                    res_list.append(temp_list + [num])
            for index in range(len(num_list)):
                mycombine(num_list[index + 1:], temp_list + [num_list[index]])
            
        res_list = []
        mycombine(list(range(1, n + 1)), [])
        return res_list

# 第二种思路，讨论区一个大神给出的思路，但是并没有看懂
# 172ms 76.24%
class Solution:
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """ 
        if k == 0:
            return [[]]
        return [pre + [i] for i in range(k, n+1) for pre in self.combine(i-1, k-1)]