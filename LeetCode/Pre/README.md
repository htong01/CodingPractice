
[Substring problem template:](https://leetcode.com/problems/minimum-window-substring/discuss/26808/Here-is-a-10-line-template-that-can-solve-most-'substring'-problems)
```
int findSubstring(string s){
        vector<int> map(128,0);
        int counter; // check whether the substring is valid
        int begin=0, end=0; //two pointers, one point to tail and one  head
        int d; //the length of substring

        for() { /* initialize the hash map here */ }

        while(end<s.size()){

            if(map[s[end++]]-- ?){  /* modify counter here */ }

            while(/* counter condition */){ 
                 
                 /* update d here if finding minimum*/

                //increase begin to make it invalid/valid again
                
                if(map[s[begin++]]++ ?){ /*modify counter here*/ }
            }  

            /* update d here if finding maximum*/
        }
        return d;
  }
```

Sliding Window Max/Min: [monotonic queue ](https://leetcode.com/problems/sliding-window-maximum/discuss/65885/This-is-a-typical-monotonic-queue-problem)

```
struct compare{
bool operator() (ListNode *l, ListNode *r){
    return l->val > r->val;
}
};

priority_queue<ListNode*, vector<ListNode*>,compare> q;
```

```
 static bool comp (Interval a, Interval b){
 		return a.start < b.start;
 }
 sort(intervals.begin(), intervals.end(), comp);
    priority_queue<int, vector<int>, greater<int> > min_heap;
 ```
