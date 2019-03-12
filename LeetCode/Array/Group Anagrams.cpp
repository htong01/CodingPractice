// By using hashmap
// sort first as key
// push_back values


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> temp;
        for(string s:strs){
            string t = s;
            sort(t.begin(),t.end());
            temp[t].push_back(s);
        }
        
        vector<vector<string>> ans;
        for(auto p:temp){
            ans.push_back(p.second);
        }
        return ans;
    }
};
