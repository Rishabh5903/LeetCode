class RandomizedSet {
public:
    set<int> s;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        bool ans=s.find(val)==s.end();
        s.insert(val);
        return ans;
    }
    
    bool remove(int val) {
                bool ans=s.find(val)!=s.end();
                if(ans)
        s.erase(s.find(val));return ans;
    }
    
    int getRandom() {
        return *(next(s.begin(), rand() % s.size()));
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */