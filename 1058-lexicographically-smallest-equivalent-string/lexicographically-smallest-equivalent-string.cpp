class Solution {
public:
    void merge(int a,int b,vector<vector<int>>& sets,vector<int>& parent){
        a=parent[a];b=parent[b];
        if(a!=b){
            if(a>b)swap(a,b);
            while(sets[b].size()){
                int temp=sets[b].back();
                sets[b].pop_back();
                sets[a].push_back(temp);
                parent[a]=min(a,temp);
                parent[temp]=a;
            }
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> parent(26);
        vector<vector<int>> sets(26);
        for(int i=0;i<26;i++){parent[i]=i;sets[i]={i};}
        for(int i=0;i<s1.size();i++)merge(s1[i]-'a',s2[i]-'a',sets,parent);
        string ans="";
        for(char c:baseStr)ans+='a'+parent[c-'a'];
        return ans;

    }
};