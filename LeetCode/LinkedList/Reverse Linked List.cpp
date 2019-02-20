class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // ---------------iteratively------------------
        // ListNode* pre = new ListNode(0);
        // ListNode* cur = head;
        // pre->next = head;
        // while(cur && cur->next){
        //     ListNode* temp = cur->next;
        //     cur->next = temp->next;
        //     temp->next =  pre->next;
        //     pre->next = temp;
        // }
        // return pre->next;
        
        //-----------------recursively------------------
        if(head==NULL || head->next==NULL) return head;
        
        // ListNode *temp = reverseList(head->next);
        // head->next->next = head;
        // head->next = NULL;
        // return temp;
        ListNode* p = head->next;
        head->next = NULL;
        ListNode *temp = reverseList(p);
        p->next = head;
        return temp;
    }
};


// 看到一个更直观一些的想法
struct ListNode* reverseList(struct ListNode* head) {
	if(NULL==head) return head;

	struct ListNode *p=head;
	p=head->next;
	head->next=NULL;
	while(NULL!=p){
		struct ListNode *ptmp=p->next;
		p->next=head;
		head=p;
		p=ptmp;
	}
	return head;
}
