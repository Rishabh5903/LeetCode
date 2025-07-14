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
    int getDecimalValue(ListNode* head) {
        int ans=0;
        int pow=-1;
        ListNode* temp=head;
        while(temp){
            pow++;temp=temp->next;
        }
        while(head){
            ans+=(head->val)*(1<<pow);
            pow--;
            head=head->next;
        }
        return ans;
    }
};