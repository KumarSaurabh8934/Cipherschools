class Solution {
    public ListNode sortList(ListNode head) {
        ListNode res=new ListNode(Integer.MIN_VALUE);
        ListNode curr=head;
        while(head!=null){
            curr=head.next;
            sort(res,head);
            head=curr;
        }
        return res.next;
    }
    
    private void sort(ListNode res,ListNode curr){
        while(res.next!=null && res.next.val<curr.val){
            res=res.next;    
        }
        curr.next=res.next;
        res.next=curr;
    }
}
