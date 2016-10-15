class WordDistance {
public:
    WordDistance(vector<string>& words) {
        int n = words.size();
        for(int i=0; i<n; ++i) {
            position_map.insert(make_pair(words[i], i));
        }
    }

    int shortest(string word1, string word2) {
        string key = "";
        if(word1.compare(word2) < 0) {
            key = word1 + word2;
        } else {
            key = word2 + word1;
        }
        if(distance_map.find(key) != distance_map.end()) {
            return distance_map[key];
        }
        auto range_1 = position_map.equal_range(word1);
        auto range_2 = position_map.equal_range(word2);
        int result = INT_MAX;

        for(auto a = range_1.first; a!=range_1.second; ++a) {
            for(auto b = range_2.first; b!=range_2.second; ++b) {
                result = min(result, abs(a->second - b->second));
            }
        }

        distance_map.insert(make_pair(key, result));
        return result;
    }
private:
    multimap<string, int> position_map;
    unordered_map<string, int> distance_map;
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");
