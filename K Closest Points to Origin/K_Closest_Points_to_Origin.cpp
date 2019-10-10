// 依然是使用堆排序的思想
// Runtime: 240 ms, faster than 68.34% of C++ online submissions for K Closest Points to Origin.
// Memory Usage: 45 MB, less than 60.94% of C++ online submissions for K Closest Points to Origin.

struct cell
{
    cell (int x, int y, double d) : x(x), y(y), dis(d) {}

    int x, y;
    double dis;
};

class Solution 
{
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        vector<vector<int>> res;

        vector<cell> heap;
        for (int i = 0; i < k; ++i)
        {
            heap.push_back(cell(points[i][0], points[i][1], getdis(points[i][0], points[i][1])));
        }

        make_heap(heap.begin(), heap.end(), key);

        for (int i = k; i < points.size(); ++i)
        {
            if (heap[0].dis > getdis(points[i][0], points[i][1]))
            {
                pop_heap(heap.begin(), heap.end(), key);
                heap.pop_back();

                heap.push_back(cell(points[i][0], points[i][1], getdis(points[i][0], points[i][1])));
                push_heap(heap.begin(), heap.end(), key);
            }
        }

        for (auto item : heap)
        {
            vector<int> temp(2, 0);
            temp[0] = item.x;
            temp[1] = item.y;
            res.push_back(temp);
        }

        return res;
    }
private:
    bool(*key)(const cell&, const cell&) = [](const cell& pos1, const cell& pos2){return pos1.dis < pos2.dis; };
private:
    double getdis(int x, int y)
    {
        return (x * x) + (y * y);
    }
};