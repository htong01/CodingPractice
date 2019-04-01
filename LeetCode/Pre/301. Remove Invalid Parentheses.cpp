DFS
https://leetcode.com/problems/remove-invalid-parentheses/discuss/75048/recommend-for-beginnersclean-C%2B%2B-implementation-with-detailed-explaination

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> res;
        int l_remove = 0;
        int r_remove = 0;
        for(auto c:s){
            if(c=='(') l_remove++;
            if(c==')'){
                if(l_remove != 0) l_remove--;
                else
                    r_remove++;
            }
        }
        helper(0, 0, l_remove, r_remove, s, "", res);
        return vector<string>(res.begin(),res.end());
    }
    
    void helper(int pair, int index, int l_remove, int r_remove, string& s, string solution, unordered_set<string>& res){
        if(index == s.size()){
            if(pair==0 && r_remove==0 && l_remove==0) res.insert(solution);
            return;
        }
        
        if(s[index] == '('){
            if(l_remove > 0) helper(pair, index+1, l_remove-1, r_remove, s, solution, res);
            helper(pair+1, index+1, l_remove, r_remove, s, solution+s[index], res);
        }
        else if(s[index] == ')'){
            if(r_remove > 0) helper(pair, index+1, l_remove, r_remove-1, s, solution, res);
            if(pair>0) helper(pair-1, index+1, l_remove, r_remove, s, solution+s[index], res);
        }
        else
            helper(pair, index+1, l_remove, r_remove, s, solution+s[index], res);
        
    }
};
