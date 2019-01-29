# 思路一的py代码
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

# 思路二的py代码
# 56ms 100%

class Solution:
    def candy(self, ratings):
        sum, pre, count = 1, 1, 1
        for i in range(1, len(ratings)):
            if ratings[i] >= ratings[i - 1]:
                if count > 1:
                    sum += count * (count - 1) // 2
                    if (pre < count):
                        sum += (count - pre)
                    pre = 1
                if (ratings[i] == ratings[i - 1]):
                    pre = 0

                pre += 1
                sum += pre
                count = 1
            else:
                count += 1
        if count > 1:
            sum += count * (count - 1) // 2
            if (pre < count):
                sum += (count - pre)
        return sum
