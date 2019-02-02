// 直接使用拓扑排序解决问题
//Runtime: 12 ms, faster than 65.88% of C++ online submissions for Course Schedule II.
//Memory Usage: 1.4 MB, less than 63.48% of C++ online submissions for Course Schedule II.

class Solution 
{
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) 
    {
        vector<int> res;

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
                res.push_back(i);
                leftNode--;
            }
        }

        while (leftNode > 0)
        {
            // 如果没有新纳入的节点，则直接退出循环
            if (delNode.empty())
            {
                res.clear();
                return res;
            }

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
                        res.push_back(item);
                    }
                }
            }
        }
        return res;
    }
};