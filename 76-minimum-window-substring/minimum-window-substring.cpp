#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    string chk(int len, string& s, unordered_map<char,int>& fr){
        unordered_map<char,int> curr;
        for(int i=0;i<len;i++){
            // curr[s[i]-(isupper(s[i])? 'A' : 'a')]++;
            curr[s[i]]++;
        }
        for(int i=0;i<s.size()-len;i++){
            int f=1;
            for(auto pair:fr){
                int j = pair.first;
                if(fr[j]>curr[j]){f=0;break;}
            }
            if(f)return s.substr(i,len);
            // curr[s[i]-(isupper(s[i])? 'A' : 'a')]--;
            // curr[s[i+len]-(isupper(s[i])? 'A' : 'a')]++;
            curr[s[i]]--;
            curr[s[i+len]]++;
        }
        int f=1;
            for(auto pair:fr){
                int j = pair.first;
                if(fr[j]>curr[j]){f=0;break;}
            }
        if(f)return s.substr(s.size()-len);
        else return "";

    }
    string minWindow(string s, string t) {
        unordered_map<char,int> fr;
        for(char c:t){
            fr[c]++;
            // else fr[c-'a']++;
            }
        // vector<int> curr(26,0);
        int lo=0,hi=s.size(),mid;
        string ans="";
        while(lo<=hi){
            mid=lo+(hi-lo)/2;
            string curr=chk(mid,s,fr);
            if(curr.size()){hi=mid-1;ans=curr;}
            else lo=mid+1;
        }
        // string curr=chk(hi+1,s,fr);
        // if(curr.size()){ans=curr;}
        return ans;
    }
};
