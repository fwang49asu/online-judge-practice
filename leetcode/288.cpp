class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for(string s: dictionary) {
            if(checked.find(s) == checked.end()) {
                count_map[convert(s)]++;
                checked.insert(s);
            }
        }
    }

    bool isUnique(string word) {
        if(checked.find(word) == checked.end()) {
            return count_map[convert(word)] < 1;
        }
        return count_map[convert(word)] == 1;
    }

    string convert(string s) {
        if(s.length() <= 2) {
            return s;
        }
        return s[0] + to_string(s.length() - 2) + s[s.length() - 1];
    }
    unordered_map<string, int> count_map;
    unordered_set<string> checked;
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");
