class Solution {
public:
    int numberOfSubstrings(string s) {int n=s.size();
        vector<int> va,vb,vc;
        for(int i=0;i<n;i++){
            if(s[i]=='a')va.push_back(i);
            if(s[i]=='b')vb.push_back(i);
            if(s[i]=='c')vc.push_back(i);
        }
        int ans=0,ind1,ind2;
        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                ind1=lower_bound(vb.begin(),vb.end(),i+1)-vb.begin();if(ind1<vb.size())ind1=vb[ind1];else ind1=n;
                ind2=lower_bound(vc.begin(),vc.end(),i+1)-vc.begin();if(ind2<vc.size())ind2=vc[ind2];else ind2=n;
            }
            else if(s[i]=='b'){
                ind1=lower_bound(va.begin(),va.end(),i+1)-va.begin();if(ind1<va.size())ind1=va[ind1];else ind1=n;
                ind2=lower_bound(vc.begin(),vc.end(),i+1)-vc.begin();if(ind2<vc.size())ind2=vc[ind2];else ind2=n;
            }
            else if(s[i]=='c'){
                ind1=lower_bound(vb.begin(),vb.end(),i+1)-vb.begin();if(ind1<vb.size())ind1=vb[ind1];else ind1=n;
                ind2=lower_bound(va.begin(),va.end(),i+1)-va.begin();if(ind2<va.size())ind2=va[ind2];else ind2=n;
            }
            ans+=max(0,n-max(ind1,ind2));
            
        }
        return ans;
    }
};