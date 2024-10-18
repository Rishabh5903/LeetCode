class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size(), m=pow(2,n);
        int temp=0;
        int orr=0,ans=0;
        for(int i:nums)orr|=i;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i & (1<<j))temp|=nums[j];
            }
            if(temp==orr)ans++;
            temp=0;
        }
        return ans;
    }
};