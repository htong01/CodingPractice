/*
560. Subarray Sum Equals K

Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.
Input:nums = [1,1,1], k = 2
Output: 2
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
// By using hashmap, time complexity is O(n) and space complexity also O(n)
int subarraySum(vector<int>& nums, int k)
{
	if(nums.size() == 0) return 0;

	unordered_map<int, int> mp;
	mp[0]++;
	int sum = 0;
	int cnt = 0;
	for(int n:nums){
		sum += n;
		cnt += mp[sum - k];
		mp[sum]++;
	}
	return cnt;
}

int main()
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	int k = 2;
	int n = subarraySum(nums, k);
	cout << "Number of such subarray is: " << n << endl;
	return 0;
}