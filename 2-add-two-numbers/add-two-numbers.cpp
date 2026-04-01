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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        ListNode* curr = ans;
        int carry = 0;
        while(l1 || l2){
            int temp = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            carry = temp/10;
            temp %= 10;
            curr -> val = temp;
            if(l1)l1 = l1->next;
            if(l2)l2 = l2->next;
            if(l1 || l2 || carry)
            {ListNode* next = new ListNode();
            curr->next = next;
            curr=next;}
            
            }
        if(carry)curr->val = carry;
        return ans;
    }
};