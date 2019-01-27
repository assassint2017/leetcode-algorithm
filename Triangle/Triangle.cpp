// 动态规划 思路一 简单递归 自顶向下
// 在最后的一个测试用例上超时了

#include<vector>
using namespace std;

typedef vector<vector<int>> vecii;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        return dp(0, 0, triangle);
    }

    int dp(int i, int j, vecii &triangle)
    {
        if (i < triangle.size() - 1)
        {
            int left = dp(i + 1, j, triangle);
            int right = dp(i + 1, j + 1, triangle);
    
            return triangle[i][j] + (left < right ? left : right);
        }
        else
        {
            return triangle[i][j];
        }   
    }
};


// 动态规划 思路二 自顶向下+备忘录
// 4ms 98.81%
#include<vector>
using namespace std;

typedef vector<vector<int>> vecii;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {    
        vecii memo;

        int row = triangle.size();
        int col = triangle[0].size();
        
        // 初始化备忘录
        for (int i = 0; i < row; i++)
        {
            vector<int> temp;
            for (int j = 0; j <= i; j++)
                temp.push_back(INT_MAX);
            memo.push_back(temp);
        }

        return dp(0, 0, triangle, memo);
    }

    int dp(int i, int j, vecii &triangle, vecii &memo)
    {
        if (memo[i][j] == INT_MAX)
        {
            if (i < triangle.size() - 1)
            {
                int left = dp(i + 1, j, triangle, memo);
                int right = dp(i + 1, j + 1, triangle, memo);
        
                memo[i][j] = triangle[i][j] + (left < right ? left : right);
            }
            else
                memo[i][j] = triangle[i][j];
        }
        return memo[i][j];
    }
};


// 动态规划 思路三 自底向上 节省空间的版本
// 4ms 98.81%
#include<vector>
using namespace std;

typedef vector<vector<int>> vecii;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {    
        int row = triangle.size(), col = triangle[row - 1].size();

        vector<int> res;
        for (int i = 0; i < col; i++)
            res.push_back(triangle[row - 1][i]);
       
        for (int i = row - 2; i >= 0; i--)
        {
            vector<int> temp = res;
            for (int j = 0; j <= col - (row - i); j++)
                res[j] = triangle[i][j] + (temp[j] < temp[j + 1] ? temp[j] : temp[j + 1]);
        }
        return res[0];
    }
};