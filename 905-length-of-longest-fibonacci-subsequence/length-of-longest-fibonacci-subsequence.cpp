class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {int n=arr.size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int temp=2;int a=arr[i],b=arr[j],ind=j;
                while(ind<n){
                    ind=lower_bound(arr.begin()+ind,arr.end(),a+b)-arr.begin();
                    if(ind>=n || arr[ind]!=a+b)break;
                    temp++;a=b;b=arr[ind];
                }
                ans=max(ans,temp);
            }
        }
        return (ans>=3 ? ans:0);
    }
};