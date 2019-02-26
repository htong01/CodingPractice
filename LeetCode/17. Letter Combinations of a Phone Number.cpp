// BFS

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0) return vector<string>();
        vector<string> res;
        string dict[10] = {"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        res.push_back("");
        
        for(int i=0;i<digits.length();i++){
            vector<string> temp;
            string chars = dict[digits[i] - '0'];
            
            for(int c=0;c<chars.length();c++){
                for(int j=0;j<res.size();j++){
                    temp.push_back(res[j]+chars[c]);
                }
            }
            res = temp;
        }
        return res;
    }
};
