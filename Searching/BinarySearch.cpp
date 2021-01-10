// Recursive Solution
// O(log(n)) time | O(log(n)) space
#include <vector>
using namespace std;

int binarySearchHelper(vector<int> array, int target, int left, int right) {
  if (left > right) {
    return -1;
  }
  int middle = floor((left + right) / 2);
  if (array[middle] > target) {
    return binarySearchHelper(array, target, left, middle - 1);
  } else if (array[middle] < target) {
    return binarySearchHelper(array, target, middle + 1, right);
  } else {
    return middle;
  }
}

int binarySearch(vector<int> array, int target) {
  // Write your code here.
  return binarySearchHelper(array, target, 0, array.size() - 1);
}

// ************************************************* < Another Solution > **************************************** 
//Iterative Solution 
// O(log(n)) time | O(1) space
#include <vector>
using namespace std;

int binarySearch(vector<int> array, int target) {
  // Write your code here.
  int left = 0;
  int right = array.size() - 1;
  while (left <= right) {
    int middle = floor((left + right) / 2);
    if (array[middle] == target) {
      return middle;
    } else if (array[middle] > target) {
      right = middle - 1;
    } else {
      left = middle + 1;
    }
  }
  return -1;
}
