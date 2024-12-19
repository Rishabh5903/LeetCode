class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {int n=arr.size();
        set<int> s1,s2;int ans=0;
        for(int i=0;i<n;i++){
            s1.insert(i);s2.insert(arr[i]);
            if(s1==s2){s1.clear();s2.clear();ans++;}
        }
        return ans;
    }
};