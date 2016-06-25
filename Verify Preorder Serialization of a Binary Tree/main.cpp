class Solution {
public:
    bool isValidSerialization(string preorder) {
        int nullCnt = 0, numCnt = 0;
        int i = 0;
        while (true) {
            if (preorder[i] == '#') {
                nullCnt++;
            } else {
                numCnt++;
            }
            
            while (i < preorder.length() && preorder[i] != ',') {
                i++;
            }
            if (i >= preorder.length()) {
                break;
            }
            i++;
            
            if (nullCnt >= numCnt + 1) {
                return false;
            }
            
        }
        
        return nullCnt == numCnt + 1;
    }
};