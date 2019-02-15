# Runtime: 36 ms, faster than 99.51% of Python3 online submissions for Two Sum II - Input array is sorted.
# Memory Usage: 12.6 MB, less than 100.00% of Python3 online submissions for Two Sum II - Input array is sorted.

class Solution:
    def twoSum(self, numbers: 'List[int]', target: 'int') -> 'List[int]':
        res = []
        leftPtr, rightPtr = 0, len(numbers) - 1

        while leftPtr < rightPtr:
            temp = numbers[leftPtr] + numbers[rightPtr]
            if (temp == target):
                res.append(leftPtr + 1)
                res.append(rightPtr + 1)
                break
            elif temp > target:
                rightPtr -= 1
            else:
                leftPtr += 1
        
        return res