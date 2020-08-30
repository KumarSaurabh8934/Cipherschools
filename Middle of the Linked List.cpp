  ListNode* middleNode(ListNode* head) {
    vector<ListNode*> v;
    ListNode* r=head;
    while(r!=NULL)
    {
        v.push_back(r);
        r=r->next;
    }
    int n=v.size();
    if(n%2==0)
        return v[(n/2)];
    else
        return v[(n-1)/2];
}
