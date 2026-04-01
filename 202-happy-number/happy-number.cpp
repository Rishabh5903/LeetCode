class Solution {
public:
    bool isHappy(int n) {
        int temp=n;
        for(int i=0;i<=100;i++){
            n=0;
            while(temp){
                n+=(temp%10) * (temp%10);
                temp/=10;
            }
            temp=n;
            if(n==1)return true;
        }
        return false;
    }
};