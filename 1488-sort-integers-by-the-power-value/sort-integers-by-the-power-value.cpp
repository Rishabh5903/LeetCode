class Solution {
public:

    int getKth(int lo, int hi, int k) {
        unordered_map<int ,int> power;
        power[1]=0;
        vector<pair<int, int>> v;
        for(int i=lo;i<=hi;i++){
            int temp=i;
            int cnt=0;
            while(power.find(temp) == power.end() && temp!=1){
                if(temp%2)temp=3*temp+1;
                else temp/=2;
                cnt++;
            }
            power[i] = cnt + power[temp];
            v.push_back({power[i], i});
        }
        sort(v.begin(), v.end());
        return v[k-1].second;
    }
};