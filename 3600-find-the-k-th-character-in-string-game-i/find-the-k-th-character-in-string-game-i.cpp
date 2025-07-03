class Solution {
public:
    char kthCharacter(int k) {
        int ans=0;
        while(k>1){
            int prev=log2(k),prev1=pow(2,prev);
            if(prev1==k)k/=2;else k-=prev1;
            ans++;}
        return 'a'+ans;
    }
};