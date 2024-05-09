class Solution {
public:
    string convert(string s, int n) {
        if(n==1)return s;
        vector<vector<char>> v(n);int k=0;
        for(int i=0;i<s.size();i++){
            if(i>=(k*n-k) && i<=((k+1)*n-(k+1))){
                v[i-(k*n-k)].push_back(s[i]);
            }
            else{
                v[(k+2)*n-(k+3)-i+1].push_back(s[i]);
            }
            if(i==((k+2)*n-(k+3)))k+=2;
        }
        string ans="";
        for(auto i:v){
            for(char j:i)ans+=j;
        }return ans;
    }
};