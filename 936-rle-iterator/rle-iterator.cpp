class RLEIterator {
public:
    vector<int> v;
    int ind=0, exhausted=0;
    RLEIterator(vector<int>& encoding) {
        v=encoding;
    }
    
    int next(int n) {
        int ans=-1;
        while(ind<v.size()-1 && n && v[ind]<=n ){
            n-=v[ind];
            v[ind]=0;
            ans = v[ind+1];
            // if(n==0)break;
            ind+=2;
            

        }
        if(ind != v.size() && n && v[ind]>=n ){
            v[ind]-=n;
            n=0;
            ans=v[ind+1];
        }

        if(n==0)return ans;
        return -1;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */