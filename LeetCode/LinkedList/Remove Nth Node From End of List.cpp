class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* h1 = head, *h2 = head;
        for(int i=0;i<n;i++) h1 = h1->next;
        if(h1 == NULL) return head->next;// !!!!!!!
        while(h1->next){
            h1 = h1->next;
            h2 = h2->next;
        }
        h2->next = h2->next->next;
        return head;                  // return head????????
    }
};
