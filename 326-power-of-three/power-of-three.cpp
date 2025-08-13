class Solution {
public:
    bool isPowerOfThree(int n) {
        long long curr=1;
        for(int i=0;i<30;i++){
            if(curr==n)return true;curr*=3;
        }
        return false;
    }
};