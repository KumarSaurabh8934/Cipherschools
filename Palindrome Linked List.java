class Solution {
public boolean isPalindrome(ListNode head) {

    if (head == null)
        return true;
    
    ListNode sPtr = head;
    ListNode fPtr = head;
    ListNode pre = null;
    ListNode next = null;
    
    while (fPtr != null && fPtr.next != null) {
        fPtr = fPtr.next.next;
        next = sPtr.next;
        sPtr.next = pre;
        pre = sPtr;
        sPtr = next;
    }
    
    if (fPtr == null) {
        while (sPtr != null) {
            if (sPtr.val != pre.val)
                return false;
            pre = pre.next;
            sPtr = sPtr.next;
        }
    } else {
        next = sPtr.next;
        while (next != null) {
            if (pre.val != next.val)
                return false;
            pre = pre.next;
            next = next.next;
        }
    }
    
    return true;
    
}
}
