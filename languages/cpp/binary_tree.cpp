#include <iostream>

struct TreeNode {
  TreeNode() : data(-1), left(nullptr), right(nullptr) {}
  explicit TreeNode(int d) : data(d), left(nullptr), right(nullptr) {}

  int data;
  TreeNode *left;
  TreeNode *right;
};

void inorder(TreeNode *root) {
  if (root == nullptr) {
    return;
  }

  inorder(root->left);
  std::cout << root->data << " ";
  inorder(root->right);
}

inline void tree_stack() {
  TreeNode root(4);
  TreeNode left(2);
  TreeNode right(7);

  root.left = &left;
  root.right = &right;

  inorder(&root);
}

inline void tree_heap() {
  TreeNode *root = new TreeNode(4);
  TreeNode *left = new TreeNode(2);
  TreeNode *right = new TreeNode(7);

  root->left = left;
  root->right = right;

  inorder(root);

  delete left;
  delete right;
  delete root;
}

int main() { return 0; }
