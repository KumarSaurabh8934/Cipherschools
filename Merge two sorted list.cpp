class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode *temp = NULL, *head = NULL;
         
        if(l1 == NULL){return l2;}
        if(l2 == NULL){return l1;}
        
        if(l1->val <= l2->val)
        {
            head = l1;
            temp = head;
            l1 = l1->next;
        }
        else
        {
            head = l2;
            temp = head;
            l2 = l2->next;
        }
        
        
        while(l1 && l2)
        {
            if(l1->val <= l2->val) 
            {
                head->next = l1;
                l1 = l1->next;
                head = head->next;
            }
            else
            {
                head->next = l2;
                l2 = l2->next;
                head = head->next;
            }
        }
        
        while(l1)
        {
            head->next = l1;
            l1 = l1->next;
            head = head->next;
        }
        
         while(l2)
        {
            head->next = l2;
            l2 = l2->next;
            head = head->next;
        }
        return temp;
    }
};
