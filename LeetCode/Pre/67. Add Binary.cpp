RUNTIME ERROR 
不理解，我觉得写的完全没有问题才对

class Solution {
public:
    string addBinary(string a, string b) {
        string s = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int sum = 0;
        string res = "";
        while(i>=0 || j>=0 || sum==1){
            sum += (i>=0 ? a[i--]-'0':0);
            sum += (j>=0 ? a[j--]-'0':0);
            
            res = sum % 2 + '0';
            s.insert(0, res);
            sum /= 2;
        }
        return s;
    }
};
