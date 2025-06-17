class Solution {
    public long fact(long n, long mod){
        if(n==0)return 1;
        long ans=n;n--;
        while(n>1){ans=(ans*n)%mod;n--;}
        return ans;
    }
    public long expo(long a, long n, long mod){
        
        long ans=1;
        while(n>0){
            if(n%2==1){ans=(ans*a)%mod;n--;}
            else {a=(a*a)%mod;n>>=1;}
        }
        return ans;
    }
    public long nCr(long n,long r,long mod){
        long a=fact(n,mod);
        long b=(fact(r,mod)*fact(n-r,mod))%mod;
        return (a*expo(b,mod-2,mod))%mod;
    }
    public int countGoodArrays(int n, int m, int k) {
        if(k>=n)return 0;
        long ans=m;
        long mod=1000000007;
        for(long i=0;i<n-k-1;i++){
            ans=(ans*(m-1))%mod;
        }
        ans = (ans*nCr(n-1,k,mod))%mod;
        return (int)ans;
    }
}