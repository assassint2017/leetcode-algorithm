// Runtime: 20 ms, faster than 82.72% of C++ online submissions for Top K Frequent Elements.
// Memory Usage: 11.5 MB, less than 48.54% of C++ online submissions for Top K Frequent Elements.

class Solution 
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
	{
		// 构建哈希字典
		unordered_map<int, int> hashMap;
		for (int item : nums)
		{
			if (hashMap.find(item) == hashMap.end())
				hashMap.insert(pair<int, int>(item, 1));
			else
				++hashMap.at(item);
		}

		vector<pair<int, int>> vec, minHeap;
		for (auto item : hashMap) vec.push_back(item);
		for (int i = 0; i < k; ++i) minHeap.push_back(vec[i]);

		// 定义匿名函数 这里是不允许使用auto的，所以面试的时候还是要谨慎使用
		bool (*comp)(const pair<int, int>&, const pair<int, int>&) = \
		[](const pair<int, int> &item1, const pair<int, int> &item2){return item1.second > item2.second;};

		// 建立最小堆
		make_heap(minHeap.begin(), minHeap.end(), comp);

		// 遍历插入
		for (int index = k; index < vec.size(); ++index)
		{
			if (minHeap[0].second < vec[index].second)
			{
				pop_heap(minHeap.begin(), minHeap.end(), comp);
				minHeap.pop_back();

				minHeap.push_back(vec[index]);
				push_heap(minHeap.begin(), minHeap.end(), comp);
			}
		}

		// 得到最终的结果
		vector<int> res;
		for (int i = 0; i < k; ++i)
		{
			pop_heap(minHeap.begin(), minHeap.end(), comp);
			res.push_back(minHeap.back().first);
			minHeap.pop_back();
		}
		return res;
    }
};


// 优化代码
// Runtime: 20 ms, faster than 82.72% of C++ online submissions for Top K Frequent Elements.
// Memory Usage: 11.3 MB, less than 83.31% of C++ online submissions for Top K Frequent Elements.

class Solution 
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
	{
		// 构建哈希字典
		unordered_map<int, int> hashMap;
		for (int item : nums)
		{
			if (hashMap.find(item) == hashMap.end())
				hashMap.insert(pair<int, int>(item, 1));
			else
				++hashMap.at(item);
		}

		vector<pair<int, int>> minHeap;
		unordered_map<int, int>::iterator iter = hashMap.begin();
		for (int i = 0; i < k; ++i, ++iter) minHeap.push_back(*iter);

		// 定义匿名函数 这里是不允许使用auto的，所以面试的时候还是要谨慎使用
		bool (*comp)(const pair<int, int>&, const pair<int, int>&) = \
		[](const pair<int, int> &item1, const pair<int, int> &item2){return item1.second > item2.second;};

		// 建立最小堆
		make_heap(minHeap.begin(), minHeap.end(), comp);

		// 遍历插入
		for (; iter != hashMap.end(); ++iter)
		{
			if (minHeap[0].second < iter->second)
			{
				pop_heap(minHeap.begin(), minHeap.end(), comp);
				minHeap.pop_back();

				minHeap.push_back(*iter);
				push_heap(minHeap.begin(), minHeap.end(), comp);
			}
		}

		// 得到最终的结果
		vector<int> res;
		for (int i = 0; i < k; ++i)
		{
			pop_heap(minHeap.begin(), minHeap.end(), comp);
			res.push_back(minHeap.back().first);
			minHeap.pop_back();
		}
		return res;
    }
};