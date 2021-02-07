using namespace std;

// O(n) time | O(1) space
bool breaksDirection(int direction, int previousInt, int currentInt) {
  int difference = currentInt - previousInt;
  if (direction > 0)
    return difference < 0;
  return difference > 0;
}

bool isMonotonic(vector<int> array) {
  // Write your code here.
  if (array.size() <= 2)
    return true;
  int direction = array[1] - array[0];
  for (int i = 2; i < array.size(); i++) {
    if (direction == 0) {
      direction = array[i] - array[i - 1];
      continue;
    }
    if (breaksDirection(direction, array[i - 1], array[i]))
      return false;
  }
  return true;
}

// ------------------------------------------------ < Another Solution > ----------------------------------------------

using namespace std;

// O(n) time | O(1) space
bool isMonotonic(vector<int> array) {
  // Write your code here.
  bool nonDecreasing = true;
  bool nonIncreasing = true;

  for (int i = 1; i < array.size(); i++) {
    if (array[i] > array[i - 1]) {
      nonDecreasing = false;
    }
    if (array[i] < array[i - 1]) {
      nonIncreasing = false;
    }
  }
  return nonDecreasing || nonIncreasing;
}
