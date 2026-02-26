/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverse(ListNode head, ListNode end){
        
        ListNode prev = null;
        
        while(head!=end){
            ListNode nextnode = head.next;
            head.next = prev;
            prev = head;
            head= nextnode;
            
        }
        return prev;
    }
    public ListNode reverseKGroup(ListNode head, int k) {
        if (head==null){
            return null;
        }
        ListNode curr=head;
        ListNode tail = curr;
        for (int i=0;i<k; i++){
            if (tail==null){
                return head;
            }
            tail = tail.next;
        }
        ListNode newhead = reverse(head, tail);
        head.next = reverseKGroup(tail, k);
        return newhead;

    }
}