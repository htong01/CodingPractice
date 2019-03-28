直接解O(2n) solution很方便，第一遍记一下012各出现了几次，第二遍就直接把数都填上就好
Follow Up不好想，看了答案
    Could you come up with a one-pass algorithm using only constant space?
    
太聪明了，先把所有值都设成2，在判断如果是1/如果是0


void sortColors(vector<int>& nums) {
    // FOLLOWUP
    int i = 0, j = 0;
    for(int k=0;k<nums.size();k++){
        int temp = nums[k];
        nums[k] = 2;
        if(temp < 2){
            nums[j] = 1;
            j++;
        }
        if(temp == 0){
            nums[i] = 0;
            i++;
        }
    }
}
