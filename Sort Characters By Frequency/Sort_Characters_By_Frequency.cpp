// Runtime: 16 ms, faster than 74.99% of C++ online submissions for Sort Characters By Frequency.
// Memory Usage: 10.6 MB, less than 82.35% of C++ online submissions for Sort Characters By Frequency.

struct cell
{
    cell () : chr('x'), times(0) {}
    cell (char c, int t) : chr(c), times(t) {}
    char chr;
    int times;
};

class Solution 
{
public:
    string frequencySort(string s) 
    {
        vector<cell> hashmap(128);
        for (int i = 0; i < 128; ++i)
            hashmap[i].chr = i;
            
        for (char chr : s)
            ++hashmap[chr].times;
        
        auto comp = [](const cell& item1, const cell& item2){return item1.times > item2.times;};
        sort(hashmap.begin(), hashmap.end(), comp);
        
        string res = "";
        for (auto item : hashmap)
            for (int i = 0; i < item.times; ++i)
                res += item.chr;
        
        return res;
    }
};