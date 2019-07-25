// 这道题目和下边的这道很相关，但是在插入最小堆的时候，原则不太一样，主要还是因为输出的结果多加了一个条件排序
// 347	Top K Frequent Elements

// Runtime: 16 ms, faster than 85.32% of C++ online submissions for Top K Frequent Words.
// Memory Usage: 11.3 MB, less than 84.51% of C++ online submissions for Top K Frequent Words.

bool comp(const pair<string, int>& item1, const pair<string, int>& item2)
{
    if (item1.second == item2.second)
        return item1.first < item2.first;
    else
        return item1.second > item2.second;
}

class Solution 
{
public:
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        // 建立哈希字典
        unordered_map<string, int> hashMap;
        for (string str : words)
        {
            if (hashMap.find(str) == hashMap.end())
                hashMap.insert(pair<string, int>(str, 1));
            else
                ++hashMap.at(str);
        }

        vector<pair<string, int>> minHeap;
        unordered_map<string, int>::iterator iter = hashMap.begin();
        for (int i = 0; i < k; ++i, ++iter) minHeap.push_back(*iter);

        // 建立最小堆
        make_heap(minHeap.begin(), minHeap.end(), comp);

        // 迭代插入
        for (; iter != hashMap.end(); ++iter)
        {
            if (minHeap[0].second < iter->second || 
            (minHeap[0].second == iter->second && iter->first < minHeap[0].first))
            {
                pop_heap(minHeap.begin(), minHeap.end(), comp);
                minHeap.pop_back();

                minHeap.push_back(*iter);
                push_heap(minHeap.begin(), minHeap.end(), comp);
            }
        }

        vector<string> res;
        for (int i = 0; i < k; ++i)
        {
            pop_heap(minHeap.begin(), minHeap.end(), comp);
            res.push_back(minHeap.back().first);
            minHeap.pop_back();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};