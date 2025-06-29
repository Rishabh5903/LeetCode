class Solution {
public:
int expo(int k,int mod){
    long long ans=1;
    long long a=2;
    while(k){
        if(k%2){ans=(ans*a)%mod;k--;}
        else{
            a=(a*a)%mod;k/=2;
        }
    }
    return (int)ans;
}


    int numSubseq(vector<int>& nums, int target) {
        int ans=0;
        int mod=1e9+7;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            
            int ind=upper_bound(nums.begin()+i,nums.end(),target-nums[i])-nums.begin()-1;
            if(ind<i)break;
            ans=(ans+expo(ind-i,mod))%mod;
        }
        // ans+=upper_bound(nums.begin(),nums.end(),target/2)-nums.begin()-1;
        return ans;
    }
};