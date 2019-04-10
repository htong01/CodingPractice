/*
621. Task Scheduler
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
Time: O(n), Space O(1)

If given a string aaabc, return string that 两个连续的char不相同(eg: abaca or acaba)
https://www.geeksforgeeks.org/rearrange-characters-string-no-two-adjacent/
767. Reorganize String
*/

// g++ -std=c++14 621.cpp -o p1


#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <map>

using namespace std;

string newString(string& tasks)
{
	string s = "";
	map<char, int> mp;
	// for(auto c:tasks) mp[c]++;
	for(int i=0;i<tasks.length();++i)
            mp[tasks[i]]++;
	priority_queue<pair<int, char> > pq;
	for(auto p:mp){
		if(p.second > (tasks.length()-1)/2) return "";
		pq.emplace(p.second, p.first);
	}
	pair<int, char> prev(0, ' ');
	while(!pq.empty()){
		pair<int, char> curr = pq.top();
		cout << curr.first << " " << curr.second << endl;
		pq.pop();
		s = curr.second + s;
		curr.first--;
		if(prev.first>0) pq.emplace(prev);
		prev = curr;
	}
	return s;
}

int leastInterval(vector<char>& tasks, int n)
{
	unordered_map<char, int> mp;
	int freq = 0;
	for(auto c:tasks){
		mp[c]++;
		freq = max(freq, mp[c]);
	}
	int temp = (freq-1) * (n+1);
	for(auto c:mp){
		if(c.second == freq) temp++;
	}
	return max(temp, (int)tasks.size());
}

int main()
{
	vector<char> tasks = {'A', 'A', 'B', 'B'};
	int n = 2;
	cout << leastInterval(tasks, n) << endl;
	string s = "aaabc";
	cout << newString(s) << endl;
	return 0;
}