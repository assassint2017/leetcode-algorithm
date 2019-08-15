// 如果使用常规操作，查询和更新两个操作一个是on的复杂度，另外一个是o1的复杂度，但是如果使用
// 区间树，就可以将两个操作都变成logn的复杂度

// Runtime: 32 ms, faster than 91.34% of C++ online submissions for Range Sum Query - Mutable.
// Memory Usage: 19.7 MB, less than 8.33% of C++ online submissions for Range Sum Query - Mutable.

struct cell
{
	cell() : start(-1), end(-1), sum(0) {}
	int start, end;
	int sum;
};

class NumArray
{
public:

	// 构建区间树
	NumArray(vector<int>& nums)
	{
		// 边界条件处理
		if (nums.size() == 0) return;

		// 计算数组的大小
		int rightPtr = nums.size() - 1, layer = 1;
		while (rightPtr)
			rightPtr /= 2, ++layer;

		// 在定义默认构造函数后，这样做之后每个新添加上的元素会按照默认构造进行初始化
		tree.resize(pow(2, layer) - 1);

        // 建立线段树
		buildSegmentTree(0, nums.size() - 1, 0, nums);
	}

	// 更新区间树中的元素 logn的时间复杂度
	void update(int i, int val)
	{
		if (tree.size() != 0)
		{
			int start = 0, end = tree.front().end;
			int index = 0;

			// dfs查找
			while (start != end)
			{
				int mid = (start + end) / 2;
				if (mid >= i)
					end = mid, index = index * 2 + 1;
				else
					start = mid + 1, index = index * 2 + 2;
			}

			int offset = val - tree[index].sum;

			// 回溯整个路径
			while (true)
			{
				tree[index].sum += offset;
				if (index == 0) break;

				if (index & 1) index = index / 2;  // 奇数节点
				else index = index / 2 - 1;  // 偶数节点                
			}
		}
	}

	// 查询函数 同样是logn的时间复杂度
	int sumRange(int start, int end)
	{
        return (tree.size() != 0 && start <= end && start >= 0) ? query(start, end, 0) : 0;
	}

private:
	vector<cell> tree;
private:
	int query(int start, int end, int index)
	{
		int mid = (tree[index].start + tree[index].end) / 2;

		if (start == tree[index].start && end == tree[index].end)
			return tree[index].sum;
		else if (end <= mid)
			return query(start, end, 2 * index + 1);
		else if (start > mid)
			return query(start, end, 2 * index + 2);
		else
			return query(start, mid, 2 * index + 1) + query(mid + 1, end, 2 * index + 2);
	}

	int buildSegmentTree(int start, int end, int index, const vector<int>& nums)
	{
		if (start == end)
		{
			tree[index].start = start;
			tree[index].end = start;
			tree[index].sum = nums[start];
		}
		else
		{
			int mid = (start + end) / 2;
			int leftSum = buildSegmentTree(start, mid, 2 * index + 1, nums);
			int rightSum = buildSegmentTree(mid + 1, end, 2 * index + 2, nums);

			tree[index].start = start;
			tree[index].end = end;
			tree[index].sum = leftSum + rightSum;
		}
		return tree[index].sum;
	}
};