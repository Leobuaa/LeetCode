class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        int len = s.length();
        for (int i = 0; i < len; i++)
        {
            switch (s[i])
            {
                case '(':
                case '{':
                case '[':
                {
                    sta.push(s[i]);
                    break;
                }
                
                case ')':
                case '}':
                case ']':
                {
                    if (sta.empty())    return false;
                    char top = sta.top();
                    sta.pop();
                    if (!(top == '(' && s[i] == ')') && !(top == '[' && s[i] == ']') && !(top == '{' && s[i] == '}'))    
                        return false;
                    break;
                }
                
                default:
                    return false;
            }
        }
        return sta.empty();
    }
};