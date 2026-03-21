class Solution {
public:
    int minCostSetTime(int start, int move, int push, int target) {
        int hours=0;
        int ans=INT_MAX;
        while(target>=100){
            target-=60;hours++;
        }
        while(target>=0){
            if(hours>=100)break;
            string curr=(hours>0 ? to_string(hours) : "") +((target<10 && hours) ? "0" : "") + (to_string(target));
            int temp=push*(curr.size());
            temp+=((curr[0]-'0' == start) ? 0 : move);
            for(int i=1;i<curr.size();i++){
                temp+=move*(curr[i]!=curr[i-1]);
                
            }
            ans=min(ans,temp);
            target-=60;
            hours++;
        }
        return ans;
    }
};