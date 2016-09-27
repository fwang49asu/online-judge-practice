#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class LRUCache{
public:
    LRUCache(int cap) {
        head_index = -1;
        tail_index = -1;
        capacity = cap;
    }

    int get(int key) {
        if(index_map.find(key) == index_map.end()) {
            return -1;
        }
        int index = index_map[key];
        int result = vec[index].value;
        MoveToHead(index);
        return result;
    }

    void set(int key, int value) {
        if(capacity == 0) {
            return;
        }
        if(index_map.find(key) == index_map.end()) {
            // add one to the head
            int size = vec.size();
            if(size < capacity) {
                Node node;
                node.key = key;
                node.value = value;
                node.next = head_index;
                node.prev = -1;
                if(vec.empty()) {
                    tail_index = 0;
                } else {
                    vec[head_index].prev = size;
                }
                head_index = size;
                index_map.insert(make_pair(key, head_index));
                vec.push_back(node);
            } else {
                index_map.erase(vec[tail_index].key);
                index_map.insert(make_pair(key, tail_index));
                vec[tail_index].key = key;
                vec[tail_index].value = value;
                MoveToHead(tail_index);
            }
        } else {
            int index = index_map[key];
            vec[index].value = value;
            MoveToHead(index);
        }
    }
private:
    struct Node{
        int key;
        int value;
        int prev;
        int next;
    };
    vector<Node> vec;
    unordered_map<int, int> index_map;
    int head_index;
    int tail_index;
    int capacity;

    void MoveToHead(int index) {
        if(index == head_index) {
            return;
        }
        Node& cur = vec[index];
        Node& prev = vec[cur.prev];
        if(tail_index == index) {
            prev.next = -1;
            tail_index = cur.prev;
        } else {
            Node& next = vec[cur.next];
            prev.next = cur.next;
            next.prev = cur.prev;
        }
        vec[head_index].prev = index;
        cur.next = head_index;
        cur.prev = -1;
        head_index = index;
    }
};

int main(int argc, char const *argv[]) {
    LRUCache cache(1);
    cache.set(2, 1);
    cout << cache.get(2) << endl;
    return 0;
}
