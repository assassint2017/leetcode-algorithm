# 思路二的py代码
# 172ms 91.22%

class Solution:
    def minDistance(self, word1, word2):
        temp = [i for i in range(len(word2) + 1)]
        steps = [0 for _ in range(len(word2) + 1)]
        for i in range(1, len(word1) + 1):
            steps[0] = i
            for j in range(1, len(word2) + 1):
                if word1[i - 1] == word2[j - 1]:
                    steps[j] = temp[j - 1]
                else:
                    stepDelete = temp[j]
                    stepReplace = temp[j - 1]
                    stepInsert = steps[j - 1]
                    steps[j] = min(stepDelete, stepInsert, stepReplace) + 1
            for j in range(len(word2) + 1):
                temp[j] = steps[j]
        return temp[len(word2)]