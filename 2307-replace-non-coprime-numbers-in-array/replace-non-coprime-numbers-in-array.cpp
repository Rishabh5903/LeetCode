class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            while(ans.size() && gcd(ans.back(),nums[i])!=1){nums[i]=lcm(ans.back(),nums[i]);ans.pop_back();}
            ans.push_back(nums[i]);
        }
        return ans;
    }
};