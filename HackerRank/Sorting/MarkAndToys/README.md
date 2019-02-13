**Bubble sort + cnt from the smallest = timeout**

```
int maximumToys(vector<int> prices, int k) {
    int n = prices.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            // Swap adjacent elements if they are in decreasing order
            if (prices[j] > prices[j + 1]) {
                swap(prices[j], prices[j + 1]);
            }
        }
    }
    // price array is sorted by bubble sort
    int cnt = 0;
    int total = 0;
    while(total <= k){
        total += prices[cnt];
        cnt++;
    }
    cnt = cnt - 1; //last time when (total>k), cnt still +1
    return cnt;

}
```
