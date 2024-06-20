class Solution {
public:
        bool chk(int k,int m,vector<int>& position,int n){
            int var=1,ind=0,prev=position[0];
            while(ind<n && var<m){
                ind=lower_bound(position.begin()+ind,position.end(),prev+k)-position.begin();
                if(ind<n){var++;prev=position[ind];}
            }
            return var==m;
        }
    int maxDistance(vector<int>& position, int m) {sort(position.begin(),position.end());int n=position.size();
    int low=1,high=position.back()-position[0],mid;
    while(low<=high){
        mid=(low+high)/2;
        if(chk(mid,m,position,n))low=(mid+1);else high=(mid-1);
    }
    return low-1;
    // return chk(21,m,position,n);


    }
};