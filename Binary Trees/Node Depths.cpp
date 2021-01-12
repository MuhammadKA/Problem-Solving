// Recursive Solution
// O(n) time | O(d) space - where n is the number of nodes in the Binary Tree
// and d is the depth of the Binary Tree
using namespace std;

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

int nodeDepthsHelper(BinaryTree *root, int depths) {
  if (root == NULL)
    return 0;
  return depths + nodeDepthsHelper(root->right, depths + 1) +
         nodeDepthsHelper(root->left, depths + 1);
}

int nodeDepths(BinaryTree *root) {
  // Write your code here.
  return nodeDepthsHelper(root, 0);
}

// ********************************************* < Another Solution > ******************************************** 
// Iterative Solution 
// Average: O(n) time | O(d) space - where n is the number of nodes in the Binary Tree 
// and d is the depth of the Binary Tree

using namespace std;

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

struct Level {
  BinaryTree *root;
  int depth;
};

int nodeDepths(BinaryTree *root) {
  // Write your code here.
  int sumOfDepths = 0;
  vector<Level> stack = {{root, 0}};
  while (stack.size() > 0) {
    BinaryTree *node = stack.back().root;
    int depth = stack.back().depth;
    stack.pop_back();
    if (node == NULL)
      continue;
    sumOfDepths += depth;
    stack.push_back(Level{node->left, depth + 1});
    stack.push_back(Level{node->right, depth + 1});
  }
  return sumOfDepths;
}