// 思路一 自顶向下的备忘录动态规划
// 如果不使用备忘录就会超时
// 16ms 8.41%

#include<string>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        // 申请空间，这里注意一下二维动态数组的申请
        int **steps = new int*[word1.length() + 1];
        for (int i = 0; i <= word1.length(); i++)
            steps[i] = new int[word2.length() + 1];
        
        // 初始化
        for (int i = 0; i <= word1.length(); i++)
            for (int j = 0; j <= word2.length(); j++)
                steps[i][j] = -1;
        
        // 动态规划
        int res = dp(word1, word2, steps);
        
        // 释放空间
        delete[] steps;

        return res;
    }

    int dp(string word1, string word2, int **steps)
    {
        if (steps[word1.length()][word2.length()] == - 1)
        {
            // 判断两个字符串是否为空
            if (word1 == "" && word2 == "")
                steps[word1.length()][word2.length()] = 0;
            else if (word1 == "")
                steps[word1.length()][word2.length()] = word2.length();
            else if (word2 == "")
                steps[word1.length()][word2.length()] = word1.length();
            else
            {
                // 如果两者都不为空的情况下进行递归的判断
                // 如果两个字符串的最后一位是相等的
                if (word2[word2.length() - 1] == word1[word1.length() - 1])
                    steps[word1.length()][word2.length()] = dp(word1.substr(0, word1.length() - 1), word2.substr(0, word2.length() - 1), steps);
                
                // 不相等
                else
                {
                    // 删除最后一个
                    int stepDelete = dp(word1.substr(0, word1.length() - 1), word2.substr(0, word2.length()), steps);

                    // 替换最后一个
                    int stepReplace = dp(word1.substr(0, word1.length() - 1), word2.substr(0, word2.length() - 1), steps);

                    // 在最后一位上插入
                    int stepInsert = dp(word1.substr(0, word1.length()), word2.substr(0, word2.length() - 1), steps);

                    steps[word1.length()][word2.length()] = minThree(stepDelete, stepReplace, stepInsert) + 1;
                }
            }
        }
        return steps[word1.length()][word2.length()];
    }

    inline int minThree(int a, int b, int c)
    {
        int temp = a < b ? a : b;
        return temp < c ? temp : c;
    }
};


// 思路二 自底向上的递推动规 节省空间版本
// 4ms 100%

class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        // 初始化第一行的结果
        int *temp = new int[word2.length() + 1];
        int *steps = new int[word2.length() + 1];
        for (int i = 0; i <= word2.length(); i++)
            temp[i] = i;

        for (int i = 1; i <= word1.length(); i++)
        {
            steps[0] = i;
            for (int j = 1; j <= word2.length(); j++)
            {
                if (word1[i - 1] == word2[j - 1])
                    steps[j] = temp[j - 1];
                else
                {
                    int stepDelete = temp[j];
                    int stepReplace = temp[j - 1];
                    int stepInsert = steps[j - 1];

                    int temp = stepDelete < stepReplace ? stepDelete : stepReplace;
                    steps[j] = 1 + (temp < stepInsert ? temp : stepInsert);
                }
            }

            for (int j = 0; j <= word2.length(); j++)
                temp[j] = steps[j];
        }
        
        int res = temp[wpord2.length()];

        // 释放空间
        delete[] steps;
        delete[] temp;

        return res;
    }
};