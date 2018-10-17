# 76ms 81.65%
class Solution:
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        # 把reslist写在前面会大幅度提高处理速度
        res_list, len_nums = [], len(candidates)
        candidates.sort()
        
        def mysum(target, temp_list, start_index = 0):
            for index in range(start_index, len_nums):
                temp = target - candidates[index]
                if temp is 0:
                    res_list.append(temp_list + [candidates[index]])
                elif temp < 0:
                    break
                else:
                    # 这里为了去重，增加了一个start_index
                    mysum(temp, temp_list + [candidates[index]], index)
        
        mysum(target, [])
        return res_list