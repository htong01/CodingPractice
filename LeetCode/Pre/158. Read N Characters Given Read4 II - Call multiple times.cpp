Difference with #157:

Call once: Assume you are always going to read from the start of the file/bufer.
Call multiple times: Start reading from where you left off. This means that you have to store the last place (ptr) where you stopped and store the read but uncopied bytes to the buffer.

The only thing is when you call read4() which reads 4 bytes into your buffer you might read more than you need, so you want to store those bytes in the structure, and next time you call read will start from those stored bytes, then read more from the file.

超级聪明的解法：每次调用read的时候会更新i4和n4，i4用来存当前读到哪了的位置，n4是每次4个字母的读出来，如果i4==n4，可以往后读下一段4个字母了
在read函数之外一定要新建东西存位置的，看到还有解法是用了queue<int>，
// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
private:
    int i4 = 0, n4 = 0;
    char buf4[4];
public:
    int read(char *buf, int n) {
        int i = 0;
        while(i < n){
            if(i4 == n4){
                i4 = 0;
                n4 = read4(buf4);
                if(!n4) break;     // 读完了
            }
            buf[i++] = buf4[i4++];
        }
        return i;
    }
};
