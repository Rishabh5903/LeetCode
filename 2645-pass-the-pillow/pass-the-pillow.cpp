class Solution {
public:
    int passThePillow(int n, int time) {
        int num=time/(n-1);
        if(num%2)return n-time%(n-1);
        return 1+time%(n-1);
    }
};