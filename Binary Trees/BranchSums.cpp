// O(n) time | O(n) space - where n is the number of nodes in the Binary Tree
using namespace std;

// This is the class of the input root. Do not edit it.
class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value) {
    this->value = value;
    left = NULL;
    right = NULL;
  }
};

void branchSumsHelper(BinaryTree *node, int currentSum, vector<int> &sums) {
  if (node == NULL)
    return;

  currentSum += node->value;
  if (node->left == NULL && node->right == NULL) {
    sums.push_back(currentSum);
    return;
  }
  branchSumsHelper(node->left, currentSum, sums);
  branchSumsHelper(node->right, currentSum, sums);
}

vector<int> branchSums(BinaryTree *root) {
  // Write your code here.
  vector<int> sums = {};
  int currentSum = 0;
  branchSumsHelper(root, currentSum, sums);
  return sums;
}
