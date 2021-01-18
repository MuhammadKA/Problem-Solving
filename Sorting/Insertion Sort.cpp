// Best: O(N) time | O(1) space
// Average: O(N^2) time | O(1) space
// Worst: O(N^2) time | O(1) space

#include <vector>
using namespace std;

vector<int> insertionSort(vector<int> array) {
  // Write your code here.
  for (int i = 1; i < array.size(); i++) {
    int j = i;
    while (j > 0 && array[j - 1] > array[j]) {
      swap(array[j - 1], array[j]);
      j--;
    }
  }
  return array;
}
