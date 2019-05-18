/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    // DFS
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> hash;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) {
            return node;
        }
        if (hash.find(node) == hash.end()) {
            UndirectedGraphNode* cpy = new UndirectedGraphNode(node->label);
            hash[node] = cpy;
            for (auto x : node->neighbors) {
                cpy->neighbors.push_back(cloneGraph(x));
            }
        }
        return hash[node];
    }

    // BFS
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> hash;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) {
            return node;
        }
        UndirectedGraphNode* copy = new UndirectedGraphNode(node->label);
        hash[node] = copy;
        queue<UndirectedGraphNode*> que;
        que.push(node);
        while (!que.empty()) {
            UndirectedGraphNode* top = que.front();
            que.pop();
            for (auto x : top->neighbors) {
                if (hash.find(x) == hash.end()) {
                    UndirectedGraphNode* copy_tmp = new UndirectedGraphNode(x->label);
                    hash[x] = copy_tmp;
                    que.push(x);
                }
                hash[top]->neighbors.push_back(hash[x]);
            }
        }
        return copy;
    }
};