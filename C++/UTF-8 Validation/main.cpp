class Solution {
public:
    // My solution. It runs well. But I could make it better.
    bool validUtf8(vector<int>& data) {
        int cnt = 0;
        for (int num : data) {
            if (num < 0 || num >= 248) {
                return false;
            }
            
            if (cnt == 0) {
                if (num >= 128 && num < 192) {
                    return false;
                }
            } else {
                if (num >= 192 || num < 128) {
                    return false;
                }
            }
            
            if (num < 128) {
                cnt = 0;
            } else if (num >= 128 && num < 192) {
                cnt--;
            } else {
                int mask = 32;
                cnt = 1;
                while (mask & num) {
                    mask >>= 1;
                    cnt++;
                }
            }
        }
        
        return cnt == 0;
    }

    // less code
    bool validUtf8(vector<int>& data) {
        int cnt = 0;
        for (int num : data) {
            if (num < 0 || num >= 248) {
                return false;
            }
            
            if (num >= 128 && num < 192) {
                if (cnt == 0) return false;
                cnt--;
            } else if (num >= 192){
                if (cnt > 0) return false;
                int mask = 32;
                cnt = 1;
                while (mask & num) {
                    mask >>= 1;
                    cnt++;
                }
            } else {
                if (cnt > 0) return false;
                cnt = 0;
            }
        }
        
        return cnt == 0;
    }

    // brilliant solution.
    bool validUtf8(vector<int>& data) {
        int cnt = 0;
        for (int num : data) {
            if (cnt == 0) {
                if ((num >> 5) == 0b110) cnt = 1;
                else if ((num >> 4) == 0b1110) cnt = 2;
                else if ((num >> 3) == 0b11110) cnt = 3;
                else if (num >> 7) return false;
            } else {
                if ((num >> 6) != 0b10) return false;
                cnt--;
            }
        }
        
        return cnt == 0;
    }
};