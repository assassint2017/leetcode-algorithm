# 80ms 44.90%

class Solution:
    def candy(self, ratings):
        """
        :type ratings: List[int]
        :rtype: int
        """
        numCandy = [1 for i in range(len(ratings))]

        for i in range(1, len(ratings)):
            if ratings[i] > ratings[i - 1]:
                numCandy[i] = numCandy[i - 1] + 1
        
        for i in range(len(ratings)- 2, -1, -1):
            if ratings[i] > ratings[i + 1] and numCandy[i] <= numCandy[i + 1]:
                numCandy[i] = numCandy[i + 1] + 1
                
        return sum(numCandy)
        