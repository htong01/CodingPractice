去年春天找实习时候微软给的oa里有这道题，换了个不一样的背景介绍罢了
从后往前数
Idea is to work backwards from the last index. Keep track of the smallest index that can "jump" to the last index.
Check whether the current index can jump to this smallest index.

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int last = n-1;
        for(int i = n-2;i>=0;i--){
            if(i+nums[i]>=last) last = i;
        }
        return last == 0;
    }
};
