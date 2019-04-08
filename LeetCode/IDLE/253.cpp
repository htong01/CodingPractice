/*
253. Meeting Rooms II
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.
Input: [[0, 30],[5, 10],[15, 20]]
Output: 2
Input: [[7,10],[2,4]]
Output: 1
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };
 
 static bool comp (Interval a, Interval b){
 		return a.start < b.start;
 }

int minMeetingRooms(vector<Interval>& intervals) {
	if(intervals.empty() ) return 0;
    sort(intervals.begin(), intervals.end(), comp);
    priority_queue<int, vector<int>, greater<int> > min_heap;
    for(int i=0;i<intervals.size();i++){
    	if(!min_heap.empty() && min_heap.top() <= intervals[i].start)
    		min_heap.pop();
    	min_heap.push(intervals[i].end);
    }
    return min_heap.size();
}

int main()
{
	vector<Interval> in;
	Interval a(7, 10);
	Interval b(2, 4);
	in.push_back(a);
	in.push_back(b);
	cout << "Min number for meeting rooms is: " << minMeetingRooms(in) << endl;
	return 0;
}