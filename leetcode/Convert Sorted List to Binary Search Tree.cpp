/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *buildSubTree(ListNode* &head, int start, int end){
        if(start>end)
            return NULL;
        int mid=start+(end-start)/2;
        TreeNode *l=buildSubTree(head,start,mid-1);
        TreeNode *root=new TreeNode(head->val);
        head=head->next;
        TreeNode *r=buildSubTree(head,mid+1,end);
        root->left=l;
        root->right=r;
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        int len=0;
        ListNode *cur=head;
        while(cur){
            len++;
            cur=cur->next;
        }
        return buildSubTree(head,0,len-1);
    }
    
};