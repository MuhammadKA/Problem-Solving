using namespace std;

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }

  void insert(int value) {
    if (value < this->value) {
      if (left == nullptr) {
        left = new BST(value);
      } else {
        left->insert(value);
      }
    } else {
      if (right == nullptr) {
        right = new BST(value);
      } else {
        right->insert(value);
      }
    }
  }
};

// O(nlog(n)) time | O(n) space
BST *constructMinHeightBST(vector<int> &array, BST *bst, int start, int end) {
  if (end < start)
    return nullptr;
  int midIdx = floor((start + end) / 2);
  int value = array[midIdx];
  if (bst == nullptr) {
    bst = new BST(value);
  } else {
    bst->insert(value);
  }
  constructMinHeightBST(array, bst, start, midIdx - 1);
  constructMinHeightBST(array, bst, midIdx + 1, end);
  return bst;
}

BST *minHeightBst(vector<int> array) {
  // Write your code here.
  return constructMinHeightBST(array, nullptr, 0, array.size() - 1);
}

// ---------------------------------------- < Optimal Solution > --------------------------------

using namespace std;

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }
};

// O(n) time | O(n) space
BST *constructMinHeightBst(vector<int> &array, BST *bst, int start, int end) {
  if (end < start)
    return nullptr;
  int midIdx = floor((start + end) / 2);
  BST *newBstNode = new BST(array[midIdx]);
  if (bst == nullptr) {
    bst = newBstNode;
  } else if (newBstNode->value > bst->value) {
    bst->right = newBstNode;
    bst = bst->right;
  } else {
    bst->left = newBstNode;
    bst = bst->left;
  }
  constructMinHeightBst(array, bst, start, midIdx - 1);
  constructMinHeightBst(array, bst, midIdx + 1, end);
  return bst;
}

BST *minHeightBst(vector<int> array) {
  // Write your code here.
  return constructMinHeightBst(array, nullptr, 0, array.size() - 1);
}

// ---------------------------------------- < Optimal/Cleaner Solution > --------------------------------
using namespace std;

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }
};

// O(n) time | O(n) space
BST *constructMinHeightBst(vector<int> &array, int start, int end) {
  if (end < start)
    return nullptr;
  int midIdx = floor((start + end) / 2);
  BST *bst = new BST(array[midIdx]);
  bst->left = constructMinHeightBst(array, start, midIdx - 1);
  bst->right = constructMinHeightBst(array, midIdx + 1, end);
  return bst;
}

BST *minHeightBst(vector<int> array) {
  // Write your code here.
  return constructMinHeightBst(array, 0, array.size() - 1);
}
