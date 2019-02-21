/*
Simple and straight O(n^2) loop. But two test case timeout
*/

int minimumAbsoluteDifference(vector<int> arr) {
    int n = arr.size();
    int res = INT_MAX;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int temp = abs(arr[i] - arr[j]);
            if(temp<res) res = temp;
        }
    }
    return res;
}
