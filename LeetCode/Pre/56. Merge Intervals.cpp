Sort intervals: 两种写法
 
1)  static bool compare(Interval a, Interval b){
      return a.start<b.start;
  } 
  sort(intervals.begin(), intervals.end(), compare);



class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.empty()) return {};
        vector<Interval> ans;
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {return a.start<b.start;});
        
        ans.push_back(intervals[0]);
        for(int i=0;i<intervals.size();i++){
            if(ans.back().end<intervals[i].start) ans.push_back(intervals[i]);
            else
                ans.back().end = max(ans.back().end, intervals[i].end);
        }
        return ans;
    }
};
