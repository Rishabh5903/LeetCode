class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        priority_queue<tuple<long long,long long,long long>,vector<tuple<long long,long long,long long>>,greater<tuple<long long,long long,long long>>> pq;
        for(long long i:ranks){
            pq.push({i,i,1});
        }
        long long ans=0;
        while(cars){
            auto [x,y,z]=pq.top();pq.pop();ans=max(ans,x);pq.push({y*(z+1)*(z+1),y,z+1});
            cars--;
        }
        return ans;
    }
};