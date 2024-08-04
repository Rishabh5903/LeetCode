class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> v;int MOD=1e9+7;
        for(int i=0;i<n;i++){
            
                
                int temp=0;
                for(int j=i;j<n;j++){
                    temp=(temp+nums[j])%MOD;
                    v.push_back(temp);
                }
                
            
        }sort(v.begin(),v.end());
        int ans=0;
        for(int i=left-1;i<right;i++){
            ans=(ans+v[i])%MOD;
        }
        return ans;
    }
};