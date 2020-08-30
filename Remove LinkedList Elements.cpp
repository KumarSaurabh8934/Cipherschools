class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        ListNode *temp=head,*last=NULL;
        while(temp!=NULL)
        {
            if(temp->val==val)
            {
                if(last==NULL)
                    head=temp->next;
                else
                    last->next=temp->next;
            }
            else
                last=temp;
            temp=temp->next;
        }
        return head;        
    }
};
