#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.length();
        int low = 0;
        int high = len - 1;
        for(; low < high && !is_character(s[low]); ++low);
        for(; high > low && !is_character(s[high]); --high);
        while(low < high) {
            char a = s[low];
            if(is_lower(a)) {
                a = a - 'a' + 'A';
            }
            char b = s[high];
            if(is_lower(b)) {
                b = b - 'a' + 'A';
            }
            if(a != b) {
                return false;
            }
            for(++low; low < high && !is_character(s[low]); ++low);
            for(--high; high > low && !is_character(s[high]); --high);
        }
        return true;
    }
private:
    inline bool is_lower(char c) {
        return c >= 'a' && c <= 'z';
    }
    inline bool is_higher(char c) {
        return c >= 'A' && c <= 'Z';
    }
    inline bool is_number(char c) {
        return c >= '0' && c <= '9';
    }
    inline bool is_character(char c) {
        return is_lower(c) || is_higher(c) || is_number(c);
    }
};

int main(int argc, char const *argv[]) {

    return 0;
}
