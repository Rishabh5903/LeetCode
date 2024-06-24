class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        vector<int> arr;int ans=0;
        for (int i=0;i<nums.size();i++){
            int var=0;int ind=lower_bound(arr.begin(),arr.end(),i)-arr.begin();
            
            if(nums[i]==1){
                if(ind<arr.size() && (arr.size()-ind)%2)var=1;
            }
            if(nums[i]==0 || var){
                
                if(ind<arr.size() && (arr.size()-ind)%2){
                    if(!var)
                    continue;
                    else{
                        if(i<=(nums.size()-k)){
                    arr.push_back(i+k-1);ans++;} else return -1;
                    }
                }
                else{
                    if(i<=(nums.size()-k)){
                    arr.push_back(i+k-1);ans++;} else return -1;
                }
            }
            // cout<<arr<<endl;
        }
        return ans;
    }
};