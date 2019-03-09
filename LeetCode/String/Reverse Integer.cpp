// 轻敌了！人生处处是陷阱
  int reverse(int x) {
      int res = 0;
      while(x>0){
          res = res*10 + x%10;
          x = x/10;
      }
      return res;
  }

  // runtime error: signed integer overflow: 964632435 * 10 cannot be represented in type 'int'
  // Need to check overflow
  
class Solution {
public:
    int reverse(int x) {
        long int res = 0;
        while(x!=0){              // end case should be != for negative ones
            res = res*10 + x%10;
            x = x/10;
        }
        if (res > INT_MAX || res < INT_MIN) return 0;  // check overflow!!!!!!
        return res;
    }
};
----------------Python Solution-------------------
class Solution:
    def reverse(self, x: int) -> int:
        sign = [1,-1][x<0]
        rev, x = 0, abs(x)
        while x != 0:
            x, mod = divmod(x,10)
            rev = rev*10 + mod
        return sign*rev if -pow(2,31)<=sign*rev<=pow(2,31)-1 else 0
