int sockMerchant(int n, vector<int> ar) {
    unordered_map<int,int> map;
    int res = 0;
    for(int i=0;i<ar.size();i++){
        map[ar[i]]++;
        if(map[ar[i]] == 2) {
            res++;
            map[ar[i]] = 0;
        }
    }
    return res;

}
// 没看懂答案的写法，所以用hashmap来做的，python不会写！！！
