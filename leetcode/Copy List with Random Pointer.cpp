/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head==NULL)
            return NULL;
        RandomListNode *cur=head,*tmp;
        while(cur!=NULL){
            tmp=new RandomListNode(cur->label);
            tmp->next=cur->next;
            cur->next=tmp;
            cur=cur->next->next;
        }
        cur=head;
        while(cur!=NULL){
            tmp=cur->next;
            if(cur->random!=NULL)
                tmp->random=cur->random->next;
            cur=cur->next->next;
        }
        cur=head;
        RandomListNode *nh=head->next;
        while(cur!=NULL){
            tmp=cur->next;
            cur->next=tmp->next;
            if(tmp->next!=NULL)
                tmp->next=tmp->next->next;
            cur=cur->next;
        }
        return nh;
    }
};