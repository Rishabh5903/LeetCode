class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        sort(banned.begin(),banned.end());
        int i=0;
        int j=1;
        int sum=0;
        int ans=0;
        while(sum+j<=maxSum && j<=n){
            while(i<banned.size() && banned[i]<j){i++;}
            if(i<banned.size() && banned[i]==j){j++;continue;}
            if(sum+j<=maxSum && j<=n){sum+=j;ans++;}
            j++;
        }
        return ans;

    }
};