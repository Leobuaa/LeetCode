class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph (numCourses);
        vector<int> indegree(numCourses, 0);
        for (auto p : prerequisites) {
            graph[p.second].push_back(p.first);
            indegree[p.first]++;
        }
        vector<int> res;
        while (res.size() < numCourses) {
            bool flag = false;
            for (int i = 0; i < numCourses; i++) {
                if (indegree[i] == 0) {
                    res.push_back(i);
                    indegree[i] = -1;
                    flag = true;
                    for (int j = 0; j < graph[i].size(); j++) {
                        indegree[graph[i][j]]--;
                    }
                }
            }
            if (!flag) {
                break;
            }
        }
        if (res.size() < numCourses) {
            res.clear();
        }
        return res;
    }
};