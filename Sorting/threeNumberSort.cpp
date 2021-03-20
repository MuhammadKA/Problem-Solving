#include <algorithm>
#include <vector>
using namespace std;

// O(1) space | O(n) time
vector<int> threeNumberSort(vector<int> array, vector<int> order) {
  // Write your code here.
  int firstValue = order[0];
  int lastValue = order[2];
  int firstIdx = 0;

  for (int i = 0; i < array.size(); i++) {
    if (firstValue == array[i]) {
      swap(array[i], array[firstIdx]);
      firstIdx++;
    }
  }

  int thirdIdx = array.size() - 1;

  for (int i = thirdIdx; i >= 0; i--) {
    if (lastValue == array[i]) {
      swap(array[i], array[thirdIdx]);
      thirdIdx--;
    }
  }

  return array;
}
