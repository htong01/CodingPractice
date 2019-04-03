一点想法都没有！！！用recursion做，DFS，DP一般用于数据量小的情况
还要keep track of previous operator，运算符优先级问题
https://www.youtube.com/watch?v=v05R1OIIg08
class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        if(num.length() == 0) return ans;
        dfs(num, target, "", 0, 0, 0, ans);
        return ans;
    }
    
    void dfs(string num, int target, string exp, int pos, long prev, int curr, vector<string> &ans){
        if(pos == num.length()){
            if(curr == target) ans.push_back(exp);
            return;
        }
        for(int l=1;l<=num.length()-pos;l++){
            string t = num.substr(pos,l);
            if(t[0] == '0' && t.length()>1) break;
            long n = stol(t);
            if(n > INT_MAX) break;
            if(pos == 0){
                dfs(num, target, exp+t, l, n, n, ans);
            }
            else
            {   dfs(num, target, exp+"+"+t, pos+l, n, curr+n, ans);
                dfs(num, target, exp+"-"+t, pos+l, -n, curr-n, ans);
                dfs(num, target, exp+"*"+t, pos+l, prev*n, curr-prev+prev*n, ans);
            }
        }
    }
};
