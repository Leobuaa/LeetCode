class MinStack {
    vector<int> sta;
    vector<int> min;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if (min.empty()) {
            min.push_back(x);
        } else if (x <= min.back()){
            min.push_back(x);
        }
        
        sta.push_back(x);
    }
    
    void pop() {
        if (top() == min.back()) {
            min.pop_back();
        }
        sta.pop_back();
    }
    
    int top() {
        return sta.back();
    }
    
    int getMin() {
        return min.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */