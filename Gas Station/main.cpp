class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size = gas.size();
        int start = 0;
        while (start < size) {
            int sum = 0, end = start;
            while ((end - start) < size) {
                sum += gas[end % size] - cost[end % size];
                if (sum < 0) {
                    break;
                } else {
                    end++;
                }
            }
            
            if ((end - start) < size) {
                start = end + 1;
            } else {
                return start;
            }
        }
        
        return -1;
    }
};