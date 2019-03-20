Go left to right and set "next" candy value to either "previous+1" or "1". Then go right to left and do the same. Very simple O(2xN) solution
Passed only half test cases in this way.

long candies(int n, vector<int> arr) {
    vector<int> t1;
    t1.push_back(1);
    vector<int> t2;
    t2.push_back(1);

    int temp = 1;
    for(int i=1;i<n;i++){
        if(arr[i]>arr[i-1]) temp += 1;
        else temp = 1;
        t1.push_back(temp);
    }
    int t = 1;
    for(int j=n-1;j>=0;j--){
        if(arr[j]>arr[j+1]) t += 1;
        else t = 1;
        t2.push_back(t);
    }
    reverse(t2.begin(),t2.end());
    long ans = 0;
    for(int k=0;k<n;k++){
        ans += max(t1[k],t2[k]);
    }
    return ans;
}

--------------------------------------------------------------------------------------------

