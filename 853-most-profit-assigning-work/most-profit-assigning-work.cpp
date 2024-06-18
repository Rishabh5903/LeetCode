class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int i=difficulty.size()-1,j=worker.size()-1;
        vector<pair<int,int>> v;
        for(int k=0;k<difficulty.size();k++){
            v.push_back({profit[k],difficulty[k]});
        }sort(v.begin(),v.end());sort(worker.begin(),worker.end());int ans=0;
        while(i>=0 && j>=0){
            while(j>=0 && v[i].second<=worker[j]){ans+=v[i].first;j--;}
            i--;
        }return ans;

    }
};