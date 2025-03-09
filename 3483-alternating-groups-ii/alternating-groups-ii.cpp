class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {int n=colors.size();
        int temp=0,ans=0;
        for(int i=0;i<k-1;i++){
            if(colors[i]!=colors[i+1])temp++;
        }
        if(temp==k-1)ans++;
        for(int j=0;j<n-1;j++){
            if(colors[j%n]!=colors[(j+1)%n])temp--;
            if(colors[(j+k-1)%n]!=colors[(j+k)%n])temp++;
            if(temp==k-1)ans++;
        }
        return ans;
    }
};