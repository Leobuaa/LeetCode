class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size = gas.size();
        int start = 0;
        while (start < size) {
            int cnt = 0, sum = 0, end = start;
            while (cnt < size) {
                sum += gas[end % size] - cost[end % size];
                if (sum < 0) {
                    break;
                } else {
                    cnt++;
                    end++;
                }
            }
            
            if (cnt < size) {
                start = end + 1;
            } else {
                return start;
            }
        }
        
        return -1;
    }
};