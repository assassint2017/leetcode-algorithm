// 贪心
// 16ms 98.84%

class Solution {
public:
    int candy(vector<int>& ratings) 
    {
        // 每个孩子至少有一颗糖
        int *numCandy = new int[ratings.size()]();
        for (int i = 0; i < ratings.size(); i++)
           numCandy[i]++;
        
        // 从左向右遍历
        for (int i = 1; i < ratings.size(); i++)
        {
            if (ratings[i] > ratings[i - 1])
                numCandy[i] = numCandy[i - 1] + 1;
        }
        
        // 从右向左遍历
        for (int i = ratings.size() - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1] && numCandy[i] <= numCandy[i + 1])
                numCandy[i] = numCandy[i + 1] + 1;
        }
        
        // 求和
        int sum = 0;
        for (int i = 0; i < ratings.size(); i++)
            sum += numCandy[i];
        
        delete[] numCandy;
        return sum;
    }
};