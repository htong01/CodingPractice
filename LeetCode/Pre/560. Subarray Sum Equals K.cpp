和 TwoSum 有点像，但是要求连续的且不知道是几个和，可以用hash table
sum[i]-sum[x]==k,则{x,x+1,x+2...i}就是符合条件的subarray: 叫做prefix sum

The unordered_map::count(): count the number of elements present in an unordered_map with a given key.

https://www.youtube.com/watch?v=mKXIH9GnhgU

O(n) in both time and space
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(nums.empty()) return 0;
        int cnt = 0;
        unordered_map<int, int> mp;
        mp[0]++;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            cnt += mp[sum-k];
            mp[sum] ++;
        }
        return cnt;
    }
};
