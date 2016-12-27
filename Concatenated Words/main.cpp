class Solution {
public:
    // AC. It runs 785ms. 43 test cases. DP solution.
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> s(words.begin(), words.end());
        vector<string> res;
        
        for (auto word : words) {
            int n = word.size();
            vector<int> dp(n + 1);
            dp[0] = 1;
            for (int i = 0; i < n; i++) {
                if (dp[i] == 0) {
                    continue;
                }
                for (int j = i + 1; j <= n; j++) {
                    if (j - i < n && s.count(word.substr(i, j - i))) {
                        dp[j] = 1;
                    }
                }
                if (dp[n]) {
                    res.push_back(word);
                    break;
                }
            }
        }
        
        return res;
    }

    // MEL. But 43 test cases passed. 
    struct TreeNode {
        char c;
        bool end;
        TreeNode *nexts[26];
        TreeNode(char c) {
            this->c = c;
            this->end = false;
            for (int i = 0; i < 26; i++) {
                this->nexts[i] = NULL;
            }
        }
    };

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> res;

        TreeNode *root = new TreeNode(0);
        build(root, words);
        for (auto word : words) {
            TreeNode *cur = root;
            for (int i = 0; i < (int)word.size() - 1; i++) {
                cur = cur->nexts[word[i] - 'a'];
                if (cur->end) {
                    if (helper(root, word.substr(i + 1))) {
                        res.push_back(word);
                        break;
                    }
                }
            }
        }
        return res;
    }
    
    bool helper(TreeNode *root, string word) {
        if (word.size() == 0) {
            return true;
        }
        
        TreeNode *cur = root;
        int i = 0;
        while (i < word.size()) {
            if (cur->end) {
                if (helper(root, word.substr(i))) {
                    return true;
                }
            }
            if (cur->nexts[word[i] - 'a']) {
                cur = cur->nexts[word[i] - 'a'];
                i++;
            } else {
                return false;
            }
        }
        
        return cur->end;
    }
    
    void build(TreeNode *root, vector<string>& words) {
        TreeNode *cur;
        for (auto word : words) {
            cur = root;
            for (int i = 0; i < word.size(); i++) {
                if (!cur->nexts[word[i] - 'a']) {
                    cur->nexts[word[i] - 'a'] = new TreeNode(word[i]);
                }
                cur = cur->nexts[word[i] - 'a'];
            }
            cur->end = true;
        }
    }

    // It runs 400+ms. Recursive. The idea is the same as DP.
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> dict(words.begin(), words.end());
        vector<string> res;
        
        for (auto &s : words) {
            if (s.length() == 0) continue;
            if (isConcatednated(s, 0, dict, true))
                res.push_back(s);
        }
        
        return res;
    }
    
    bool isConcatednated(string& s, int st, unordered_set<string>& dict, bool first) {
        if (st == s.length())   return true;
        int end = first ? (s.length() - 1) : s.length();
        for (int i = st; i < end; i++) {
            string tmp = s.substr(st, i - st + 1);
            if (dict.count(tmp) == 0) continue;
            if (isConcatednated(s, i + 1, dict, false)) return true;
        }
        return false;
    }
};