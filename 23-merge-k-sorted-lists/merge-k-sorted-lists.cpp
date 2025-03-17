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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> v;
        for(auto x:lists)while(x){v.push_back(x->val);x=x->next;}
        sort(v.begin(),v.end());
        if(!v.size())return NULL;
        ListNode *ans=new ListNode();
        
        ans->val=v[0];
        ListNode* temp=ans;
        for(int i=1;i<v.size();i++){ListNode* temp1=new ListNode(v[i]);temp->next=temp1;temp=temp1;}
        return ans;
    }
};