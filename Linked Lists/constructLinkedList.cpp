using namespace std;

class Node {
public:
  int value;
  Node *prev;
  Node *next;

  Node(int value);
};

// Feel free to add new properties and methods to the class.
class DoublyLinkedList {
public:
  Node *head;
  Node *tail;

  DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
  }

  // O(1) time | O(1) space
  void setHead(Node *node) {
    // Write your code here.
    if (head == nullptr) {
      head = node;
      tail = node;
      return;
    }
    insertBefore(head, node);
  }

  // O(1) time | O(1) space
  void setTail(Node *node) {
    // Write your code here.
    if (tail == nullptr) {
      setHead(node);
      return;
    }
    insertAfter(tail, node);
  }

  // O(1) time | O(1) space
  void insertBefore(Node *node, Node *nodeToInsert) {
    // Write your code here.
    if (nodeToInsert == head && nodeToInsert == tail)
      return;
    remove(nodeToInsert);
    nodeToInsert->prev = node->prev;
    nodeToInsert->next = node;
    if (node->prev == nullptr) {
      head = nodeToInsert;
    } else {
      node->prev->next = nodeToInsert;
    }
    node->prev = nodeToInsert;
  }

  // O(1) time | O(1) space
  void insertAfter(Node *node, Node *nodeToInsert) {
    // Write your code here.
    if (nodeToInsert == head && nodeToInsert == tail)
      return;
    remove(nodeToInsert);
    nodeToInsert->prev = node;
    nodeToInsert->next = node->next;
    if (node->next == nullptr) {
      tail = nodeToInsert;
    } else {
      node->next->prev = nodeToInsert;
    }
    node->next = nodeToInsert;
  }

  // O(p) time | O(1) space - p: given position
  void insertAtPosition(int position, Node *nodeToInsert) {
    // Write your code here.
    if (position == 1) {
      setHead(nodeToInsert);
      return;
    }
    int currPosition = 1;
    Node *currentNode = head;
    while (currentNode != nullptr && currPosition != position) {
      currentNode = currentNode->next;
      currPosition++;
    }
    if (currentNode == nullptr) {
      setTail(nodeToInsert);
    } else {
      insertBefore(currentNode, nodeToInsert);
    }
  }

  // O(n) time | O(1) space
  void removeNodesWithValue(int value) {
    // Write your code here.
    Node *currentNode = head;
    while (currentNode != nullptr) {
      Node *potentialNodeToRemove = currentNode;
      currentNode = currentNode->next;
      if (potentialNodeToRemove->value == value)
        remove(potentialNodeToRemove);
    }
  }

  // O(1) time | O(1) space
  void remove(Node *node) {
    // Write your code here.
    if (node == head)
      head = head->next;
    if (node == tail)
      tail = tail->prev;
    removeNodeBindings(node);
  }

  // O(n) time | O(1) space
  bool containsNodeWithValue(int value) {
    // Write your code here.
    Node *currentNode = head;
    while (currentNode != nullptr) {
      if (currentNode->value == value)
        return true;
      currentNode = currentNode->next;
    }
    return false;
  }

  // O(1) time | O(1) space
  void removeNodeBindings(Node *node) {
    if (node->prev != nullptr)
      node->prev->next = node->next;
    if (node->next != nullptr)
      node->next->prev = node->prev;
    node->prev = nullptr;
    node->next = nullptr;
  }
};
