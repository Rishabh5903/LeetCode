class Solution {
public:
vector<long long> v;
    Solution(vector<int>& w) {
        long long tot=0;
        for(int i:w)tot+=i;
        for(long long i=0;i<w.size();i++){
            long long fr = (w[i] * 100 + tot -1)/tot;
            for(int j=0;j<fr;j++)v.push_back(i);
        }
    }
    
    int pickIndex() {
        int i = rand() % (v.size());
        return v[i];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */