class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        vector<int> v(n + 1, 0);

        for (int i = 0; i < n; i++) {
            v[i + 1] = abs(s[i] - t[i]) + v[i];
        }

        int low = 0, high = n, mid, prevMid;
        while (low <= high) {
            mid = low + (high - low) / 2;
            bool found = false;

            for (int i = 0; i <= n - mid; i++) {
                if (v[i + mid] - v[i] <= maxCost) {
                    found = true;
                    break;
                }
            }

            if (found) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return high;
    }
};
