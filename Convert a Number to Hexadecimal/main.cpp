class Solution {
public:
    string toHex(int num) {
        if (num == 0) {
            return "0";
        }
        
        unsigned int number = (unsigned int)num;
        
        vector<string> alp = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "a", "b", "c", "d", "e", "f"};
        int mask = 15;
        string res = "";
        while (number != 0) {
            res = alp[number & mask] + res;
            number >>= 4;
        }
        
        return res;
    }
};