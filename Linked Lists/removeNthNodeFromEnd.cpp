#include <vector>
using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value);
  void addMany(vector<int> values);
  vector<int> getNodesInArray();
};

// O(n) space | O(1) space
void removeKthNodeFromEnd(LinkedList *head, int k) {
  // Write your code here.
  int currentNodeCount = 0;
  LinkedList *firstPtr = head;
  LinkedList *secondPtr = head;
  while (currentNodeCount < k) {
    secondPtr = secondPtr->next;
    currentNodeCount++;
  }
  if (secondPtr == nullptr) {
    head->value = head->next->value;
    head->next = head->next->next;
    return;
  }
  while (secondPtr->next != nullptr) {
    firstPtr = firstPtr->next;
    secondPtr = secondPtr->next;
  }
  firstPtr->next = firstPtr->next->next;
}
