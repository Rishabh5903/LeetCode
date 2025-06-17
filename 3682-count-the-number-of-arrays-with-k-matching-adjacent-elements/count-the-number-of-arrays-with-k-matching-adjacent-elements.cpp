class Solution {
    static constexpr long long MOD = 1'000'000'007;
    
    long long fact(long long n) {
        if (n == 0) return 1;
        long long ans = n--;
        while (n > 1) {
            ans = (ans * n) % MOD;
            --n;
        }
        return ans;
    }
    
    long long expo(long long a, long long e) {
        long long ans = 1;
        while (e > 0) {
            if (e & 1) {
                ans = (ans * a) % MOD;
                --e;
            } else {
                a = (a * a) % MOD;
                e >>= 1;
            }
        }
        return ans;
    }
    
    long long nCr(long long n, long long r) {
        long long A = fact(n);
        long long B = (fact(r) * fact(n - r)) % MOD;
        return (A * expo(B, MOD - 2)) % MOD;
    }
    
public:
    int countGoodArrays(int n, int m, int k) {
        if (k >= n) return 0;
        // m * (m-1)^(n-k-1) % MOD
        long long ans = (long long)m * expo(m - 1, n - k - 1) % MOD;
        // * C(n-1, k)
        ans = ans * nCr(n - 1, k) % MOD;
        return (int)ans;
    }
};
