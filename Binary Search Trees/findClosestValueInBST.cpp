// Recursive solution
// Average: O(log(n)) time | O(log(n)) space
// Worst: O(n) time | O(n) space

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};

int findClosestValueInBstHelper(BST *tree, int target, int closest) {
  // Base case
  if (tree == NULL) {
    return closest;
  }
  if (abs(target - tree->value) < abs(target - closest)) {
    closest = tree->value;
  }
  if (tree->value > target) {
    return findClosestValueInBstHelper(tree->left, target, closest);
  } else if (tree->value < target) {
    return findClosestValueInBstHelper(tree->right, target, closest);
  } else {
    return closest;
  }
}

int findClosestValueInBst(BST *tree, int target) {
  // Write your code here.
  return findClosestValueInBstHelper(tree, target, tree->value);
}

// ********************************************************* << Another Solution >> **************************************************************

// Iterative solution
// Average: O(log(n)) time | O(1) space
// Worst: O(n) time | O(1) space

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};

int findClosestValueInBst(BST *tree, int target) {
  BST *currentNode = tree;
  int closest = currentNode->value;
  while (currentNode != NULL) {
    if (abs(target - currentNode->value) < abs(target - closest)) {
      closest = currentNode->value;
    }
    if (currentNode->value > target) {
      currentNode = currentNode->left;
    } else if (currentNode->value < target) {
      currentNode = currentNode->right;
    } else {
      break;
    }
  }
  return closest;
}
