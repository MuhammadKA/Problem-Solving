using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
public:
  int value;
  LinkedList *next = nullptr;

  LinkedList(int value) { this->value = value; }
};

// O(max(n, m)) time | O(max(n, m)) space - where n is the length of the first
// Linked List and m is the length of the second Linked List
LinkedList *sumOfLinkedLists(LinkedList *linkedListOne,
                             LinkedList *linkedListTwo) {
  // Write your code here.
  LinkedList *dummyNode = new LinkedList(0);
  LinkedList *currentNode = dummyNode;
  int currCarry = 0;
  int currSum = 0;

  while (linkedListOne != nullptr || linkedListTwo != nullptr ||
         currCarry != 0) {
    int firstNum = linkedListOne != nullptr ? linkedListOne->value : 0;
    int secondNum = linkedListTwo != nullptr ? linkedListTwo->value : 0;
    currSum = (firstNum + secondNum + currCarry) % 10;
    currCarry = (firstNum + secondNum + currCarry) / 10;
    LinkedList *Node = new LinkedList(currSum);
    currentNode->next = Node;
    currentNode = currentNode->next;
    if (linkedListOne != nullptr)
      linkedListOne = linkedListOne->next;
    if (linkedListTwo != nullptr)
      linkedListTwo = linkedListTwo->next;
  }
  return dummyNode->next;
}