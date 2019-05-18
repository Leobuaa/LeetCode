class Solution {
public:
    // My solution
    bool isValid(string s) {
        // It is important. 01 is not valid.
        if (s[0] == '0' && s.length() > 1) {
            return false;
        }
        int res = 0;
        for (int i = 0; i < (int)s.length(); i++) {
            res = res * 10 + s[i] - '0';
        }
        
        return ((res >= 0) && (res <= 255));
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        int pos = (int)s.length() - 1;
        for (int i = 0; i <=2; i++) {
            for (int j = i + 1; j <= i + 3; j++) {
                for (int k = j + 1; k <= j + 3; k++) {
                    if (k >= pos || pos - k > 3) {
                        continue;
                    }
                    
                    string num1 = s.substr(0, i + 1);
                    string num2 = s.substr(i + 1, j - i);
                    string num3 = s.substr(j + 1, k - j);
                    string num4 = s.substr(k + 1, pos - k);
                    
                    if (isValid(num1) && isValid(num2) && isValid(num3) && isValid(num4)) {
                        res.push_back(num1 + '.' + num2 + '.' + num3 + '.' + num4);
                    }
                }
            }
        }
        return res;
    }

    // A better one from discuss
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        string ans;

        for (int a=1; a<=3; a++)
        for (int b=1; b<=3; b++)
        for (int c=1; c<=3; c++)
        for (int d=1; d<=3; d++)
            if (a+b+c+d == s.length()) {
                int A = stoi(s.substr(0, a));
                int B = stoi(s.substr(a, b));
                int C = stoi(s.substr(a+b, c));
                int D = stoi(s.substr(a+b+c, d));
                if (A<=255 && B<=255 && C<=255 && D<=255)
                    // The first bit of the num can not be 0.
                    if ( (ans=to_string(A)+"."+to_string(B)+"."+to_string(C)+"."+to_string(D)).length() == s.length()+3) 
                        ret.push_back(ans);
            }    

        return ret;
    }
};