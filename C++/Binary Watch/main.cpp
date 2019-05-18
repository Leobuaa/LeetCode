class Solution {
    public:
        vector<string> readBinaryWatch(int num) {
            vector<string> res;
            const int H = 12;
            const int M = 60;
            for (int i = 0; i < H; i++) {
                for (int j = 0; j < M; j++) {
                    int count = 0;
                    int hour = i, minute = j;
                    while (hour > 0) {
                        count += hour & 1;
                        hour >>= 1;
                    }

                    while (minute > 0) {
                        count += minute & 1;
                        minute >>= 1;
                    }

                    if (count == num) {
                        string temp = to_string(i) + ":" + ((j < 10) ? "0" : "") + to_string(j);
                        res.push_back(temp);
                    }
                }
            }

            return res;
        }

        // Use bitset
        vector<string> readBinaryWatch(int num) {
            vector<string> res;
            const int H = 12;
            const int M = 60;
            for (int i = 0; i < H; i++) {
                for (int j = 0; j < M; j++) {
                    bitset<4> hour(i);
                    bitset<6> minute(j);
                    if (hour.count() + minute.count() == num) {
                        string temp = to_string(i) + ":" + ((j < 10) ? "0" : "") + to_string(j);
                        res.push_back(temp);
                    }
                }
            }

            return res;
        }
};
