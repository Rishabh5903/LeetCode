class Solution {
public:
    int reverse(int x) {
        if(x==0)return 0;
        int neg = (x<0?1:0);
        // if(neg) x*=-1;
        int xx=x;
        int len = 0;
        while(xx){
            len+=1;
            xx/=10;
        }
        len--;
        int ans=0;
        while(x){
            if(!((ans+ (x%10) * pow(10,len) >= -(1LL<<31)) && (ans <= ((1LL<<31) -1 - (x%10) * (pow(10,len))))))return 0;
            ans+= (x%10) * (pow(10,len));
            len--; x/=10;
        }
        // if(neg) ans*=-1;
        return (((ans >= -(1LL<<31)) && (ans<= ((1LL<<31) -1))) ? ans : 0);
    }
};