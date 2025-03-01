class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){nums[i]*=2;nums[i+1]=0;}
        }
        vector<int> ans;for(int i:nums)if(i)ans.push_back(i);
        int n=nums.size()-ans.size();
        for(int i=0;i<n;i++)ans.push_back(0);
        return ans;
    }
};