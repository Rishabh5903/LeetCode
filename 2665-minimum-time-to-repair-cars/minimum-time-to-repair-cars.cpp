class Solution {
public:
    bool chk(vector<int>& ranks,int& cars,long long mid){
        long long temp=0;
        for(int i:ranks)temp+=sqrt(mid/i);
        return temp>=cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long l=1,r=1e15,mid;
        while(l<=r){
            mid=l+(r-l)/2;
            if(chk(ranks,cars,mid))r=mid-1;else l=mid+1;
        }
        return r+1;
    }
};