// 第一种思路是使用哈希表，每产生一个序列就插入到哈希表中
// Runtime: 60 ms, faster than 35.43% of C++ online submissions for Letter Tile Possibilities.
// Memory Usage: 17.3 MB, less than 100.00% of C++ online submissions for Letter Tile Possibilities.

typedef unordered_set<string> hashSet;

class Solution 
{
public:
    int numTilePossibilities(string tiles) 
    {
        unordered_set<string> hashset;
        vector<bool> visited(tiles.length(), false);
        string str = "";
        
        genSequence(tiles, visited, hashset, str);
        return hashset.size();
    }
private:
    void genSequence(const string& input, vector<bool>& visited, hashSet& hashset, string& str)
    {
        for (int i = 0; i < input.length(); ++i)
        {
            if (visited[i] == false)
            {
                str += input[i];
                visited[i] = true;
                
                if (hashset.find(str) == hashset.end())
                    hashset.insert(str);
                
                genSequence(input, visited, hashset, str);
                
                str.pop_back();
                visited[i] = false;
            }
        }
    }
};