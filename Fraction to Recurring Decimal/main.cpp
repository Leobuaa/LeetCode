class Solution {
public:
    // Use hash table
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0 || denominator == 0) {
            return "0";
        }
        
        unordered_map<int, int> mapRemain;
        string res = "";
        long long numAbs = abs((long long)numerator), denAbs = abs((long long)denominator);
        if (numAbs < denAbs) {
            res += "0.";
        } else {
            if (numAbs % denAbs != 0) {
                res += to_string(numAbs / denAbs) + ".";
            } else {
                res += to_string(numAbs / denAbs);
            }
        }
        
        long long r = numAbs % denAbs, num = r * 10;
        int cnt = 1;
        while (num > 0) {
            if (mapRemain.find(r) != mapRemain.end()) {
                break;
            }
            mapRemain[r] = cnt++;
            res += to_string(num / denAbs);
            r = num % denAbs;
            num = r * 10;
        }
        
        if (r != 0) {
            int pos = res.find_first_of(".") + mapRemain[r];
            res.insert(pos, "(");
            res += ")";
        }
        
        if ((numerator > 0 && denominator < 0) || (numerator < 0 && denominator > 0)) {
            res = "-" + res;
        }
        
        return res;
    }
};