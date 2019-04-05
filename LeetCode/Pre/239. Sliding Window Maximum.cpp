看到sliding window就想用hashmap, hashmap用来做substring problem比较合适
参考了一下答案
silding window max/min 统一解法应该是： monotonic queue problem

class Mqueue{
    deque<pair<int, int> > m_deque;
    // m_queue.first: value
    // m_queue.second: element deteled
public:
    void push(int val){
        int cnt = 0;
        while(!m_deque.empty() && m_deque.back().first < val){
            cnt += m_deque.back().second + 1;
            m_deque.pop_back();
        }
        m_deque.emplace_back(val, cnt);
    }
    int max(){
        return m_deque.front().first;
    }
    void pop(){
        if(m_deque.front().second > 0){
            m_deque.front().second--;
            return;
        }
        m_deque.pop_front();
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        Mqueue mq;
        k = min(k, (int)nums.size()); // !!!!!这里要加int
        for(int i=0;i<k-1;i++)
            mq.push(nums[i]); // push first k element
        for(int i=k-1;i<nums.size();i++){
            mq.push(nums[i]); // push new element
            res.push_back(mq.max());
            mq.pop();
        }
        return res;
    }
};
