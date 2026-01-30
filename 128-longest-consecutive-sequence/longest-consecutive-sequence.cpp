class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> fr;
        for(int i:nums)fr[i]=1;
        int ans=0,curr=0;
        for(auto p:fr){
            int i=p.first;
            curr=0;
            int j=i-1;
            while(fr.find(i)!=fr.end() && fr[i]){
                curr++;
                fr[i]=0;
                i++;
            }
            while(fr.find(j)!=fr.end() && fr[j]){
                curr++;
                fr[j]=0;
                j--;
            }
            ans=max(ans,curr);
            
        }
        return ans;
    }
};