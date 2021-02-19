using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }
};

struct TreeInfo {
  int diameter;
  int height;
};

TreeInfo getTreeInfo(BinaryTree *tree) {
  if (tree == nullptr)
    return TreeInfo{0, 0};
  TreeInfo leftTreeInfo = getTreeInfo(tree->left);
  TreeInfo rightTreeInfo = getTreeInfo(tree->right);

  int longestPathThroughRoot = leftTreeInfo.height + rightTreeInfo.height;
  int maxDiameterSoFar = max(leftTreeInfo.diameter, rightTreeInfo.diameter);
  int currentMaxDiameter = max(maxDiameterSoFar, longestPathThroughRoot);
  int currentHeight = max(leftTreeInfo.height, rightTreeInfo.height) + 1;
  return {currentMaxDiameter, currentHeight};
}

int binaryTreeDiameter(BinaryTree *tree) {
  // Write your code here.
  return getTreeInfo(tree).diameter;
}
