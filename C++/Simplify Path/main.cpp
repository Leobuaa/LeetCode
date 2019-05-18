class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string str;
        vector<string> sta;
        
        while (getline(ss, str, '/')) {
            if (str == "." || str == "") {
                continue;
            }
            if (str == "..") {
                if (!sta.empty()) {
                    sta.pop_back();
                }
                continue;
            }
            sta.push_back(str);
        }
        
        string res = "";
        for (auto dir : sta) {
            res += "/" + dir;
        }
        
        if (res == "") {
            res = "/";
        }
        return res;
    }
};