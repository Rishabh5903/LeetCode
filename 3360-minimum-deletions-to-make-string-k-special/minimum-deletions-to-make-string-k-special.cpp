class Solution {
public:
bool chk(vector<int>& fr,vector<int>& suff,int& k,int mid){
    int n=fr.size();
    int temp=0;
    for(int i=0;i<n;i++){
        if(temp>mid)return false;
        int ind=lower_bound(fr.begin(),fr.end(),fr[i]+k)-fr.begin();
        if(ind==n)return true;
        if(suff[ind]-(n-ind)*(fr[i]+k)+temp<=mid)return true;
        temp+=fr[i];
    }
    
    return false;
}
    int minimumDeletions(string word, int k) {
        vector<int> fr(26,0);
        for(char c:word)fr[c-'a']++;
        sort(fr.begin(),fr.end());
        for(int i=0;i<26;i++){
            if(fr[i]!=0){fr=vector<int>(fr.begin()+i,fr.end());break;}
        }
        int n=fr.size();
        vector<int> suff(n,0);suff[n-1]=fr[n-1];
        for(int i=n-2;i>=0;i--)suff[i]=suff[i+1]+fr[i];
        int lo=0,hi=word.size();int mid;
        while(lo<=hi){
            mid=lo+(hi-lo)/2;
            if(chk(fr,suff,k,mid))hi=mid-1;else lo=mid+1;
        }
        return hi+1;
    }
};