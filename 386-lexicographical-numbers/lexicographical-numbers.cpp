class Solution {
public:
    vector<int> lexicalOrder(int n) {
        int curr=1;
        vector<int> ans;

            while(curr%10<=9){
            while(curr<=n){
                ans.push_back(curr);
                curr*=10;
                }
                curr/=10;
            while(curr%10==9)curr/=10;
            if(curr==0)break;
            curr++;
            }
        return ans;
    }
};