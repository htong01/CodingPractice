Sort + min heap

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty()) return {};
        
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start<b.start;});
        priority_queue<int, vector<int>, greater<int> > min_heap;
        
        for(auto in:intervals){
            if(!min_heap.empty() && min_heap.top()<=in.start)
                min_heap.pop();
            min_heap.push(in.end);
        }
        return min_heap.size();
    }
};

还有个挺方便的想法：

