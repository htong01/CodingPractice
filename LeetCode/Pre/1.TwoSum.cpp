// O(n) solution

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
            int toFind = target - nums[i];
            if(map.find(toFind) != map.end()){
                res.push_back(i);
                res.push_back(map[toFind]);
                return res;
            }
            map[nums[i]] = i;
        }
        return res;
    }
};
