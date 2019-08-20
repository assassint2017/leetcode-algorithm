// 基本思路就是去计算每一个马距离最近的那个加热器的距离，然后取所有距离的最大值就行了

// 第一种实现方式，暴力迭代，果不其然，超时了
//28 / 30 test cases passed.
class Solution 
{
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) 
    {
        int res = INT_MIN;
        for (int house : houses)    
        {
            int dis = INT_MAX;
            for (int heater : heaters)
            {
                dis = min(dis, abs(heater - house));
            }
            res = max(res, dis);
        }
        return res;
    }
};


// 思路二 使用排序和二分查找
// Runtime: 72 ms, faster than 95.31% of C++ online submissions for Heaters.
// Memory Usage: 11.2 MB, less than 71.43% of C++ online submissions for Heaters.

class Solution 
{
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) 
    {
        sort(heaters.begin(), heaters.end());

        int res = INT_MIN;
        for (auto house : houses)
        {
            int leftPtr = 0, rightPtr = heaters.size() - 1;
            while (leftPtr < rightPtr - 1)
            {
                int mid = (leftPtr + rightPtr) / 2;
                if (heaters[mid] >= house)
                    rightPtr = mid;
                else
                    leftPtr = mid;
            }
            res = max(res, min(abs(heaters[rightPtr] - house), abs(heaters[leftPtr] - house)));
        }
        return res;
    }
};