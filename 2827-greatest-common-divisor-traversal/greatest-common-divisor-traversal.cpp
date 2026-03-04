class Solution {
public:
    int get(vector<int>& par, int x){
        return par[x]==x ? x : (par[x]=get(par,par[x]));
    }
    void merge(vector<int>& par,vector<int>& deg, int i, int j){
        i= get(par,i);
        j= get(par,j);
        if(i==j)return;
        if (deg[i]<deg[j])swap(i,j);
        par[j] = i;
        deg[i]+=deg[j];
    }
    bool canTraverseAllPairs(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return true;
        vector<int> par(n,0),deg(n,1);
        for(int i=0;i<n;i++)par[i]=i;
        unordered_map<int,int> have;
        for(int i=0;i<n;i++){
            int x = nums[i];
            for(int j=2;j*j<=x;j++){
                if(x%j==0){
                    if(have.count(j))
                    merge(par,deg,i,have[j]);
                    else{
                    have[j]=i;
                }
                while(x%j==0)x/=j;
                }
                
            }
            if(x>1){
                if(have.count(x)){
                    merge(par,deg,i,have[x]);
                }
                else have[x]=i;
            }
        }
        return deg[get(par,0)]==n;
        

    }
};