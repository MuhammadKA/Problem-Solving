#include <vector>
using namespace std;

// Do not edit the class below except for the buildHeap,
// siftDown, siftUp, peek, remove, and insert methods.
// Feel free to add new properties and methods to the class.
class MinHeap {
public:
  vector<int> heap;

  MinHeap(vector<int> vector) { heap = buildHeap(vector); }

  // O(n) time | O(1) space
  vector<int> buildHeap(vector<int> &vector) {
    // Write your code here.
    int firstParentIdx = (vector.size() - 2) / 2;
    for (int currentIdx = firstParentIdx; currentIdx >= 0; currentIdx--) {
      siftDown(currentIdx, vector.size() - 1, vector);
    }
    return vector;
  }

  // O(log(n)) time | O(1) space - just like a binary tree
  void siftDown(int currentIdx, int endIdx, vector<int> &heap) {
    // Write your code here.
    int childOneIdx = currentIdx * 2 + 1;
    while (childOneIdx <= endIdx) {
      int childTwoIdx = currentIdx * 2 + 2 <= endIdx ? currentIdx * 2 + 2 : -1;
      int idxToSwap;
      if (childTwoIdx != -1 && heap[childTwoIdx] < heap[childOneIdx]) {
        idxToSwap = childTwoIdx;
      } else {
        idxToSwap = childOneIdx;
      }
      if (heap[idxToSwap] < heap[currentIdx]) {
        swap(heap[idxToSwap], heap[currentIdx]);
        currentIdx = idxToSwap;
        childOneIdx = currentIdx * 2 + 1;
      } else {
        return;
      }
    }
  }

  // O(log(n)) time | O(1) space - just like a binary tree
  void siftUp(int currentIdx, vector<int> &heap) {
    // Write your code here.
    int parentIdx = (currentIdx - 1) / 2;
    while (parentIdx > 0 && heap[parentIdx] > heap[currentIdx]) {
      swap(heap[parentIdx], heap[currentIdx]);
      currentIdx = parentIdx;
      parentIdx = (currentIdx - 1) / 2;
    }
  }

  // O(1) time | O(1) space
  int peek() {
    // Write your code here.
    return heap[0];
  }

  // O(log(n)) time | O(1) space
  int remove() {
    // Write your code here.
    swap(heap[0], heap[heap.size() - 1]);
    int valueToRemove = heap[heap.size() - 1];
    heap.pop_back();
    siftDown(0, heap.size() - 1, heap);
    return valueToRemove;
  }

  // O(log(n)) time | O(1) space
  void insert(int value) {
    // Write your code here.
    heap.push_back(value);
    siftUp(heap.size() - 1, heap);
  }
};
