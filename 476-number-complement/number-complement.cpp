class Solution {
public:
    int findComplement(int num) {
        int len=log2(num);
        int ans=0;

        for(int i=0;i<=len;i++){
            if((num & (1<<i))==0)ans+=(1<<i);
        }return ans;
    }
};