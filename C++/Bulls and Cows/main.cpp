class Solution {
public:
    string getHint(string secret, string guess) {
        int len = int(secret.length());
        int a = 0, b = 0;
        vector<int> count1(10, 0), count2(10, 0);
        
        for (int i = 0; i < len; i++)
        {
            if (secret[i] == guess[i])
                a++;
            else
            {
                count1[secret[i] - '0']++;
                count2[guess[i] - '0']++;
            }
        }
        
        for (int i = 0; i < 10; i++)
            b += min(count1[i], count2[i]);
        
        return to_string(a) + "A" + to_string(b) + "B";
    }
};