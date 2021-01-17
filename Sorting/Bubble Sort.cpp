// Best: O(N) time | O(1) space
// Average: O(N^2) time | O(1) space
// Worst: O(N^2) time | O(1) space

#include <vector>
using namespace std;

vector<int> bubbleSort(vector<int> array) {
  // Write your code here.
  if (array.empty()) {
    return {};
  }
  bool isSorted = false;
  int counter = 0; // small optimization
  while (!isSorted) {
    isSorted = true;
    for (int i = 0; i < array.size() - 1 - counter; i++) {
      if (array[i] > array[i + 1]) {
        swap(array[i], array[i + 1]);
        isSorted = false;
      }
    }
    counter++;
  }
  return array;
}