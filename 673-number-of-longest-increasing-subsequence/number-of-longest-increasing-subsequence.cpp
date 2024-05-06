#include <vector>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        vector<int> dp1(nums.size(), 1), dp2(nums.size(), 1);
        int count = 0, maxval = 1;
        
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if ((dp1[j] + 1) > dp1[i]) {
                        dp1[i] = dp1[j] + 1;
                        dp2[i] = dp2[j];
                    } else if ((dp1[j] + 1) == dp1[i]) {
                        dp2[i] += dp2[j];
                    }
                }
            }
            if (dp1[i] > maxval) {
                maxval = dp1[i];
                count = dp2[i]; // Reset count to the count of the new LIS length
            } else if (dp1[i] == maxval) {
                count += dp2[i];
            }
        }
        return count;
    }
};
