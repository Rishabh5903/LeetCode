class Solution {
public:
void backtrack(int i, int sum, vector<int>& curr, vector<vector<int>>& ans, vector<int>& candidates, int& target){
    if(sum==target) {
        ans.push_back(curr);
        return;
    }
    if(i>=candidates.size() || sum>target) return;
    for(int j=i;j<candidates.size();j++){
        if (j > i && candidates[j] == candidates[j-1]) continue;
        curr.push_back(candidates[j]);
        // sum+=candidates[j];
        backtrack(j+1, sum+candidates[j], curr, ans, candidates, target);
        curr.pop_back();
        // sum-=candidates[j];
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        vector<vector<int>> ans;
        backtrack(0, 0, curr, ans, candidates, target);
        return ans;
    }
};