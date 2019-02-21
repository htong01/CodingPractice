/*
Two pointers:
slow goes step by step, fast goes two steps at a time
If linkedlist has a cycle, these two pointer will meet at some time
*/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) return true;
        }
        return false;
        
    }
};
