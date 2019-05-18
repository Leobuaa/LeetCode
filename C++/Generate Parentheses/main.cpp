class Solution {
public:
    void createRes(int push, int pop, vector<string>& res, string s)
    {
        if (push < 0 || pop < 0) {
            return;
        } 
        if (push == 0)
        {
            while (pop--)
                s += ")";
            res.push_back(s);
            return;
        }
        
        if (push == pop)
        {
            createRes(push - 1, pop, res, s + "(");
            return;
        }
        
        createRes(push - 1, pop, res, s + "(");
        createRes(push, pop - 1, res, s + ")");
    }

    vector<string> generateParenthesis(int n) {
        int push = n, pop = n;
        vector<string> res;
        createRes(n - 1, n, res, "(");
        return res;
    }
};