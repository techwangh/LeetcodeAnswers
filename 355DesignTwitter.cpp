class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        news.push_back(make_pair(tweetId, userId));

    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        int n = 0;
        for(int i = news.size()-1; i >= 0; --i) {
            auto followees = users[userId];
            if(find(followees.begin(), followees.end(), news[i].second) != followees.end()) {
                res.push_back(news[i].first);
                n++;
                if(n == 10) break;
            }
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(users.find(followerId) == users.end()) {
            users[followerId].push_back(followerId);
        }
        users[followerId].push_back(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        users[followerId].erase(find(users[followerId].begin(), users[followerId].end(), followeeId));
    }

private:
    unordered_map<int, vector<int>> users;
    vector<pair<int, int>> news;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */