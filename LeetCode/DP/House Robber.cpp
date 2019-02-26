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
