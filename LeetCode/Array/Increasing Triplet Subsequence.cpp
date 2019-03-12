在判断是否有递增
难点在于三个东西，却要在O(n)时间内完成，一个循环

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX, second = INT_MAX;
        for(int p:nums){
            if(p<=first) first = p;
            else if(p<=second) second = p;
            else return true;
        }
        return false;
    }
};
判断条件是小于等于
