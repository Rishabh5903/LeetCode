class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int> v;
        for(int i:arr){v[i]++;}
        for(int i:arr)if((v[2*i] && i!=0) || (i==0 && v[0]>=2))return true;
        return false;
    }
};