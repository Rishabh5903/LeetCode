class Solution {
public:
    bool check(char s){
        return (s=='a' || s=='e' || s=='i' || s=='o' || s=='u');
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> v(words.size()+1,0);
        for(int i=0;i<words.size();i++){
            if(check(words[i][0]) && check(words[i].back()))v[i+1]=v[i]+1;else v[i+1]=v[i];
        }
        vector<int> ans;
        for(auto q:queries){
            ans.push_back(v[q[1]+1]-v[q[0]]);
        }
        return ans;

    }
};