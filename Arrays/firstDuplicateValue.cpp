#include <vector>
using namespace std;

// O(n^2) time | O(1) space
int firstDuplicateValue(vector<int> array) {

  int minimumSecondIndex = array.size();
  for (int i = 0; i < array.size(); i++) {
    int value = array[i];
    for (int j = i + 1; j < array.size(); j++) {
      int valueToCompare = array[j];
      if (value == valueToCompare) {
        minimumSecondIndex = min(minimumSecondIndex, j);
      }
    }
  }
  if (minimumSecondIndex == array.size())
    return -1;
  return array[minimumSecondIndex];
}
