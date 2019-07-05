// 思路一 最暴力的思路 nlogn的时间复杂度 O(1)的空间复杂度
// Runtime: 120 ms, faster than 44.38% of C++ online submissions for Squares of a Sorted Array.
// Memory Usage: 14.5 MB, less than 14.67% of C++ online submissions for Squares of a Sorted Array.

class Solution 
{
public:
    vector<int> sortedSquares(vector<int>& A) 
    {
        vector<int> res;
        for (auto item : A)
            res.push_back(item * item);
        
        sort(res.begin(), res.end(), [](const int &num1, const int &num2){return abs(num1) < abs(num2);});
        
        return res;
    }
};

// 思路二 使用两个指针用线性的时间复杂度解决问题

// Runtime: 92 ms, faster than 98.25% of C++ online submissions for Squares of a Sorted Array.
// Memory Usage: 14.5 MB, less than 22.53% of C++ online submissions for Squares of a Sorted Array.

class Solution 
{
public:
    vector<int> sortedSquares(vector<int>& A) 
    {
        int leftPtr = 0;

        while (leftPtr < A.size() && A[leftPtr] < 0)
            leftPtr++;
        
        int rightPtr = leftPtr--;

        vector<int> res;

        while (leftPtr >= 0 && rightPtr < A.size())
        {
            int left = A[leftPtr] * A[leftPtr];
            int right = A[rightPtr] * A[rightPtr];
            
            if (left <= right)
            {
                res.push_back(left);
                leftPtr--;
            }
            else
            {
                res.push_back(right);
                rightPtr++;
            }
        }

        while (leftPtr >= 0)
        {
            res.push_back(A[leftPtr] * A[leftPtr]);
            leftPtr--;
        }

        while (rightPtr < A.size())
        {
            res.push_back(A[rightPtr] * A[rightPtr]);
            rightPtr++;
        }
        
        return res;
    }
};