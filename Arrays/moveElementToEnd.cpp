#include <vector>
using namespace std;

// O(n) time | O(1) space
vector<int> moveElementToEnd(vector<int> array, int toMove) {
  // Write your code here.
  int left = 0;
  int right = array.size() - 1;
  while (right > left) {
    if (array[left] == toMove && array[right] != toMove) {
      swap(array[left], array[right]);
      left++;
      right--;
    } else if (array[left] == toMove && array[right] == toMove) {
      right--;
    } else if (array[left] != toMove && array[right] != toMove) {
      left++;
    } else {
      left++;
      right--;
    }
  }
  return array;
}

//--------------------------------------------------- < Another Solution > ----------------------------------------

#include <vector>
using namespace std;

// O(n) time | O(1) space
vector<int> moveElementToEnd(vector<int> array, int toMove) {
  // Write your code here.
  int left = 0;
  int right = array.size() - 1;
  while (right > left) {
    while (right > left && array[right] == toMove)
      right--;
    if (array[left] == toMove)
      swap(array[left], array[right]);
    left++;
  }
  return array;
}