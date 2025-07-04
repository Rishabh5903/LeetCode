class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int ans=0;
        while(k>1){
            int i=ceil(log2(k))-1;
            ans+=operations[i];
            k-=pow(2,i);
        }
        return 'a'+ans%26;
    }
};