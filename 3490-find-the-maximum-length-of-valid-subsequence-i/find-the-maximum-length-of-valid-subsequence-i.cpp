class Solution {
public:
    int maximumLength(vector<int>& nums) {
        vector<int> v;
        // int s = (nums[0] + nums[1]) % 2;
        int ans = 0,c1=0,c2=0;
        v.push_back(nums[0]);
        if(nums[0]%2)c1++;else c2++;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i]%2 != v.back()%2) {
                v.push_back(nums[i]);
                // s=1-s;
            }
            if(nums[i]%2)c1++;else c2++;

        }
        int w = v.size();
        ans = max(ans, w);
        return max((int)v.size(),max(c1,c2));
    }
};
