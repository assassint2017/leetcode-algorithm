# 52ms 95.29%
class Solution:
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        res_list = []
        candidates.sort()
        
        def mysum(candidates, target, temp_list):
            for index in range(len(candidates)):
                if index > 0 and candidates[index] == candidates[index - 1]:
                    continue
                temp = target - candidates[index]
                if temp is 0:
                    res_list.append(temp_list + [candidates[index]])
                elif temp < 0:
                    break
                else:
                    mysum(candidates[index + 1:], temp, temp_list + [candidates[index]])
        
        mysum(candidates, target, [])
        return res_list