非相邻元素的子集最大和
int maxSubsetSum(vector<int> arr) {
    if(arr.size() == 0) return 0;
    arr[0] = max(0, arr[0]);
    if(arr.size() == 1) return arr[0];
    arr[1] = max(arr[0], arr[1]);

    for(int i=2;i<arr.size();i++){
        arr[i] = max(arr[i-1], arr[i]+arr[i-2]);
    }
    return arr[arr.size()-1];
}
