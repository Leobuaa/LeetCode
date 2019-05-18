class Solution {
public:
    // My solution use stack. The code is too long and it runs 50ms. Not a good solution.
    void calculate(stack<char> & op, stack<int>& num) {
        if (!op.empty()) {
            char oper = op.top();
            op.pop();
            int num1 = num.top();
            num.pop();
            int num2 = num.top();
            num.pop();
            switch(oper) {
                case '+':
                    num.push(num1 + num2);
                    break;
                    
                case '-':
                    num.push(num2 - num1);
                    break;
                    
                case '*':
                    num.push(num1 * num2);
                    break;
                    
                case '/':
                    num.push(num2 / num1);
                    break;
            }
        }
    }

    int calculate(string s) {
        int len = (int)s.length();
        stack<char> op;
        stack<int> num;
        int i = 0;
        while (i < len || !op.empty()) {
            if (i == len) {
                calculate(op, num);
                continue;
            }
            
            if (s[i] == ' ') {
                i++;
                continue;
            }
            
            if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                if (op.empty()) {
                    op.push(s[i]);
                    i++;
                    continue;
                }
                
                if ((op.top() == '+' || op.top() == '-') && (s[i] == '*' || s[i] == '/')) {
                    op.push(s[i]);
                    i++;
                    continue;
                }
                
                if ((s[i] == '+' || s[i] == '-')) {
                    while (!op.empty()) {
                        calculate(op, num);
                    }
                }
                
                calculate(op, num);
                op.push(s[i]);
                i++;
                continue;
            }
            
            int res = s[i] - '0';
            while ((i < len - 1) && (s[i + 1] >= '0' && s[i + 1] <= '9')) {
                i++;
                res = res * 10 + s[i] - '0';
            }
            i++;
            num.push(res);
        }
        
        return num.top();
    }

    // an excellent method from discuss. It runs 22ms.
    int calculate(string s) {
        istringstream in('+' + s + '+');
        long long sum = 0, num1 = 0, num2 = 0;
        char op;
        while (in >> op) {
            if (op == '+' || op == '-') {
                sum += num1;
                in >> num1;
                num1 *= op == '+' ? 1 : -1;
            } else {
                in >> num2;
                if (op == '*') {
                    num1 *= num2;
                } else {
                    num1 /= num2;
                }
            }
        }
        
        return sum;
    } 
};