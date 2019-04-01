min heap: O(nlogk) time, O(k) space

class Solution {
    struct compare{
        bool operator() (ListNode *l, ListNode *r){
            return l->val > r->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>,compare> q;
        for(auto list:lists){
            if(list) q.push(list);
        }// 把k个list的第一个元素都放进去了
        
        if(q.empty()) return NULL;
        ListNode *res = q.top();
        q.pop();
        if(res->next) q.push(res->next);
        ListNode *tail = res;
        while(!q.empty()){
            tail->next = q.top();
            q.pop();
            tail = tail->next;
            if(tail->next) q.push(tail->next);
        }
        return res;
    }
};
