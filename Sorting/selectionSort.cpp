// Best: O(N^2) time | O(1) space
// Average: O(N^2) time | O(1) space
// Worst: O(N^2) time | O(1) space

#include <vector>
using namespace std;

vector<int> selectionSort(vector<int> array) {
  // Write your code here.
  if (array.empty())
    return {};
  // startIdx is the index of the first number in the unsorted sub-list
  // we just need to go to the last index - 1 in the array, because when our
  // unsorted list contains only 1 number, then this number is in its final
  // position
  for (int startIdx = 0; startIdx < array.size() - 1; startIdx++) {
    int j = startIdx + 1;
    int smallest_index = startIdx;
    while (j < array.size()) {
      if (array[smallest_index] > array[j])
        smallest_index = j;
      j++;
    }
    swap(array[smallest_index], array[startIdx]);
  }
  return array;
}
