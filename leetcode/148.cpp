class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL) {
            return NULL;
        }
        // radix sort
        // we just assume all numbers are positive here.
        // for negative numbers, use two buckets in the last run
        // use bucket sort
        int bucket_num = 1 << 4;
        int mask = bucket_num - 1;
        typedef pair<ListNode*, ListNode*> Bucket;
        Bucket empty_bucket = make_pair<ListNode*, ListNode*>(NULL, NULL);
        vector<Bucket> buckets(bucket_num, empty_bucket);
        vector<Bucket> next_buckets(bucket_num, empty_bucket);

        buckets[0].first = head;
        for(int i=0; i<9; ++i) {
            for(Bucket& cur: buckets) {
                ListNode* next;
                for(ListNode* p = cur.first; p != NULL; p = next) {
                    int index = 0;
                    if(i < 7) {
                        index = (p->val >> (i << 2)) & mask;
                    } else if(i == 7) {
                        mask = mask >> 1;
                        index = p->val >> (i << 2) & mask;
                    } else {
                        index = p->val < 0 ? 0 : 1;
                    }
                    if(next_buckets[index].first == NULL) {
                        next_buckets[index].first = p;
                        next_buckets[index].second = p;
                    } else {
                        next_buckets[index].second->next = p;
                        next_buckets[index].second = p;
                    }
                    next = p->next;
                    p->next = NULL;
                }
            }
            buckets.swap(next_buckets);

            vector<Bucket> vec(bucket_num, empty_bucket);
            next_buckets.swap(vec);
        }

        ListNode* result = NULL;
        ListNode* tail = NULL;
        for(Bucket& cur: buckets) {
            if(cur.first != NULL) {
                if(result == NULL) {
                    result = cur.first;
                    tail = cur.second;
                } else {
                    tail->next = cur.first;
                    tail = cur.second;
                }
            }
        }
        return result;
    }
};
