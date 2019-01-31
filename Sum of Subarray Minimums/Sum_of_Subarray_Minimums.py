# 思路三的py代码
# 328ms 15.79%

class Solution:
    def sumSubarrayMins(self, A):

        ple = [i + 1 for i in range(len(A))]
        nle = [len(A) - i for i in range(len(A))]
        pleStack, nleStack = [], []

        for i in range(len(A)):
            while pleStack and pleStack[-1][0] > A[i]:
                pleStack.pop()
            ple[i] = i - pleStack[-1][1] if pleStack else i + 1
            pleStack.append((A[i], i))

            while nleStack and nleStack[-1][0] > A[i]:
                temp = nleStack.pop()
                nle[temp[1]] = i - temp[1]
            nleStack.append((A[i], i))

        return int(sum([A[i] * ple[i] * nle[i] for i in range(len(A))]) % (1e9 + 7))