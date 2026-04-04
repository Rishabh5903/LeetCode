class Solution {
public:
    priority_queue<pair<int,char>> pq;
    int ans=0;
    int leastInterval(vector<char>& tasks, int n) {
        sort(tasks.begin(), tasks.end());
        int temp=1;
        for(int i=1;i<tasks.size();i++){
            if(tasks[i]==tasks[i-1]){
                temp++;
            }
            else{
                pq.push({temp,tasks[i-1]});
                temp=1;
            }
        }
        pq.push({temp,tasks.back()});
        while(pq.size()){
            if(pq.top().first > 1){
                ans+=n+1;
            }
            else{
                ans+=min(n+1, (int)pq.size());
            }
            vector<pair<int,char>> v;
            for(int i=0;i<n+1;i++){
                if(pq.size()){
                v.push_back(pq.top());
                pq.pop();
                v.back().first--;
                }
            }
            while(v.size()){
                if(v.back().first > 0)pq.push(v.back());
                v.pop_back();
            }

        }
        return ans;
    }
};