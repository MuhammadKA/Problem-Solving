// Iterative Solution

#include <vector>
using namespace std;

// Do not edit the class below except for
// the insert, contains, and remove methods.
// Feel free to add new properties and methods
// to the class.
class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val) {
    value = val;
    left = NULL;
    right = NULL;
  }

  // Average O(log(n)) time | O(1) space
  // Worst 	 O(n) time | O(1) space
  BST &insert(int val) {
    // Write your code here.
    // We call the insert function on a given node.
    BST *current = this;
    while (true) {
      if (current->value > val) {
        if (current->left == NULL) {
          BST *newNode = new BST(val);
          current->left = newNode;
          break;
        } else {
          current = current->left;
        }
      } else {
        if (current->right == NULL) {
          BST *newNode = new BST(val);
          current->right = newNode;
          break;
        } else {
          current = current->right;
        }
      }
    }
    // Do not edit the return statement of this method.
    return *this;
  }

  // Average O(log(n)) time | O(1) space
  // Worst 	 O(n) time | O(1) space
  bool contains(int val) {
    // Write your code here.
    BST *current = this;
    while (current != NULL) {
      if (current->value > val)
        current = current->left;
      else if (current->value < val)
        current = current->right;
      else
        return true;
    }
    return false;
  }

  // Average O(log(n)) time | O(1) space
  // Worst 	 O(n) time | O(1) space
  BST &remove(int val, BST *parentNode = NULL) {
    // Write your code here.
    BST *currentNode = this;
    while (currentNode != NULL) {
      if (currentNode->value > val) {
        parentNode = currentNode;
        currentNode = currentNode->left;
      } else if (currentNode->value < val) {
        parentNode = currentNode;
        currentNode = currentNode->right;
      } else { // we found the node with the required value
        // check if the node has both its children
        if (currentNode->left != NULL && currentNode->right != NULL) {
          // replace the current node value with the smallest value in the
          // right sub-tree
          currentNode->value = currentNode->right->getMinValue();
          currentNode->right->remove(currentNode->value, currentNode);
        } else if (parentNode == NULL) {
          // If we are dealing with the root node with only one branch
          if (currentNode->left != NULL) {
            currentNode->value = currentNode->left->value;
            currentNode->right = currentNode->left->right;
            currentNode->left = currentNode->left->left;
          } else if (currentNode->right != NULL) {
            currentNode->value = currentNode->right->value;
            currentNode->left = currentNode->right->left;
            currentNode->right = currentNode->right->right;
          } else {
            // This is a single-node tree; do nothing.
          }
        } else if (parentNode->left == currentNode) {
          parentNode->left = currentNode->left != NULL ? currentNode->left
                                                       : currentNode->right;
        } else if (parentNode->right == currentNode) {
          parentNode->right = currentNode->left != NULL ? currentNode->left
                                                        : currentNode->right;
        }
        break;
      }
    }
    // Do not edit the return statement of this method.
    return *this;
  }

  int getMinValue() {
    BST *currentNode = this;
    while (currentNode->left != NULL) {
      currentNode = currentNode->left;
    }
    return currentNode->value;
  }
};
