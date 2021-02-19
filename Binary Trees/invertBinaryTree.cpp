#include <deque>
#include <vector>
using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value);
  void insert(vector<int> values, int i = 0);
  void invertedInsert(vector<int> values, int i = 0);
};

// O(n) time | O(n) space
void invertBinaryTree(BinaryTree *tree) {
  // Write your code here.
  deque<BinaryTree *> queue;
  queue.push_back(tree);

  while (!queue.empty()) {
    BinaryTree *currentNode = queue.front();
    queue.pop_front();
    if (currentNode == nullptr)
      continue;
    swap(currentNode->left, currentNode->right);
    queue.push_back(currentNode->left);
    queue.push_back(currentNode->right);
  }
}

// ----------------------------- < Recursive Solution > -----------------------

#include <vector>
using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value);
  void insert(vector<int> values, int i = 0);
  void invertedInsert(vector<int> values, int i = 0);
};

// O(n) time | O(d = log(n)) space
void invertBinaryTree(BinaryTree *tree) {
  // Write your code here.
  if (tree == nullptr)
    return;
  swap(tree->left, tree->right);
  invertBinaryTree(tree->left);
  invertBinaryTree(tree->right);
}
