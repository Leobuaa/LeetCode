class Solution {
public:
    string decodeString(string s) {
        string res = "";
        stack<int> nums;
        stack<string> strings;
        
        int num = 0;
        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + c - '0';
                continue;
            } else {
                if (num > 0) {
                    nums.push(num);
                    num = 0;
                }
                
                if (c == ']') {
                    string tmpStr = "";
                    while (!strings.empty()) {
                        if (strings.top() != "[") {
                            tmpStr = strings.top() + tmpStr;
                            strings.pop();
                        } else {
                            strings.pop();
                            break;
                        }
                    }
                    string tmpRes = "";
                    int tmpNum = 1;
                    if (!nums.empty()) {
                        tmpNum = nums.top();
                        nums.pop();
                    }
                    for (int i = 0; i < tmpNum; i++) {
                        tmpRes += tmpStr;
                    }
                    
                    strings.push(tmpRes);
                } else {
                    string tmp = "";
                    tmp += c;
                    strings.push(tmp);
                }
            }
        }
        
        while (!strings.empty()) {
            res = strings.top() + res;
            strings.pop();
        }
        
        return res;
    }


    // Recursive solution
    int pos = 0;
    string decodeString(string s) {
        return helper(s);
    }
    
    string helper(string s) {
        string res = "";
        int num = 0;
        while (pos < s.length()) {
            if (isdigit(s[pos])) {
                num = num * 10 + s[pos++] - '0';
            } 
            if (isalpha(s[pos])) {
                res += s[pos++];
            }
            if (s[pos] == ']') {
                pos++;
                return res;
            }
            if (s[pos] == '[') {
                pos++;
                string tmp = helper(s);
                if (num > 0) {
                    string tmpRes = tmp;
                    while (--num) {
                        tmpRes += tmp;
                    }
                    res += tmpRes;
                } else {
                    res += tmp;
                }
            }
        }
        
        return res;
    }
};