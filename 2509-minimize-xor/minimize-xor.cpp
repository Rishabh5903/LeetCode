class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int len=log2(num1);
        int ans=0;
        int cnt=0;
        while(num2){if(num2%2){cnt++;}num2/=2;}
        for(int i=len;i>=0;i--){
            if(cnt==0)break;
            if(num1&(1<<i)){ans+=(1<<i);cnt--;}}
        for(int i=0;i<32;i++){
            if(cnt==0)break;
            if(!(ans&(1<<i))){ans+=(1<<i);cnt--;}
        }
        return ans;
    }
};