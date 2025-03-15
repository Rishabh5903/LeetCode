class Solution {
public:
bool check(vector<int>& nums,int k,int mid){
    int cnt=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]<=mid){cnt++;i++;}
        if(cnt==k)return true;
    }
    return cnt==k;
}
    int minCapability(vector<int>& nums, int k) {
        int l=1,r=*max_element(nums.begin(),nums.end()),mid;
        while(l<=r){
            mid=l+(r-l)/2;
            if(check(nums,k,mid))r=mid-1;else l=mid+1;
        }
        return r+1;
    }
};