class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<double,vector<int>>> v;
        for(int i=0;i<arr.size();i++){
            for (int j=i+1;j<arr.size();j++){
                double fraction = static_cast<double>(arr[i]) / arr[j];
                v.emplace_back(fraction, vector<int>{arr[i], arr[j]});
            }
        }sort(v.begin(),v.end());
        // return v;
        return v[k-1].second;
    }
};