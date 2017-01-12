class Solution {
public:
    string validIPAddress(string IP) {
        vector<string> res = {"IPv4", "IPv6", "Neither"};
        if (IP.length() > 39 || IP.length() < 7) {
            return res[2];
        }
        
        int cnt[2] = {0};
        for (char c : IP) {
            if (c == '.') {
                cnt[0]++;
            }
            if (c == ':') {
                cnt[1]++;
            }
        }
        
        if (cnt[0] == 3 && cnt[1] == 0) {
            return isValidIPv4(IP, res);
        }
        
        if (cnt[0] == 0 && cnt[1] == 7) {
            return isValidIPv6(IP, res);
        }
        
        return res[2];
    }
    
    string isValidIPv4(string& IP, vector<string>& res) {
        string newIP = "";
        int val = -1;
        for (char& c : IP) {
            if (c == '.') {
                if (val < 0) {
                    return res[2];
                }
                newIP += (to_string(val) + '.');
                val = -1;
            } else if (isdigit(c)) {
                val = (val < 0) ? 0 : val;
                val = val * 10 + c - '0';
                if (val > 255) {
                    return res[2];
                }
            } else {
                return res[2];
            }
        }
        if (val >= 0) {
            newIP += to_string(val);
        }
        
        return (newIP.length() == IP.length()) ? res[0] : res[2];
    }
    
    string isValidIPv6(string& IP, vector<string>& res) {
        int cnt = 0;
        for (char& c : IP) {
            if (c == ':') {
                if (cnt == 0) {
                    return res[2];
                }
                cnt = 0;
            } else if (isdigit(c) || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f')) {
                cnt++;
                if (cnt > 4) {
                    return res[2];
                }
            } else {
                return res[2];
            }
        }
        
        return (cnt > 0) ? res[1] : res[2];
    }
};