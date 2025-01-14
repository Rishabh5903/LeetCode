class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int> mp1,mp2;
        vector<int> ans;int curr=0;
        for(int i=0;i<A.size();i++){
            mp1[A[i]]++;mp2[B[i]]++;
            if(mp1[B[i]])curr++;if(mp2[A[i]])curr++;curr-=(A[i]==B[i]);ans.push_back(curr);
        }return ans;
    }
};