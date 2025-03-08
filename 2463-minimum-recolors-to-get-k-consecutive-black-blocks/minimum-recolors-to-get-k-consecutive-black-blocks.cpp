class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans=0,temp=0;
        for(int i=0;i<k;i++){
            if(blocks[i]=='W')temp++;
        }ans=temp;
        for(int j=0;j<blocks.size()-k;j++){
            temp-=blocks[j]=='W';temp+=blocks[j+k]=='W';ans=min(ans,temp);
        }
        return ans;
    }
};