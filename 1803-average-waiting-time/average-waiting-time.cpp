class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double tot=0;int curr=customers[0][0];
        for(int i=0;i<customers.size();i++){
            tot+=customers[i][1];
            tot+=max(curr-customers[i][0],0);
            curr=max(customers[i][0],curr)+customers[i][1];
        }
        return tot/customers.size();
    }
};