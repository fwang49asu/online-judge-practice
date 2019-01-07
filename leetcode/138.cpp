class Solution {
public:
  RandomListNode *copyRandomList(RandomListNode *head) {
    if (head == NULL) {
      return NULL;
    }
    RandomListNode* cur = head;
    while(cur != NULL) {
      RandomListNode* node = new RandomListNode(cur->label);
      node->next = cur->next;
      cur->next = node;
      cur = cur->next->next;
    }
    cur = head;
    while (cur != NULL) {
      cur->next->random = cur->random == NULL ? NULL : cur->random->next;
      cur = cur->next->next;
    }
    RandomListNode* result = new RandomListNode(0);
    RandomListNode* tail = result;
    cur = head;
    while(cur != NULL) {
      tail->next = cur->next;
      cur->next = cur->next->next;
      tail = tail->next;
      cur = cur->next;
    }
    cur = result->next;
    result->next = NULL;
    delete result;
    return cur;
  }
};
