class Solution {
public:
bool chk(vector<int>& nums, int mid, int p){
    int cnt=0;
    for(int i=0;i<nums.size()-1;i++){
        if(abs(nums[i]-nums[i+1])<=mid){cnt++;i++;}
    }
    return (cnt>=p);
}
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int low=0,hi=1e9;int mid;
        while(low<=hi){
            mid=low+(hi-low)/2;
            if(chk(nums,mid,p)){hi=mid-1;}else low=(mid+1);
        }
        return hi+1;
    }
};