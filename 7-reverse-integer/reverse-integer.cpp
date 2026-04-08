class Solution {
public:
    int reverse(int x) {
        int MIN = (1<<31);
        int MAX = ((1LL<<31) -1);
        int ans = 0;
        while(x){
            if(ans > MAX/10 || (ans == MAX/10) && x%10 > MAX%10) return 0;
            if(ans < MIN/10 || (ans == MIN/10) && x%10 < MIN%10) return 0;
            ans = ans * 10 + x%10;
            x/=10;
        }
        return ans;
    }
};
