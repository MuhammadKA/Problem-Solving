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

// -------------------------------------------- < Optimized Solution > -----------------------------------------

// O(n) time | O(1) space - Most Optimal solution, requieres exactly one
// traverse in the array
vector<int> threeNumberSort(vector<int> array, vector<int> order) {
  // Write your code here.
  int firstValue = order[0];
  int secondValue = order[1];

  int firstIdx = 0;
  int secondIdx = 0;
  int thirdIdx = array.size() - 1;

  while (secondIdx <= thirdIdx) {
    int value = array[secondIdx];

    if (value == firstValue) {
      swap(array[secondIdx++], array[firstIdx++]);
    } else if (value == secondValue) {
      secondIdx++;
    } else {
      swap(array[secondIdx], array[thirdIdx--]);
    }
  }
  return array;
}
