// 思路一 简单粗暴的使用三重循环
// 91/100 pass 超时了

class Solution {
public:
    int sumSubarrayMins(vector<int>& A) 
    {
        int sum = 0;
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = i; j < A.size(); j++)
            {
                int min = A[i];
                for (int k = i + 1; k <= j; k++)
                {
                    if (A[k] < min)
                        min = A[k];
                }
                if ((sum + min) > (1e9 + 7))
                    sum = (sum + min) % static_cast<int>(1e9 + 7);
                else
                    sum += min;
            }
        } 
        return sum;     
    }
};

// 思路二 求序列最小值的时候进行了改进
// 4752ms 0% 已经徘徊在超时的边缘了

class Solution {
public:
    int sumSubarrayMins(vector<int>& A) 
    {
        int sum = 0;
        for (int i = 0; i < A.size(); i++)
        {
            int min = A[i];
            for (int j = i; j < A.size(); j++)
            {
                if (A[j] < min)
                    min = A[j];
                if ((sum + min) > (1e9 + 7))
                    sum = (sum + min) % static_cast<int>(1e9 + 7);
                else
                    sum += min;
            }
        } 
        return sum;     
    }
};


// 思路三 使用递增栈
// 64ms 72.22%

class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        
        // 第一个为value 第二个为索引
        stack<pair<int, int>> pleStack, nleStack;

        int *ple = new int[A.size()];
        int *nle = new int[A.size()];

        // 初始化
        // for (int i = 0; i < A.size(); i++) ple[i] = i + 1;
        for (int i = 0; i < A.size(); i++) nle[i] = A.size() - i;

        // one pass
        for (int i = 0; i < A.size(); i++)
        {
            // ple
            while (!pleStack.empty() && pleStack.top().first > A[i]) 
                pleStack.pop();
            ple[i] = pleStack.empty() ? i + 1 : i - pleStack.top().second;
            pleStack.push(pair<int, int>(A[i], i));

            // nle
            while (!nleStack.empty() && nleStack.top().first > A[i])
            {
                pair<int, int> temp = nleStack.top();
                nleStack.pop();
                nle[temp.second] = i - temp.second;
            }
            nleStack.push(pair<int, int>(A[i], i));
        }

        // 累计求和
        int sum = 0;
        for (int i = 0; i < A.size(); i++)
            sum = (sum + A[i] * ple[i] * nle[i]) % static_cast<int>(1e9 + 7);
        
        // 释放空间
        delete[] ple;
        delete[] nle;

        return sum;
    }
};