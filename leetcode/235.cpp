#include <iostream>
#include <vector>

using namespace std;

class TreeNode {
 public:
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  ~TreeNode() {
    if(NULL != left) {
      delete left;
    }
    if(NULL != right) {
      delete right;
    }
  }
};

class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(NULL == root) {
      return NULL;
    }
    if(p == q) {
      return p;
    }
    // use dfs to find p
    // use dfs to find q
    vector<TreeNode*> pathP;
    vector<TreeNode*> pathQ;
    pathP.push_back(root);
    pathQ.push_back(root);
    dfs(p, pathP);
    dfs(q, pathQ);
    for(int i=0; i<pathP.size(); ++i) {
      cout << pathP[i]->val << " ";
    }
    cout << endl;
    for(int i=0; i<pathQ.size(); ++i) {
      cout << pathQ[i]->val << " ";
    }
    cout << endl;
    int index;
    for(index = 0; index<pathQ.size() && index<pathP.size() && pathQ[index] == pathP[index]; ++index);
    return pathP[index-1];
  }
 private:
  bool dfs(TreeNode* target, vector<TreeNode*>& path) {
    TreeNode* root = path.back();
    if(NULL == root) {
      path.pop_back();
      return false;
    }
    if(root == target) {
      return true;
    }
    path.push_back(root->left);
    if(dfs(target, path)) {
      return true;
    }

    path.push_back(root->right);
    if(dfs(target, path)) {
      return true;
    }
    path.pop_back();
    return false;
  }
};

int main() {
  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(3);
  root->right = new TreeNode(6);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(4);
  root->left->left->left = new TreeNode(1);

  TreeNode* p = root->left->left->left;
  TreeNode* q = root->left->right;
  Solution s;
  cout << s.lowestCommonAncestor(root, p, q)->val << endl;
  delete root;
  return 0;
}
