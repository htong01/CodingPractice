function传递的参数记得加地址&
以及不理解recursion

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > ans;
        int i = 0;
        vector<int> sub;
        subset(nums, i, sub, ans);
        return ans;

    }
private:
    void subset(vector<int>& nums, int i, vector<int>& sub, vector<vector<int> >& ans){
        ans.push_back(sub);
        for(int j=i;j<nums.size();j++){
            sub.push_back(nums[j]);
            subset(nums, j+1, sub, ans);
            sub.pop_back();
        }
    }
};
