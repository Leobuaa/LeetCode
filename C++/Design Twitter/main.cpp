// The better one solution. Use prority queue.
class Twitter {
    public:
        /** Initialize your data structure here. */
        Twitter() {
            timestamp = 0;
        }

        /** Compose a new tweet. */
        void postTweet(int userId, int tweetId) {
            timestamp++;
            followRelationships[userId].insert(userId);
            postTweets[userId].push_back(make_pair(timestamp, tweetId));
        }

        /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
        vector<int> getNewsFeed(int userId) {
            vector<pair<int, int>> allTweets;

            for (auto p = followRelationships[userId].begin(); p != followRelationships[userId].end(); p++) {
                allTweets.insert(allTweets.end(), postTweets[*p].begin(), postTweets[*p].end());
            }

            priority_queue<pair<int, int>> pq(allTweets.begin(), allTweets.end());

            vector<int> res;
            while (!pq.empty()) {
                res.push_back(pq.top().second);
                pq.pop();
                if (res.size() >= 10) {
                    break;
                }
            }

            return res;
        }

        /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
        void follow(int followerId, int followeeId) {
            followRelationships[followerId].insert(followeeId); 
        }

        /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
        void unfollow(int followerId, int followeeId) {
            if (followRelationships.count(followerId) && followRelationships[followerId].count(followeeId) && (followerId != followeeId)) {
                followRelationships[followerId].erase(followeeId);
            }
        }

    private:
        map<int, vector<pair<int, int>>> postTweets;
        map<int, set<int>> followRelationships;
        int timestamp;
};

// My previous solution. It runs slowly. I did not use priority queue to get new tweets.
class Twitter {
    public:
        /** Initialize your data structure here. */
        Twitter() {

        }

        /** Compose a new tweet. */
        void postTweet(int userId, int tweetId) {
            allTweets.push_back(make_pair(userId, tweetId));
            if (postTweets.find(userId) != postTweets.end()) {
                postTweets[userId].insert(tweetId);
            } else {
                set<int> tmp;
                tmp.insert(tweetId);
                postTweets[userId] = tmp;
            }

            if (followRelationships.find(userId) != followRelationships.end()) {
                followRelationships[userId].insert(userId);
            } else {
                set<int> tmp;
                tmp.insert(userId);
                followRelationships[userId] = tmp;
            }
        }

        /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
        vector<int> getNewsFeed(int userId) {
            vector<int> res;
            for (auto pointer = allTweets.rbegin(); pointer != allTweets.rend(); pointer++) {
                set<int> followees = followRelationships[userId];
                if (followees.find((*pointer).first) != followees.end()) {
                    res.push_back((*pointer).second);
                }

                if (res.size() >= 10) {
                    break;
                }
            }

            return res;
        }

        /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
        void follow(int followerId, int followeeId) {
            if (followerId == followeeId) {
                return;
            }
            if (followRelationships.find(followerId) != followRelationships.end()) {
                followRelationships[followerId].insert(followeeId);
            } else {
                set<int> tmp;
                tmp.insert(followeeId);
                followRelationships[followerId] = tmp;
            }
        }

        /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
        void unfollow(int followerId, int followeeId) {
            if (followerId == followeeId) {
                return;
            }
            if (followRelationships.find(followerId) != followRelationships.end()) {
                auto pos = followRelationships[followerId].find(followeeId);
                if (pos != followRelationships[followerId].end()) {
                    followRelationships[followerId].erase(pos);
                }
            }
        }

    private:
        map<int, set<int>> postTweets;
        map<int, set<int>> followRelationships;
        vector<pair<int, int>> allTweets;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
