#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        vector<int> findSubstring(string s, vector<string>& words) {
            vector<int> result;
            if(words.size() == 0 || words[0].length() == 0) {
                return result;
            }
            int N = s.length();
            int M = words.size();
            int K = words[0].length();
            int dic_size = M*K;
            if(N < M * K) {
                return result;
            }

            unordered_map<size_t, int> hash_map;
            size_t target = 0;
            for(string word: words) {
                size_t key = hash<string>{}(word);
                target += key;
                if(hash_map.find(key) == hash_map.end()) {
                    hash_map[key] = 1;
                } else {
                    int count = hash_map[key];
                    hash_map[key] = count + 1;
                }
            }

            vector<size_t> base_hash_vec(N-K+1);
            for(int i=0; i<=(N-K); ++i) {
                base_hash_vec[i] = hash<string>{}(s.substr(i, K));
            }

            for(int i=0; i<=(N-dic_size); ++i) {
                size_t sum = 0;
                for(int k=0; k<M; ++k) {
                    sum += base_hash_vec[i + k*K];
                }
                if(sum == target) {
                    result.push_back(i);
                }
            }
            return result;
        }
};

int main() {
    Solution s;
    string array[] = {"foo", "bar"};
    vector<string> vec(array, array+2);
    vector<int> result = s.findSubstring("barfoothefoobarman", vec);
    for(int i=0; i<result.size(); ++i) {
        cout << result[i] << endl;
    }
    return 0;
}
