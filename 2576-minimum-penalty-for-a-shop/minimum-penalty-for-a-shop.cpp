class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        vector<int> left(n+1,0),right(n+1,0);
        for(int i=1;i<=n;i++){
            left[i]=left[i-1];
            if(customers[i-1]=='N')left[i]++;
        }
        for(int i=n-1;i>=0;i--){
            right[i]=right[i+1];
            if(customers[i]=='Y')right[i]++;
        }
        int mino=INT_MAX,ans=0;
        if(right[0]<=mino){
            mino=right[0];
            ans=0;
            }
        
        for(int i=0;i<n;i++){
            if(left[i]+right[i+1]<mino){
                mino=left[i]+right[i+1];
                ans=i+1;
            }
        }
        if(left.back()<mino){
            mino=left.back();
            ans=n;
        }
        return ans;
    }
};