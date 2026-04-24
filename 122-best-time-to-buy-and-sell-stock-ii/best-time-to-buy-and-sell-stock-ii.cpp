class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        stack<int> st;
        vector<int> next(n,-1);
        st.push(0);
        for(int i=1;i<n;i++){
            while(st.size() && prices[i]>=prices[st.top()]){
                next[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        vector<int> dp(n,0);
        int ans = 0;
        for(int i=n-2;i>=0;i--){
            if(next[i] != -1) dp[i] = max(dp[i+1], prices[next[i]] - prices[i] + dp[next[i]]);
            else dp[i] = dp[i+1];
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};