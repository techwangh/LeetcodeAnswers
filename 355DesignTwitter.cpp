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
            if(followees.find(news[i].second) != followees.end() || news[i].second == userId) {
                res.push_back(news[i].first);
                n++;
                if(n == 10) break;
            }
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        users[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        users[followerId].erase(followeeId);
        
    }

private:
    unordered_map<int, unordered_set<int>> users;
    vector<pair<int, int>> news;
};


//faster one
//ref: https://discuss.leetcode.com/topic/48253/72ms-c-solution/2
class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() : time(0) {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets[userId].emplace_back(time++, tweetId);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;

        vector<pair<Tweet*, Tweet*>> heap;
        for(auto id : followees[userId]) {      //followers' tweets
            auto& t = tweets[id];
            if(t.size() > 0) {
                heap.emplace_back(t.data(), t.data()+t.size()-1);
            }
        }
        auto& t = tweets[userId];   //self
        if(t.size() > 0) {
            heap.emplace_back(t.data(), t.data()+t.size()-1);
        }

        auto lessThan = [] (const pair<Tweet*, Tweet*>& p1, const pair<Tweet*, Tweet*>& p2) {
            return p1.second->time < p2.second->time;
        };
        make_heap(heap.begin(), heap.end(), lessThan);

        for(int i = 0; (i < n) && (!heap.empty()); ++i) {
            pop_heap(heap.begin(), heap.end(), lessThan);
            auto& hb = heap.back();
            res.push_back(hb.second->id);

            if(hb.first == hb.second) {
                heap.pop_back();
            }
            else {
                hb.second--;
                push_heap(heap.begin(), heap.end(), lessThan);
            }
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        followees[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        followees[followerId].erase(followeeId);
    }

private:
    const int n = 10;

    struct Tweet {
        int id;
        int time;
        Tweet(int time, int id) : time(time), id(id) {}
    };

    unordered_map<int, unordered_set<int>> followees;
    unordered_map<int, vector<Tweet>> tweets;

    int time;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */