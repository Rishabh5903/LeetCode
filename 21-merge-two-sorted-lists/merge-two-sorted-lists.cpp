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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2)return list1;
        ListNode* ans = new ListNode();
        ListNode* ANS = ans;
        int curr=0;
        if(list1 && list2){
            if(list1->val <= list2-> val){curr=list1->val;list1=list1->next;}
            else {curr=list2->val;list2=list2->next;}
        }
        else if(list1){
            curr=list1->val;list1=list1->next;
        }
        else if(list2){curr=list2->val;list2=list2->next;}
        ans->val=curr;
        while(list1 || list2){
            ans->next= new ListNode();
            if(list1 && list2){
            if(list1->val <= list2-> val){curr=list1->val;list1=list1->next;}
            else {curr=list2->val;list2=list2->next;}
        }
        else if(list1){
            curr=list1->val;list1=list1->next;
        }
        else if(list2){curr=list2->val;list2=list2->next;}
        ans->next->val = curr;
        ans=ans->next;
        }
        return ANS;


    }
};