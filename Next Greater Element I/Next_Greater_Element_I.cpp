// Runtime: 12 ms, faster than 75.78% of C++ online submissions for Next Greater Element I.
// Memory Usage: 9.3 MB, less than 65.43% of C++ online submissions for Next Greater Element I.

class Solution 
{
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        
        unordered_map<int, int> hashMap;
        stack<int> myStack;

        for (int index = nums2.size() - 1; index >= 0 ; index--)
        {
            while (!myStack.empty() && nums2[index] >= myStack.top())
                myStack.pop();
            
            hashMap.insert(make_pair(nums2[index], myStack.empty() ? -1 : myStack.top()));
            myStack.push(nums2[index]);
        }

        vector<int> res(nums1.size());
        for (int index = 0; index < nums1.size(); index++)
            res[index] = hashMap.at(nums1[index]);

        return res;
    }
};