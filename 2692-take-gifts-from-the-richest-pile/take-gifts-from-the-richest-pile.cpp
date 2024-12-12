class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        long long ans=0;
        for(int i:gifts){pq.push(i);ans+=i;}
        
        while(k){
            int temp=pq.top();pq.pop();
            ans-=temp-floor(sqrt(temp));
            pq.push(floor(sqrt(temp)));
            k--;
        }
        return ans;
    }
};