/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
vector<int> ind;int prev=-1;int i=0;
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        while(head){
            if(prev!=-1 && head->next){
                if((head->val>head->next->val && head->val>prev) || 
                (head->val<head->next->val && head->val<prev) )ind.push_back(i);
            }
            prev=head->val;
            head=head->next;i++;
        }
        if(ind.size()<2)return {-1,-1};
        else {
            int mino=INT_MAX;
            for(int j=1;j<ind.size();j++)mino=min(mino,ind[j]-ind[j-1]);
            return {mino,ind.back()-ind[0]};
        }return {};
    }
};