class Solution {
public:
bool chk(long long mid, vector<int>& nums1, vector<int>& nums2, long long k){
    long long cnt=0;
    for(int i:nums1){
        if(i==0){
            if(mid>=0)cnt+=nums2.size();
            continue;
        }
        long long target = mid/i;
        if((mid%i !=0) && mid<0)if(i<0)target++;else target--;
        long long ind;
        if(i<0){ind=lower_bound(nums2.begin(),nums2.end(),target)-nums2.begin();cnt+=nums2.size()-ind;}
        else if(i>0){ind=upper_bound(nums2.begin(),nums2.end(),target)-nums2.begin();cnt+=ind;}
    }
    return cnt>=k;
}
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long lo=-1e10,hi=1e10;long long mid;
        if(nums1.size()>nums2.size())swap(nums1,nums2);
        while(lo<=hi){
            mid=lo+(hi-lo)/2;
            if(chk(mid,nums1,nums2,k))hi=mid-1;else lo=mid+1;
        }
        return hi+1;
    }
};