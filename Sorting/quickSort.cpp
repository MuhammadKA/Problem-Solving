#include <vector>
using namespace std;

// Best: O(nlog(n)) time | O(log(n)) space
// Average: O(nlog(n)) time | O(log(n)) space
// Worst: O(n^2) time | O(log(n)) space
vector<int> quickSortHelper(vector<int> &array, int startIdx, int endIdx);

vector<int> quickSort(vector<int> array) {
  // Write your code here.
  quickSortHelper(array, 0, array.size() - 1);
  return array;
}

vector<int> quickSortHelper(vector<int> &array, int startIdx, int endIdx) {
  if (startIdx >= endIdx)
    return array;
  int pivotIdx = startIdx;
  int leftIdx = startIdx + 1;
  int rightIdx = endIdx;

  while (leftIdx <= rightIdx) {
    if (array[leftIdx] > array[pivotIdx] && array[rightIdx] < array[pivotIdx]) {
      swap(array[leftIdx], array[rightIdx]);
    }
    if (array[leftIdx] <= array[pivotIdx]) {
      leftIdx++;
    }
    if (array[rightIdx] >= array[pivotIdx]) {
      rightIdx--;
    }
  }
  swap(array[rightIdx], array[pivotIdx]);
  bool isLeftArraySmaller = rightIdx - 1 - startIdx < endIdx - (rightIdx + 1);
  if (isLeftArraySmaller) {
    quickSortHelper(array, startIdx, rightIdx - 1);
    quickSortHelper(array, rightIdx + 1, endIdx);
  } else {
    quickSortHelper(array, rightIdx + 1, endIdx);
    quickSortHelper(array, startIdx, rightIdx - 1);
  }
  return array;
}