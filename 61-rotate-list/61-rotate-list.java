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
    
    public ListNode rotate(ListNode head)
    {
        ListNode t=head;
        ListNode p=null;
        while(t.next!=null)
        {
            p=t;
            t=t.next;
        }
        if(p!=null)
        {
             p.next=null;
        }
        t.next=head;
        return t;
        
    }
    
    public ListNode rotateRight(ListNode head, int k) {
        
        if(head==null||head.next==null)
        {
            return head;
        }
        int siz=0;
        ListNode p=head;
        while(p!=null)
        {
            p=p.next;
            siz++;
        }
        if(k>siz)
        {
            k=k%siz;
        }
        for(int i=0;i<k;i++)
        {
            head=rotate(head);
        }
        return head;
    }
}