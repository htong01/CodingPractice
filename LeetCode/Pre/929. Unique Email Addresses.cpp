和 10. Regular Expression Matching 有点像，不过这个更方便一点，只需要找到'@'，忽略'.'和'+'后面的东西就好
不需要用到DP的方法吧

https://stackoverflow.com/questions/20326356/how-to-remove-all-the-occurrences-of-a-char-in-c-string
#include <algorithm>
str.erase(std::remove(str.begin(), str.end(), 'a'), str.end());

答案写的乱七八糟的有点懒得看，干脆把最短的那个想了下自己的理解写了写，很直接的想法，就是有些函数不知道怎么用+没见过
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> unique;
        for(auto &e:emails){
            auto pos = e.find_first_of('@');
            auto name = e.substr(0, pos),
                domain = e.substr(pos);
            auto plus = name.find_first_of('+');
            name = name.substr(0, plus);
            name.erase( remove(name.begin(), name.end(), '.'), name.end() );
            string new_email = name + domain;
            if(unique.find(new_email) == unique.end()) unique.insert(new_email);
            
        }
        return unique.size();
    }
};
