class TimeMap {
public:
    unordered_map<string,vector<string>> val;
    unordered_map<string,vector<int>> time;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        val[key].push_back(value);
        time[key].push_back(timestamp);
    }
    
    string get(string key, int timestamp) {
        if(val.find(key) != val.end() ){
            int ind = upper_bound(time[key].begin(), time[key].end(), timestamp) - time[key].begin() - 1;
            if(ind>=0) return val[key][ind];
            else return "";
        }
        else return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */