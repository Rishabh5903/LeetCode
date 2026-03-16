class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int n = properties.size();
        vector<int> maxo(n,0);
        sort(properties.begin(),properties.end());
        maxo.back() = properties.back()[1];
        vector<int> attack(n,0);
        attack.back() = properties.back()[0];

        for(int i=n-2;i>=0;i--){
            maxo[i]=max(maxo[i+1], properties[i][1]);
            attack[i] = properties[i][0];
        }
        int ans=0;
        for(int i=0;i<n-1;i++){
            int ind= upper_bound(attack.begin(),attack.end(), attack[i]) - attack.begin();
            if(ind<n){
                if(maxo[ind]>properties[i][1])ans++;
            }
        }
        return ans;

    }
};