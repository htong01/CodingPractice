方法非常的不懂！！实现不难，但是想法太神奇了！！！背吧！！！
Find the largest index k such that nums[k] < nums[k + 1]. If no such index exists, just reverse nums and done.
Find the largest index l > k such that nums[k] < nums[l].
Swap nums[k] and nums[l].
Reverse the sub-array nums[k + 1:].


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pos, pos2;
        for(pos=n-2;pos>=0;pos--){
            if(nums[pos]<nums[pos+1]) break;
        }
        if(pos<0) reverse(nums.begin(), nums.end());
        else{
            for(pos2=n-1;pos2>pos;pos2--){
                if(nums[pos2]>nums[pos]) break;
            }
            swap(nums[pos], nums[pos2]);
            reverse(nums.begin()+pos+1, nums.end());
        }
    }
};
