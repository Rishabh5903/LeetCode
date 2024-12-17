class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int k) {
        priority_queue<vector<double>> pq;
        for(auto i:classes){
            double temp=((i[1]-i[0])/(1.0*i[1]*(i[1]+1)));
            pq.push({temp,i[0]*1.0,i[1]*1.0});
        }
        double ans=0;
        vector<double> temp;
        while(k){
            temp=pq.top();pq.pop();
            temp[1]++;temp[2]++;
            temp[0]=((temp[2]-temp[1])/(temp[2]*(temp[2]+1)));
            pq.push(temp);
            k--;

        }
        while(pq.size()){
            temp=pq.top();pq.pop();
            ans+=temp[1]/temp[2];
        }
        ans/=classes.size();
        return ans;
    }
};