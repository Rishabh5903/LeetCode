class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<float,vector<int>>> v;
        for(int i=0;i<arr.size();i++){
            for (int j=i+1;j<arr.size();j++){
                // float fraction = static_cast<float>(arr[i]) / arr[j];
                v.push_back({static_cast<float>(arr[i]) / arr[j],{arr[i], arr[j]}});
            }
        }sort(v.begin(),v.end());
        // return v;
        return v[k-1].second;
    }
};