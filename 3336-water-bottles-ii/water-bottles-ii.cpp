class Solution {
public:
    int maxBottlesDrunk(int y, int x) {
        int ans=y;
        while(y>=x){
        int k=(sqrt(1+4*(x*x-x+2*y))-1)/2;
        y-=(k*(k+1))/2-(x*(x-1))/2;
        k-=x-1;
        x+=k;
        y+=k;
        ans+=k;
        }
        return ans;
    }
};