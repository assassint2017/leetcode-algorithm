/*

附上大佬的参考代码
https://leetcode.com/problems/is-graph-bipartite/discuss/115487/Java-Clean-DFS-solution-with-Explanation

u 代表还没有被上色
r 表示红色
b 表示蓝色
*/

// 单纯使用简单的DFS的代码有点超时，还需要再优化一下
// 63 / 78 test cases passed.
class Solution 
{
public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        if (graph.size() == 0) return true;
        
        vector<char> memo(graph.size(), 'u');
        
        return safe(graph, memo, 0);
    }
private:
    bool safe(const vector<vector<int>>& graph, vector<char>& memo, int startIndex)
    {
        // 递归停止条件
        if (startIndex == graph.size()) return true;
        
        if (memo[startIndex] != 'u')
        {
            for (auto node : graph[startIndex])
            {
                if (memo[node] == memo[startIndex]) return false;
            }

            char color = memo[startIndex] == 'b' ? 'r' : 'b';
            for (auto node : graph[startIndex])
            {
                memo[node] = color;
            }
            
            return safe(graph, memo, startIndex + 1);
        }
        else
        {
            vector<char> tempmemo = memo;

            vector<char> colors = {'b', 'r'};
            for (char color : colors)
            {
                memo[startIndex] = color;

                bool bad = false;
                for (auto node : graph[startIndex])
                {
                    if (memo[node] == memo[startIndex])
                    {
                        bad = true;
                        break;
                    }
                }

                if (bad) continue;

                char tempcolor = memo[startIndex] == 'b' ? 'r' : 'b';
                for (auto node : graph[startIndex])
                {
                    memo[node] = tempcolor;
                }

                if (safe(graph, memo, startIndex + 1)) 
                    return true;
                else
                    memo = tempmemo;
            }

            memo[startIndex] = 'u';
            return false;
        }    
    }
};

// 充分理解题目意思之后的BFS改进代码
// Runtime: 44 ms, faster than 7.69% of C++ online submissions for Is Graph Bipartite?.
// Memory Usage: 11.9 MB, less than 38.46% of C++ online submissions for Is Graph Bipartite?.
class Solution 
{
public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        vector<char> memo(graph.size(), 'u');
        
        for (int index = 0; index < memo.size(); ++index)
        {
            if (memo[index] != 'u') continue;

            queue<int> q;
            int layer = 1;
            q.push(index);

            while (!q.empty())
            {
                for (int i = q.size(); i > 0; --i)
                {
                    int node = q.front();
                    memo[node] = layer % 2 == 0 ? 'r' : 'b';
                    q.pop();

                    for (auto nextNode : graph[node])
                    {
                        if (memo[node] == memo[nextNode]) return false;
                    }

                    for (auto nextNode : graph[node])
                    {
                        if (memo[nextNode] == 'u') q.push(nextNode);
                    }
                }
                ++layer;
            }    
        }
        return true;
    }
};