/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        
        Node h;
        HashMap<Node,Node> map=new HashMap<Node,Node>();
        h=head;
        while(h!=null)
        {
            Node newNode=new Node(h.val);
            map.put(h,newNode);
            h=h.next;
        }
        
        h=head;
        while(h!=null)
        {
            Node next=h.next;
            Node random=h.random;
            Node newNode=map.get(h);
            Node nextNewNode;
            Node randomNode;
            if(next!=null)
            {
                 nextNewNode=map.get(next); 
            }
            else
            {
                nextNewNode=null;
            }
            if(random!=null)
            {
                randomNode=map.get(random);
            }
            else
            {
                randomNode=null;
            }  
            newNode.next=nextNewNode;
            newNode.random=randomNode;
            h=h.next;
        }
        return map.get(head);
        
        
    }
}