class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;sort(nums.begin(),nums.end());
        int temp=nums[0],prev=temp;int f=0;if(nums[0]==0)f++;
        
        for(int i=1;i<nums.size();i++){
            temp^=nums[i];
            if(temp!=0 && prev!=0){ans.push_back(nums[i-1]);
            temp=nums[i];
            }prev=temp;
            if(nums[i]==0)f++;
        }
        
        if(f==1)ans.push_back(0);
        if(ans.size()<2)ans.push_back(nums.back());
        return ans;
    }
};