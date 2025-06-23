class Solution {
public:
    bool isPalindrome(const string &s) {
        int i = 0, j = s.size() - 1;
        while (i < j) if (s[i++] != s[j--]) return false;
        return true;
    }

    bool isKMirror(long long x, int k) {
        long long t = x;
        string s;
        while (t > 0) {
            s.push_back('0' + (t % k));
            t /= k;
        }
        reverse(s.begin(), s.end());
        return isPalindrome(s);
    }

    long long kMirror(int k, int n) {
        vector<long long> result;
        for (int len = 1; result.size() < n; ++len) {
            int half = (len + 1) / 2;
            long long start = pow(10, half - 1);
            long long end = pow(10, half) - 1;
            if (half == 1) start = 1;
            for (long long prefix = start; prefix <= end && result.size() < n; ++prefix) {
                long long pal = prefix;
                long long tmp = prefix / (len % 2 ? 10 : 1);
                while (tmp > 0) {
                    pal = pal * 10 + (tmp % 10);
                    tmp /= 10;
                }
                if (isKMirror(pal, k)) result.push_back(pal);
            }
        }
        long long sum = 0;
        for (int i = 0; i < n; ++i) sum += result[i];
        return sum;
    }
};
