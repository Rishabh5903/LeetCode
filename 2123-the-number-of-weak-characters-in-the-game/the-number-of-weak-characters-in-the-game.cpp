class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int maxAttack = 0, n = properties.size(), ans = 0;
        for(int i = 0 ; i < n ; i++){
            maxAttack = max(maxAttack, properties[i][0]);
        }

        vector<int> maxDefense(maxAttack+2, 0);

        for(int i = 0 ; i < n ; i++){
            maxDefense[properties[i][0]] = max(maxDefense[properties[i][0]], properties[i][1]);
        }

        for(int i = maxDefense.size()-2 ; i >= 0 ; i--){
            maxDefense[i] = max(maxDefense[i], maxDefense[i+1]);
        }

        for(int i = 0 ; i < n ; i++){
            if(maxDefense[properties[i][0]+1] > properties[i][1]){
                ans++;
            }
        }

        return ans;
    }
};