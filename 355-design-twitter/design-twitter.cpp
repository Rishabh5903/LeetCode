class Twitter {
public:
    int time;
    unordered_map<int,set<int>> network;
    unordered_map<int,priority_queue<pair<int,int>>> feed;
    Twitter() {
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        time++;
        feed[userId].push({time,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        network[userId].insert(userId);
        vector<int> ans;
        vector<int> ids;
        vector<int> times;
        for(int i=0;i<10;i++){
            int tweet=-1, time=-1, id=-1;
            for(int i:network[userId]){
                if(feed[i].size() && feed[i].top().first>time){
                    time=feed[i].top().first;
                    id=i;
                    tweet=feed[i].top().second;
                    

                }
            }
            if(tweet!=-1){ans.push_back(tweet);
            ids.push_back(id);
            times.push_back(time);
            feed[id].pop();
            }
        }
        for(int i=0;i<ans.size();i++){
            feed[ids[i]].push({times[i],ans[i]});
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        network[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        network[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */