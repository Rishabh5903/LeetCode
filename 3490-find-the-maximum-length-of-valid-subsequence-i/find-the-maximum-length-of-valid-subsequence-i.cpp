class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int prev=nums[0]%2;
        int e=0;
        int o=0;
        int a=1;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(prev!=nums[i]%2){
                a++;
                prev=1-prev;
            }
            if(nums[i]%2==0){
                e++;
                // prev=0;
            }
            else{
                o++;
                // prev=1;
            }
        }
        ans=max(a,max(e,o));
        return ans;
    }
};