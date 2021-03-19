#include <vector>
using namespace std;

void buildMaxHeap(vector<int> &array); // O(n) time | O(1) space
void siftDown(int currentIdx, int endIdx,
              vector<int> &heap); // O(log(n)) time | O(1) space

// O(1) space | O(nlog(n)) time - For Worst, Average, and Best case scenario
vector<int> heapSort(vector<int> array) {
  // Write your code here.
  buildMaxHeap(array);
  for (int endIdx = array.size() - 1; endIdx > 0; endIdx--) {
    swap(array[0], array[endIdx]);
    siftDown(0, endIdx - 1, array);
  }
  return array;
}

void buildMaxHeap(vector<int> &array) {
  int firstParentIdx = floor((array.size() - 2) / 2);
  for (int currentIdx = firstParentIdx; currentIdx >= 0; currentIdx--) {
    siftDown(currentIdx, array.size() - 1, array);
  }
}

void siftDown(int currentIdx, int endIdx, vector<int> &heap) {
  int firstChildIdx = currentIdx * 2 + 1;
  while (firstChildIdx <= endIdx) {
    int secondChildIdx = currentIdx * 2 + 2 <= endIdx ? currentIdx * 2 + 2 : -1;
    int idxToSwap;
    if (secondChildIdx != -1 && heap[secondChildIdx] > heap[firstChildIdx]) {
      idxToSwap = secondChildIdx;
    } else {
      idxToSwap = firstChildIdx;
    }
    if (heap[idxToSwap] > heap[currentIdx]) {
      swap(heap[idxToSwap], heap[currentIdx]);
      currentIdx = idxToSwap;
      firstChildIdx = currentIdx * 2 + 1;
    } else {
      return;
    }
  }
}
