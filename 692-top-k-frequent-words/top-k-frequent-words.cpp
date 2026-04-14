class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> fr;
        for(string& s:words) fr[s]++;
        vector<pair<int, string>> v;
        for(auto& p:fr) v.push_back({-p.second, p.first});
        sort(v.begin(), v.end());
        vector<string> ans;
        for(int i=0;i<k;i++) ans.push_back(v[i].second);
        return ans;
    }
};