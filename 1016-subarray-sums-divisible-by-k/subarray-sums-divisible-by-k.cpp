class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int prev=nums[0];
        map<int,int> mp;
        mp[(prev)%k]=1;
        long long ans=0;
        int n=(int)nums.size();
        for(int i=0;i<n-1;i++){
            prev+=nums[i+1];
            int temp=(prev)%k;
            if(mp[temp]){
                mp[temp]+=1;
            }
            else
            mp[temp]=1;
        }
        
        for(int i=-pow(10,4);i<pow(10,4)+1;i++){
            if(mp[i]){
            int temp=mp[i];
            ans+=temp*(temp-1)/2;
            if(mp[i+k]){
                ans+=mp[i]*mp[i+k];
            }
            if(i==0){
                ans+=temp;
            }}
        }
        return ans;
    }
};