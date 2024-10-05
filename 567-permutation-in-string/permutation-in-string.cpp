class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> alpha(26,0);
        for(int i=0;i<s1.size();i++){
            alpha[s1[i]-'a']++;
        }
        // pv(alpha);
        if(s2.size()<s1.size()) return false;
        int k=s1.size();
        vector<int> curr(26,0);
        for(int i=0;i<s2.size();i++){
            if(i<k-1){
                curr[s2[i]-'a']++;
            }
            else if(i==k-1){
                curr[s2[i]-'a']++;
                if(curr==alpha) return true;
            }
            else{
                curr[s2[i]-'a']++;
                curr[s2[i-k]-'a']--;
                if(curr==alpha) return true;
            }
            // pv(curr);
        }
        return false;
    }
};