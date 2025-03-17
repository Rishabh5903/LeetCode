class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> fr(501,0);
        for(int i:nums)fr[i]++;
        for(int i:fr)if(i%2)return false;return true;
    }
};