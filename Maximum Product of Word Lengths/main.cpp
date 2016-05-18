class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> wordsBitSet(words.size(), 0);
        int size = words.size();
        for (int i = 0; i < size; i++)
        {
            int len = words[i].size();
            for (int j = 0; j < len; j++)
                wordsBitSet[i] |= (1 << (words[i][j] - 'a'));
        }
        
        int res = 0;
        
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = i + 1; j < size; j++)
                if ((wordsBitSet[i] & wordsBitSet[j]) == 0)
                    res = max(res, int(words[i].size()) * int(words[j].size()));
        }
        
        return res;
    }
    
};