// Go left to right and set "next" candy value to either "previous+1" or "1". Then go right to left and do the same. Very simple O(2xN) solution
// Passed only half test cases in this way.

// Initialize vector<int> 要注意，这里一开始没写对

long candies(int n, vector<int> arr) {
    vector<int> candies(n,0);
    candies[0] = 1;
    for(int i=1;i<n;i++){
        candies[i] = (arr[i]>arr[i-1]) ? (candies[i-1]+1) : 1;
    }
    for(int i=n-1;i>=0;i--){
        candies[i] = (arr[i]>arr[i+1] && (arr[i+1]+1)>=arr[i]) ? (candies[i+1]+1) : candies[i];
    }
    long ans = 0;
    for(int i=0;i<n;i++){
        ans += candies[i];
    }
    return ans;
}
