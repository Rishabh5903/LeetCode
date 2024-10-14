class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans=0;
        priority_queue<long long> pq;
        for (int i:nums)pq.push(i);
        while(k){
            long long temp=pq.top();pq.pop();
            ans+=temp;pq.push(ceil(temp/3.0));
            k--;

        }
        return ans;
    }
};