class Solution {
public:
    // My solution, it runs 32ms.
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> ind(numCourses, 0);
        for (auto p : prerequisites) {
            graph[p.second].push_back(p.first);
            ind[p.first]++;
        }

        int cnt = 0;
        while (true) {
            bool flag = false;
            for (int i = 0; i < numCourses; i++) {
                if (ind[i] == 0) {
                    ind[i] = -1;
                    cnt++;
                    flag = true;
                    for (int j = 0; j < graph[i].size(); j++) {
                        ind[graph[i][j]]--;
                    }
                }
            }
            if (!flag) {
                break;
            }
        }
        return cnt == numCourses;
    }
};