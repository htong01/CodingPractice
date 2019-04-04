难点在于，理解题目问了啥，思路很简单。
注意给的API输入是pointer形式

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int res = 0;
        int lastRead = 4;
        while(res<n && lastRead==4){
            lastRead = read4(buf+res);
            res += lastRead;
        }
        return min(res, n);
    }
};
