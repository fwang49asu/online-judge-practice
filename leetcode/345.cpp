class Solution {
public:
    string reverseVowels(string s) {
        string str = s;
        int n = str.length();
        int low = 0;
        int high = n-1;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for(; low < high && vowels.find(str[low]) == vowels.end(); ++low);
        for(; low < high && vowels.find(str[high]) == vowels.end(); --high);
        while(low < high) {
            swap(str[low], str[high]);
            for(++low; low < high && vowels.find(str[low]) == vowels.end(); ++low);
            for(--high; low < high && vowels.find(str[high]) == vowels.end(); --high);
        }
        return str;
    }
};
