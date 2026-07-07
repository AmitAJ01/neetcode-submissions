class Twitter {
public:
    int timer = 0;
    unordered_map<int, vector<pair<int,int>>> tweetmap;
    unordered_map<int, unordered_set<int>> followmap;

    struct Node{
        int time;
        int tweetId;
        int userId;
        int index;
    };

    struct Compare{
        bool operator()(const Node &a, const Node &b) const{
            return a.time < b.time;
        }
    };
    Twitter() { }
    
    void postTweet(int userId, int tweetId) {
        tweetmap[userId].push_back({timer++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        followmap[userId].insert(userId);
        
        priority_queue<Node, vector<Node>, Compare> q;

        for(auto friends: followmap[userId]){
            if(!tweetmap[friends].empty()){
                int idx = tweetmap[friends].size()-1;

                q.push({tweetmap[friends][idx].first,
                tweetmap[friends][idx].second,
                friends,
                idx-1});
            }
        }

        while(!q.empty() && ans.size()<10){
            Node curr = q.top(); q.pop();

            ans.push_back(curr.tweetId);

            if(curr.index >= 0){
                q.push({tweetmap[curr.userId][curr.index].first,
                tweetmap[curr.userId][curr.index].second,
                curr.userId,
                curr.index-1});
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followmap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followmap[followerId].erase(followeeId);
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