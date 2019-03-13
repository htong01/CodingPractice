class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        if(nums.size()<=3) return accumulate(nums.begin(),nums.end(),0);
        int sum;
        int ans = nums[0] + nums[1] + nums[2];
        
        for(int i=0;i<nums.size()-2;i++){
            int left = i + 1;
            int right = nums.size()-1;
            
            while(left < right){
                sum = nums[i] + nums[left] + nums[right];
                
                if(abs(sum-target)<abs(ans-target) ){
                    ans = sum;
                    if(ans == target) return ans;
                }
                (sum > target) ? right--:left++;
            }
        }
        return ans;
    }
};
