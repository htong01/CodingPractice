python的sort写法不同，而且没有res.back()函数，因此自己加了个
class Solution:
    def merge(self, intervals: List[Interval]) -> List[Interval]:
        if not intervals:
            return []
        intervals.sort(key=lambda x:x.start)
        res = []
        back = intervals[0]
        res.append(back)
        for i in range(1, len(intervals)):
            if back.end < intervals[i].start:
                res.append(intervals[i])
                back = intervals[i]
            else:
                back.end = max(back.end, intervals[i].end)
                back.start = min(back.start, intervals[i].start)
        return res
