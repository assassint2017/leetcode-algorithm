// 附参考链接
// https://leetcode.com/problems/reach-a-number/discuss/112968/Short-JAVA-Solution-with-Explanation

class Solution 
{
public:
    int reachNumber(int target) 
    {
        target = target > 0 ? target : -target;
        
        int pos = 0;
        int step = 1;
        
        while (pos + step < target)
        {
            pos += step;
            ++step;
        }
        
        if (pos + step == target) return step;
        
        int dis = step - (target - pos);
        
        if ((dis & 1) == 0)
            return step;
        else if((step + 1) & 1)
            return step + 1;
        else
            return step + 2;
    }
};