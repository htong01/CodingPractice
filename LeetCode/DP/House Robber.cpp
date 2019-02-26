// 最开始的想法是只要隔一个数求和，单数列和偶数列总有一个最大，和DP没有任何关系。然后遇到了[2,1,1,2]的情况
class Solution {
public:
    int rob(vector<int>& nums) {
        int sum1 = 0, sum2 = 0;
        int n = nums.size();
        for(int i=0;i<n;i+=2){
            sum1 += nums[i];
        }
        for(int j=1;j<n;j+=2){
            sum2 += nums[j];
        }
        return max(sum1,sum2);
    }
};

//---------------------------------DP Answer----------------------------------------------------
/*
O(N) time, O(1) space
For every house k, there are two options: either to rob it (include this house: i) or not rob it (exclude this house: e).

Include this house:
i = num[k] + e (money of this house + money robbed excluding the previous house)

Exclude this house:
e = max(i, e) (max of money robbed including the previous house or money robbed excluding the previous house)
(note that i and e of the previous step, that's why we use tmp here to store the previous i when calculating e, to make O(1) space)
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int total = 0;
        int prev = 0;
        
        for(int i=0;i<nums.size();i++){
            int temp = total;
            total = prev + nums[i];
            prev = max(prev,temp);
        }
        return max(prev,total);
    }
};
