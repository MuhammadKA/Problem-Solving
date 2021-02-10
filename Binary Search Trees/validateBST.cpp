class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};

bool validateBstHelper(BST *tree, int minValue, int maxValue);

bool validateBst(BST *tree) {
  // Write your code here.
  int maxValue = INT_MAX;
  int minValue = INT_MIN;
  return validateBstHelper(tree, minValue, maxValue);
}

// O(n) time | O(d) space
bool validateBstHelper(BST *tree, int minValue, int maxValue) {
  if (tree == NULL)
    return true;

  if (tree->value >= maxValue || tree->value < minValue)
    return false;

  return validateBstHelper(tree->left, minValue, tree->value) &&
         validateBstHelper(tree->right, tree->value, maxValue);
}
