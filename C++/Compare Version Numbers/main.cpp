class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream v1(version1);
        stringstream v2(version2);
        
        string num1, num2;
        bool f1 = getline(v1, num1, '.'), f2 = getline(v2, num2, '.');
        while (f1 || f2) {
            if (!f1) {
                num1 = "0";
            }
            
            if (!f2) {
                num2 = "0";
            }
            if (stoi(num1) < stoi(num2)) {
                return -1;
            } else if (stoi(num1) > stoi(num2)) {
                return 1;
            }
            
            f1 = getline(v1, num1, '.');
            f2 = getline(v2, num2, '.');
        }
        
        return 0;
    }
};