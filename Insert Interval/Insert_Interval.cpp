// Runtime: 244 ms, faster than 7.56% of C++ online submissions for Insert Interval.
// Memory Usage: 11.2 MB, less than 100.00% of C++ online submissions for Insert Interval.

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution 
{
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) 
    {
        auto iter = intervals.begin();
        for (; iter != intervals.end(); iter++)
        {
            // 位于右边
            if (iter->end < newInterval.start) 
                continue;
            // 位于左边
            else if (iter->start > newInterval.end)
            {
                intervals.insert(iter, newInterval);
                return intervals;
            }
            // 存在交集
            else
            {
                newInterval.start = min(iter->start, newInterval.start);
                newInterval.end = max(iter->end, newInterval.end);
                intervals.erase(iter--);
            }
        }

        intervals.insert(intervals.end(), newInterval);
        return intervals;
    }
};

// 由于vector的随机插入删除效率比较低，因此第二种实现方法是新建一个vector，然后不断在最后进行元素的插入
// Runtime: 16 ms, faster than 100.00% of C++ online submissions for Insert Interval.
// Memory Usage: 11.1 MB, less than 100.00% of C++ online submissions for Insert Interval.

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

class Solution 
{
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) 
    {
        vector<Interval> res;
        bool insert = false;
        auto iter = intervals.begin();
        for (; iter != intervals.end(); iter++)
        {
            // 位于右边
            if (iter->end < newInterval.start) 
                res.push_back(*iter);
            // 位于左边
            else if (iter->start > newInterval.end)
            {
                insert = true;
                res.push_back(newInterval);
                res.push_back(*iter);
                break;
            }
            // 存在交集
            else
            {
                newInterval.start = min(iter->start, newInterval.start);
                newInterval.end = max(iter->end, newInterval.end);
            }
        }

        if (!insert) 
            res.push_back(newInterval);
        else
        {
            for (iter++; iter != intervals.end(); iter++)
                res.push_back(*iter);
        }
        return res;
    }
};