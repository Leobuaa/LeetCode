class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> map;
        unordered_map<string, char> rMap;
        istringstream iss(str);
        int pos = 0, len = int (pattern.length());
        while (iss && pos < len)
        {
            string tmp;
            iss >> tmp;
            if (map.find(pattern[pos]) == map.end())
            {
                map[pattern[pos]] = tmp;
                if (rMap.find(tmp) != rMap.end())   return false;
                rMap[tmp] = pattern[pos];
            }
            else if (tmp != map[pattern[pos]])   return false;
            if (iss)    pos++;
        }
        
        if (iss)
        {
            string tmp;
            iss >> tmp;
        }
        return pos == len && !iss;
    }
};