class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int s1=0,s2=0,s3=0;
        // int ans=1;
        // sort()
        for(int i:bills){
            if(i==5)s1++;
            else if(i==10){
                if(s1)s1--;
                else return 0;
                s2++;
            }
            else{
                if(s1 && s2){s1--;s2--;}
                else if(s1>=3){s1-=3;}
                else return 0;s3++;
            }
        }return 1;
    }
};