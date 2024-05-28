class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {int n=s.size();
        vector<int> v(n+1,0);
        for(int i=0;i<n;i++){
            v[i+1]=abs(s[i]-t[i])+v[i];
        }
        int low=0,high=n,mid=0,prev=-1;
        while(low<=high && prev!=mid){
           prev=mid; mid=(high+low)/2;int f=0;
            for(int i=0;i<(n+1-mid);i++){
                if((v[i+mid]-v[i]) <=maxCost){
                    f=1;break;
                }
            }
            if(f)low=(mid+1);
            else high=(mid-1);
            
        }
        return low-1;
    }
};