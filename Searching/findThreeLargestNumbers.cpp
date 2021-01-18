// O(N) time | O(1) space

#include <climits>
#include <vector>
using namespace std;

vector<int> findThreeLargestNumbers(vector<int> array) {
  // Write your code here.
  vector<int> ThreeLargest = {INT_MIN, INT_MIN, INT_MIN};
  for (int i = 0; i < array.size(); i++) {
    if (array[i] > ThreeLargest[2]) {
      ThreeLargest[0] = ThreeLargest[1];
      ThreeLargest[1] = ThreeLargest[2];
      ThreeLargest[2] = array[i];
    } else if (array[i] > ThreeLargest[1]) {
      ThreeLargest[0] = ThreeLargest[1];
      ThreeLargest[1] = array[i];
    } else if (array[i] > ThreeLargest[0]) {
      ThreeLargest[0] = array[i];
    }
  }
  return ThreeLargest;
}

// ************************************************************ < Cleaner Implementation > *************************************************** 
// O(N) time | O(1) space

#include <climits>
#include <vector>
using namespace std;

void updateLargest(vector<int> &ThreeLargest, int num);
void shiftAndUpdate(vector<int> &ThreeLargest, int num, int idx);

vector<int> findThreeLargestNumbers(vector<int> array) {
  // Write your code here.
  vector<int> ThreeLargest = {INT_MIN, INT_MIN, INT_MIN};
  for (int num : array) {
    updateLargest(ThreeLargest, num);
  }
  return ThreeLargest;
}

void updateLargest(vector<int> &ThreeLargest, int num) {
  if (num > ThreeLargest[2]) {
    shiftAndUpdate(ThreeLargest, num, 2);
  } else if (num > ThreeLargest[1]) {
    shiftAndUpdate(ThreeLargest, num, 1);
  } else if (num > ThreeLargest[0]) {
    shiftAndUpdate(ThreeLargest, num, 0);
  }
}

void shiftAndUpdate(vector<int> &ThreeLargest, int num, int idx) {
  for (int i = 0; i <= idx; i++) {
    if (i == idx) {
      ThreeLargest[i] = num;
    } else {
      ThreeLargest[i] = ThreeLargest[i + 1];
    }
  }
}