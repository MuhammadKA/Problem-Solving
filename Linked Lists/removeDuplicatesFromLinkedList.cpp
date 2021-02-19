using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
public:
  int value;
  LinkedList *next = nullptr;

  LinkedList(int value) { this->value = value; }
};

// O(n) time | O(1) space
void remove(LinkedList *current, LinkedList *nodeToRemove);

LinkedList *removeDuplicatesFromLinkedList(LinkedList *linkedList) {
  // Write your code here.
  LinkedList *current = linkedList;
  while (current->next != nullptr) {
    if (current->value == current->next->value) {
      remove(current, current->next);
    } else {
      current = current->next;
    }
  }
  return linkedList;
}

void remove(LinkedList *current, LinkedList *nodeToRemove) {
  current->next = nodeToRemove->next;
  nodeToRemove->next = nullptr;
}
