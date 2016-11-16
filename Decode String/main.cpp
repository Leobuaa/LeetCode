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
};