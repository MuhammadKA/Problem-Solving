#include <vector>
using namespace std;

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
};

// O(n) time | O(n) space - n: number of nodes
void inOrderTraverse(BST *tree, vector<int> &array) {
  // Write your code here.
  if (tree != nullptr) {
    inOrderTraverse(tree->left, array);
    array.push_back(tree->value);
    inOrderTraverse(tree->right, array);
  }
}

// O(n) time | O(n) space
void preOrderTraverse(BST *tree, vector<int> &array) {
  // Write your code here.
  if (tree != nullptr) {
    array.push_back(tree->value);
    preOrderTraverse(tree->left, array);
    preOrderTraverse(tree->right, array);
  }
}

// O(n) time | O(n) space
void postOrderTraverse(BST *tree, vector<int> &array) {
  // Write your code here.
  if (tree != nullptr) {
    postOrderTraverse(tree->left, array);
    postOrderTraverse(tree->right, array);
    array.push_back(tree->value);
  }
}
