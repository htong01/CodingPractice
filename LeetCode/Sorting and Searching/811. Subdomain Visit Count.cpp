Hash table problem

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> mp;
        for(auto &c:cpdomains){
            int i = c.find(" ");
            int n = stoi(c.substr(0,i));
            string s = c.substr(i+1);
            for(int i=0;i<s.length();++i){
                if(s[i] == '.') 
                    mp[s.substr(i+1)] += n;
            }
            mp[s] += n;
        }
        
        vector<string> res;
        for(auto k:mp)
            res.push_back(to_string(k.second) + " " + k.first);
        return res;
    }

};
