class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long tot=0;
        unordered_map<int,int> mp;
        for(int i:skill){tot+=i;mp[i]++;}
        long long ans=0;
        int var=tot/(skill.size()/2);
        sort(skill.begin(),skill.end());
        int f=1;
        for(int i=0;i<skill.size()/2;i++){
            if(!mp[var-skill[i]] || (2*skill[i]==var && mp[skill[i]]<2)){f=0;break;}
            else {mp[skill[i]]--;mp[var-skill[i]]--;}
            ans+=skill[i]*(var-skill[i]);
        }
        return (f) ? ans: -1;
    }
};