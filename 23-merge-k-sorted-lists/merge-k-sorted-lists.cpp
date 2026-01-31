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
    ListNode* merge2(ListNode* l1, ListNode* l2){
        if(!l1)return l2;
        if(!l2)return l1;
        if(l1->val < l2->val){
            l1->next = merge2(l1->next,l2);
            return l1;
        }
        else{
            l2->next=merge2(l1,l2->next);
            return l2;
        }
    }
    ListNode* merge(vector<ListNode*>& lists, int left, int right){
        if(left>=right)return lists[left];
        int mid = left + (right-left)/2;
        ListNode* l = merge(lists,left,mid);
        ListNode* r = merge(lists,mid+1,right);
        return merge2(l,r);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(!lists.size())return NULL;
        return merge(lists, 0, lists.size()-1);
    }
};