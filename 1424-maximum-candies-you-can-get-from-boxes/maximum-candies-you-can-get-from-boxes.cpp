class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n=status.size();
        vector<int> vis(n,0);
        queue<int> q;set<int> key,s;
        for (int i:initialBoxes){q.push(i);s.insert(i);}
        int ans=0;
        while(q.size()){
            int curr=q.front();
            if((key.find(curr)!=key.end()) || (status[curr]) ){
                ans+=candies[curr];q.pop();
                for(int i:keys[curr])key.insert(i);
                for(int i:containedBoxes[curr])if(s.find(i)==s.end()){q.push(i);s.insert(i);}
                // open[curr]=1;
                // s.erase(curr);
            }
            else if(vis[curr]==1){q.pop();}
            else {
                q.pop();q.push(curr);
                vis[curr]+=1;}
        }
        return ans;
    }
};