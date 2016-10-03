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
        if(n == 0) {
            return 0;
        }
        if(n <= buffered_count) {
            for(int i=0; i<n; ++i) {
                buf[i] = buffer[i];
            }
            int diff = buffered_count - n;
            for(int i=0; i<diff; ++i) {
                buffer[i] = buffer[i+n];
            }
            buffered_count = diff;
            return n;
        }
        // consume all buffer
        for(int i=0; i<buffered_count; ++i) {
            buf[i] = buffer[i];
        }
        int head = buffered_count;
        buf += buffered_count;
        n -= buffered_count;
        buffered_count = 0;

        int times = n >> 2;
        for(int i=0; i<times; ++i, buf+=4) {
            int cur = read4(buf);
            if(cur < 4) {
                return head + (i << 2) + cur;
            }
        }
        int remaining = n & 3;
        buffered_count = read4(buffer);
        remaining = min(remaining, buffered_count);
        remaining = read(buf, remaining);
        return head + remaining + (times << 2);
    }
private:
    char buffer[4];
    int buffered_count = 0;
};
