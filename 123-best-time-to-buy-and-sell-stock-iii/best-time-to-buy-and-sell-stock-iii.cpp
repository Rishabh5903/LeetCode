class Solution {
public:
    int maxProfit(vector<int>& prices) {int n=prices.size();
        vector<int> maxo(n),mino(n);maxo[n-1]=prices[n-1];mino[0]=prices[0];
        for(int i=n-2;i>=0;i--)maxo[i]=max(maxo[i+1],prices[i]);
        for(int i=n-1;i>=0;i--)maxo[i]=maxo[i]-prices[i];
        for(int i=n-2;i>=0;i--)maxo[i]=max(maxo[i+1],maxo[i]);
        for(int i=1;i<n;i++)mino[i]=min(mino[i-1],prices[i]);
        for(int i=0;i<n;i++)mino[i]=prices[i]-mino[i];
        for(int i=1;i<n;i++)mino[i]=max(mino[i-1],mino[i]);
        int ans=0;
        for(int i=0;i<n-1;i++){
            ans=max(ans,mino[i]+maxo[i+1]);
        }
        return max(ans,mino[n-1]);

    }
};