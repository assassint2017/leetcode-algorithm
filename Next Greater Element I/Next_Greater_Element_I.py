# Runtime: 40 ms, faster than 94.25% of Python3 online submissions for Next Greater Element I.
# Memory Usage: 13.2 MB, less than 85.02% of Python3 online submissions for Next Greater Element I.

class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        
        hashMap = dict()
        stack = []

        for i in range(len(nums2) - 1, -1, -1):
            while myStack and nums2[i] >= myStack[-1]:
                myStack.pop()
            
            hashMap[nums2[index]] = -1 if not myStack else myStack[-1]
            myStack.push(nums2[i])
        
        res = []
        for item in nums1:
            res.append(hashMap[item])
        return res