// 这道题目很显然可以使用立方的时间复杂度，常数的空间复杂度来解决
// 但是，可以使用哈希表牺牲空间来换取时间

// Runtime: 24 ms, faster than 41.41% of C++ online submissions for Max Points on a Line.
// Memory Usage: 12.6 MB, less than 24.54% of C++ online submissions for Max Points on a Line.

class Solution 
{
public:
    int maxPoints(vector<vector<int>>& points) 
    {
        // 边界条件处理
        if (points.size() <= 2) return points.size();
        
        int res = 2;
        for (int i = 0; i < points.size(); ++i)
        {
            int tempres = 0, overlap = 0;
            unordered_map<string, int> hashMap;
            
            for (int j = i; j < points.size(); ++j)
            {
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1])
                {
                    ++overlap;
                    continue;
                }
                
                string slope = getSlope(points[i], points[j]);    
                if (hashMap.find(slope) == hashMap.end())
                {
                    hashMap.insert(pair<string, int>(slope, 1));
                    tempres = max(tempres, 1);
                }
                else
                    tempres = max(tempres, ++hashMap.at(slope));
            }
            res = max(res, tempres + overlap);
        }
        return res;
    }
private:
    string getSlope(const vector<int>& point1, const vector<int>& point2)
    {
        int a = point1[1] - point2[1];
        int b = point1[0] - point2[0];
        
        // 如果两点形成了一条垂线
        if (b == 0) return to_string(point1[0]) + "*";
        
        // 如果两点之间形成了一条水平线
        if (a == 0) return "*" + to_string(point1[1]);
        
        // 两点形成一条正常的线段
        int gcd = getGcd(a, b);
        a /= gcd, b /= gcd;
        
        if ((a > 0 && b < 0 )|| (a < 0 && b < 0))
            a *= -1, b*= -1;
        return to_string(a) + '*' + to_string(b);
    }
    
    // 求取两数的最大公约数
    int getGcd(int num1, int num2)
    {
        while (num1 % num2 != 0)
        {
            int temp = num1 % num2;
            num1 = num2;
            num2 = temp;
        }
        return num2;
    }
};