class Solution {
public:
    unordered_map<string,bool> memo;

    bool solve(string& bottom, string& curr, unordered_map<string,vector<char>>& mp){
        if(bottom.size()==1){
            return true;
        }

        string key = bottom + "|" + curr;
        if(memo.find(key)!=memo.end()) return memo[key];

        if(curr.size()==bottom.size()-1){
            string next="";
            return memo[key]=solve(curr,next,mp);
        }

        string base="";
        base+=bottom[curr.size()];
        base+=bottom[curr.size()+1];
        if(mp.find(base)==mp.end()) return memo[key]=false;

        for(char c:mp[base]){
            curr+=c;
            if(solve(bottom,curr,mp)){
                curr.pop_back();
                return memo[key]=true;
            }
            curr.pop_back();
        }
        return memo[key]=false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string,vector<char>> mp;
        for(string s:allowed) mp[s.substr(0,2)].push_back(s[2]);
        string curr="";
        return solve(bottom,curr,mp);
    }
};
