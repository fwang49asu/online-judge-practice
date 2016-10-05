class TwoSum {
    unordered_map<int,int> m;
public:
    void add(int number) {
        m[number]++;
    }

    bool find(int value) {
        for (auto e: m) {
            int a = e.first;
            int b = value - a;
            if ((a == b && e.second > 1) || (a != b && m.find(b) != m.end())) {
                return true;
            }
        }
        return false;
    }
};
