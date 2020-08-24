class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        
        ListNode p1=head,p2=head;
        int l=0;
        
        if(head==null)
            return null;
        
        while(p1!=null){
            p1=p1.next;
            l++;
        }
        
        k=k%l;
        p1=head;
        while(k>0) {
            p1=p1.next;
            k--;
        }
        
        while(p1.next!=null){
            p1=p1.next;
            p2=p2.next;
        }
        p1.next=head;
        head=p2.next;
        p2.next=null;
        return head;
        
        
    }
}
