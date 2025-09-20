class Router {
public:
    deque<vector<int>> dq;
    unordered_map<int,deque<int>> mp;
    set<vector<int>> s;
    int sz=0;
    Router(int memoryLimit) {
        sz=memoryLimit;
    }
    
    bool addPacket(int source, int dest, int timestamp) {
        if(s.find({source,dest,timestamp})==s.end()){
            s.insert({source,dest,timestamp});
            if(dq.size()==sz){
                auto fr=dq.front();
                s.erase(fr);
                dq.pop_front();
                mp[fr[1]].pop_front();
            }
            mp[dest].push_back(timestamp);
            dq.push_back({source,dest,timestamp});
            return true;
        }
        else return false;
    }
    
    vector<int> forwardPacket() {
        if(!dq.size())return {};
                auto fr=dq.front();
                s.erase(fr);
                dq.pop_front();
                mp[fr[1]].pop_front();
                return fr;

    }
    
    int getCount(int dest, int startTime, int endTime) {
        auto start=lower_bound(mp[dest].begin(),mp[dest].end(),startTime)-mp[dest].begin() ;
        auto end = upper_bound(mp[dest].begin(),mp[dest].end(),endTime)-mp[dest].begin() ;
        return end-start;

    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */