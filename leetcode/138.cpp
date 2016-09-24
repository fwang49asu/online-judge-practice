class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode*, RandomListNode*> visit_map;
        if(head == NULL) {
            return NULL;
        }
        RandomListNode* cur_old = head;
        RandomListNode* new_head = new RandomListNode(head->label);
        RandomListNode* cur_new = new_head;

        while(cur_old != NULL) {
            cur_new->next = GetNode(cur_old->next, visit_map);
            cur_new->random = GetNode(cur_old->random, visit_map);
            cur_old = cur_old->next;
            cur_new = cur_new->next;
        }
        return new_head;
    }
    RandomListNode* GetNode(RandomListNode* old, unordered_map<RandomListNode*, RandomListNode*>& visit_map) {
        if(old == NULL) {
            return NULL;
        }
        if(visit_map.find(old) != visit_map.end()) {
            return visit_map[old];
        }
        RandomListNode* new_node = new RandomListNode(old->label);
        visit_map[old] = new_node;
        return new_node;
    }
};
