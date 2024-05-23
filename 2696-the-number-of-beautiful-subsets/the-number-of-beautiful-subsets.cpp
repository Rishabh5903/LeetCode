class Solution {
public:
    int dfs(int i, int k,unordered_map<int,int>& mp,vector<int>& nums){
        if(i>=nums.size())return 1;

        int yes=0;
        if(!mp[nums[i]+k] && !mp[nums[i]-k]){
            mp[nums[i]]++;
            yes=dfs(i+1,k,mp,nums);
            mp[nums[i]]--;
        }
        int no=dfs(i+1,k,mp,nums);
        return yes+no;    }
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        return dfs(0,k,mp,nums)-1;
    }
};