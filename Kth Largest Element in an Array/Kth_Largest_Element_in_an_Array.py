# 132ms 23.21%

class Solution:
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        maxSize = len(nums) - 1
        self.creatMaxHeap(nums)

        for i in range(k - 1):
            self.deleteFromHeap(nums, maxSize)
            maxSize -= 1
        
        return nums[0]
    
    def creatMaxHeap(self, maxHeap):
        def helper(index):
            temp = maxHeap[index]
            parent = index
            while parent * 2 + 1 <= len(maxHeap) - 1:

                child = parent * 2 + 1
                if (child + 1 <= len(maxHeap) - 1 and maxHeap[child] < maxHeap[child + 1]):
                    child += 1
                if temp > maxHeap[child]:
                    break;
                else:
                    maxHeap[parent] = maxHeap[child]
                parent = child
            maxHeap[parent] = temp
        for i in range(len(maxHeap) - 1, -1, -1):
            helper(i)
    
    def deleteFromHeap(self, maxHeap, maxSize):
        temp = maxHeap[maxSize]
        parent = 0
        while parent * 2 + 1 <= maxSize:
            child = parent * 2 + 1
            if child + 1 <= maxSize and maxHeap[child] < maxHeap[child + 1]:
                child += 1
            if temp > maxHeap[child]:
                break;
            else:
                maxHeap[parent] = maxHeap[child]
            parent = child
        maxHeap[parent] = temp