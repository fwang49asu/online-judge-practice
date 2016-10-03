// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int times = n >> 2;
        char* p = buf;
        for(int i=0; i<times; p+=4, ++i) {
            int cur = read4(p);
            if(cur < 4) {
                return (i << 2) + cur;
            }
        }
        int remaining = n & 3;
        int got = read4(p);
        return (times << 2) + min(got, remaining);
    }
};
