class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> ind;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2)ind.push_back(i);
        }
        int ans=0;
        // if(v.size()<k)return 0;
        int l=0;int a=1,b=1;
        for(int r=k-1;r<ind.size();r++){
            if(l>0)a=ind[l]-ind[l-1];else a=ind[l]+1;
            if(r<ind.size()-1)b=ind[r+1]-ind[r];else b=nums.size()-ind[r];
            ans+=a*b;l++;
        }return ans;
    }
};