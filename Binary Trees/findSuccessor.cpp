using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
  int value;
  BinaryTree *left = nullptr;
  BinaryTree *right = nullptr;
  BinaryTree *parent = nullptr;

  BinaryTree(int value) { this->value = value; }
};

// O(n) time | O(n) space
void getInOrderTraversalOrder(BinaryTree *node, vector<BinaryTree *> &order);

BinaryTree *findSuccessor(BinaryTree *tree, BinaryTree *node) {
  // Write your code here.
  vector<BinaryTree *> inOrderTraversalOrder;
  getInOrderTraversalOrder(tree, inOrderTraversalOrder);

  for (int i = 0; i < inOrderTraversalOrder.size(); i++) {
    if (inOrderTraversalOrder[i] == node &&
        (i + 1) < inOrderTraversalOrder.size())
      return inOrderTraversalOrder[i + 1];
  }
  return nullptr;
}

void getInOrderTraversalOrder(BinaryTree *node, vector<BinaryTree *> &order) {
  if (node == nullptr)
    return;
  getInOrderTraversalOrder(node->left, order);
  order.push_back(node);
  getInOrderTraversalOrder(node->right, order);
}

// ---------------------- < Optimal Solution > ------------------

using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
  int value;
  BinaryTree *left = nullptr;
  BinaryTree *right = nullptr;
  BinaryTree *parent = nullptr;

  BinaryTree(int value) { this->value = value; }
};
// O(d) time | O(1) space 
BinaryTree *findLeftMostChild(BinaryTree *node) {
  BinaryTree *currentNode = node;
  while (currentNode->left != nullptr) {
    currentNode = currentNode->left;
  }
  return currentNode;
}

BinaryTree *findRightMostParent(BinaryTree *node) {
  BinaryTree *currentNode = node;
  while (currentNode->parent != nullptr &&
         currentNode->parent->right == currentNode) {
    currentNode = currentNode->parent;
  }
  return currentNode->parent;
}

BinaryTree *findSuccessor(BinaryTree *tree, BinaryTree *node) {
  // Write your code here.
  if (node->right != nullptr)
    return findLeftMostChild(node->right);
  return findRightMostParent(node);
}
