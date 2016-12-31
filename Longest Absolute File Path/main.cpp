class Solution {
public:
    int lengthLongestPath(string input) {
        int res = 0;
        int strLen = 0, tabCnt = 0;
        bool isFile = false;
        vector<int> arr;
        for (int i = 0; i < input.size(); i++) {
            char c = input[i];
            if (c == '\n') {
                if (isFile) {
                    if (tabCnt > 0) {
                        res = max(res, strLen + arr[tabCnt - 1] + tabCnt);
                    } else {
                        res = max(res, strLen);
                    }
                } else {
                    int size = arr.size();
                    int lastOne = (size > 0) ? arr[tabCnt - 1] : 0;
                    if (tabCnt >= size) {
                        arr.push_back(lastOne + strLen);
                    } else {
                        arr[tabCnt] = lastOne + strLen;
                    }
                }
                isFile = false;
                strLen = tabCnt = 0;
                continue;
            }
            
            if (c == '\t') {
                tabCnt++;
                continue;
            }
            
            if (c == '.') {
                isFile = true;
            }
            
            strLen++;
        }
        
        if (isFile) {
            if (tabCnt > 0) {
                res = max(res, strLen + arr[tabCnt - 1] + tabCnt);
            } else {
                res = max(res, strLen);
            }
        }
        
        return res;
    }
};