#include <vector>
using namespace std;

// Do not edit the class below except
// for the depthFirstSearch method.
// Feel free to add new properties
// and methods to the class.
class Node {
public:
  string name;
  vector<Node *> children;

  Node(string str) { name = str; }

  // O(v+e) time | O(v) space
  vector<string> depthFirstSearch(vector<string> *array) {
    // Write your code here.
    // For every node
    // whenever we are at a given node, we gonna add that node's name to the
    // final array and then for every child node that node has, we gonna call
    // the depthFirstSearch function and pass the final array.
    array->push_back(this->name);
    for (Node *child : this->children) {
      child->depthFirstSearch(array);
    }
    // End of your code.
    return *array;
  }

  Node *addChild(string name) {
    Node *child = new Node(name);
    children.push_back(child);
    return this;
  }
};
