O(n) space:
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> begin(n,1);
        vector<int> last(n,1);
        vector<int> res(n,1);
        for(int i=1;i<n;i++) begin[i] = begin[i-1]*nums[i-1];
        for(int i=n-2;i>=0;i++) last[i] = last[i+1]*nums[i+1];
        for(int i=0;i<n;i++) res[i] = begin[i] * last[i];
        return res;
    }
};
-------------------------------------------------------------------------------
O(1) Space:

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int begin = 1;
        int end = 1;
        vector<int> res(n,1);
        for(int i=0;i<n;i++){
            res[i] *= begin;
            res[n-1-i] *= end;
            begin *= nums[i];
            end *= nums[n-1-i];
        }
        return res;
    }
};
