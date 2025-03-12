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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<ListNode*> v;
        while(head){v.push_back(head);head=head->next;}
        for(int i=0;i<v.size()/k;i++){
            for(int j=0;j<k/2;j++){
                swap(v[k*i+j],v[k*i+k-1-j]);
            }
        }
        for(int i=0;i<v.size()-1;i++){
            v[i]->next=v[i+1];
        }v.back()->next=NULL;
        return v[0];
    }
};