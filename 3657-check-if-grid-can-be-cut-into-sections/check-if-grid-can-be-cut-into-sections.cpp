class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int,int>> x,y;
        for(auto i:rectangles){
            x.push_back({i[0],1});
            x.push_back({i[2],-1});
            y.push_back({i[1],1});
            y.push_back({i[3],-1});
        }sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        int curr=0,temp=0,cnt=0;
        for(auto i:x){
            if(i.second==1)temp++;
            else{
                curr+=temp-1;temp=0;
                if(curr==0 && i!=x.back())cnt++;
            }
        }
        curr=0,temp=0;int cnt2=0;
        for(auto i:y){
            if(i.second==1)temp++;
            else{
                curr+=temp-1;temp=0;
                if(curr==0 && i!=y.back())cnt2++;
            }
        }
        return (cnt>=2 || cnt2>=2);
    }
};