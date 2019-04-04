Math: c = a % k, c = b % k, so we have a % k = b % k.
Suppose b-a=d, then we have b % k = ((a+d) % k)%k = (a%k + d%k)%k
In order to make the equation valid: a % k = (a%k + d%k)%k


 if two numbers (s1 and s2) have the same remainder , and the divisor is k , then s2-s1 must be divided by k


set:: count() check if a certain element in the set

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0, pre = 0;
        unordered_set<int> m;
        for(int i=0;i<n;i++){
            sum += nums[i];
            int mod = k==0 ? sum : sum%k;
            if(m.count(mod) ) return true;
            m.insert(pre);
            pre = mod;
        }
        return false;
    }
};

-------------DP solution-------------------------
慢的解法 暴力解
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum = nums[i];
            for(int j = i+1;j<nums.size();j++){
                sum += nums[j];
                if( sum==k || (k!=0 && sum%k == 0))
                    return true;
            }
        }
        return false;
