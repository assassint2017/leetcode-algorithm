// 解题思路是检测一个有向图中有没有环的存在
// 如果存在环，就返回false 
// 如果不存在环，就返回true
// 同样使用拓扑排序就可以解决

// Runtime: 8 ms, faster than 99.65% of C++ online submissions for Course Schedule.
// Memory Usage: 1.3 MB, less than 74.13% of C++ online submissions for Course Schedule.

class Solution 
{
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) 
    {
        // 建立入邻接表
        vector<vector<int>> inadj(numCourses);
        for (auto edge : prerequisites)
            inadj[edge.first].push_back(edge.second);

        // 初始化每一个节点的入度
        vector<int> degree(numCourses);
        for (int i = 0; i < numCourses; i++)
            degree[i] = inadj[i].size();
        
        // 建立出邻接表
        vector<vector<int>> outadj(numCourses);
        for (auto edge : prerequisites)
            outadj[edge.second].push_back(edge.first);

        queue<int> delNode;
        int leftNode = numCourses;

        // 首先纳入入度为零的节点
        for (int i = 0; i < numCourses; i++)
        {
            if (degree[i] == 0)
            {
                degree[i] = -1;
                delNode.push(i);
                leftNode--;
            }
        }

        while (leftNode > 0)
        {
            // 如果没有新纳入的节点，则直接退出循环
            if (delNode.empty())
                return false;

            // 更新剩余节点的入度
            int size = delNode.size();
            for (int i = 0; i < size; i++)
            {
                auto node = delNode.front();
                delNode.pop();
            
                for (auto item : outadj[node])
                {
                    if (--degree[item] == 0)
                    {
                        leftNode--;
                        degree[item] = -1;
                        delNode.push(item);
                    }
                }
            }
        }
        return true;
    }
};