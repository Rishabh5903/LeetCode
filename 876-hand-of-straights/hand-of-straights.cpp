class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int,int> mp;int ans=1;
        for(int i:hand)mp[i]++;
        vector<int> v;for(auto i:mp)v.push_back(i.first);sort(v.begin(),v.end());
        for(int i:v){if(!ans)break;
            if(mp[i]){int temp=mp[i];
                for(int j=i;j<(i+groupSize);j++){
                    if(mp[j]<temp){ans=0;break;}
                    mp[j]-=temp;
                }
            }
        }return ans;
    }
};