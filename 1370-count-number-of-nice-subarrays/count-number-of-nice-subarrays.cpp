class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> x;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % 2 != 0){
                x.push_back(i);
            }
        }
        
        if (x.size() < k) return 0; 

        int count = 0;
        int a = 1, b = 1;
        for(int j = 0; j < x.size() - k + 1; j++){
            if(j == 0){
                a = x[j] + 1;
            } else {
                a = x[j] - x[j - 1];
            }
            if(j + k == x.size()){
                b = nums.size() - x[j + k - 1];
            } else {
                b = x[j + k] - x[j + k - 1];
            }
            count += a * b;
        }
        return count;
    }
};
