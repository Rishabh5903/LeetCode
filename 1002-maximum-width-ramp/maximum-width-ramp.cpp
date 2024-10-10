class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<pair<int,int>> v;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        vector<int> mino(nums.size()),maxo(nums.size());
        int temp=v[0].second;mino[0]=temp;
        for(int i=0;i<nums.size();i++){
            temp=min(temp,v[i].second);mino[i]=temp;
        }
        temp=0;
        for(int i=nums.size()-1;i>=0;i--){
            temp=max(temp,v[i].second);maxo[i]=temp;
        }
        int ans=0;
        for(int i=1;i<(v.size());i++){
            ans=max(ans,maxo[i]-mino[i]);
        }return ans;
    }
};