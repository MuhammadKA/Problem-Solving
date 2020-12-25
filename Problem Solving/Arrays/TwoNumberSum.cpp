// Solution 1

#include <vector>
using namespace std;
// O(n^2) time | O(1) space
vector<int> twoNumberSum(vector<int> array, int targetSum) {
  // Write your code here.
  vector<int> temp;
  for (int i = 0; i < array.size() - 1; i++) {
    for (int j = i + 1; j < array.size(); j++) {
      if (array[i] + array[j] == targetSum)
        return vector<int>{array[i], array[j]};
    }
  }
  // End of your code
  return {};
}

//***********************************************************************************************************************

// Solution 2

#include <map>
#include <vector>
using namespace std;
// O(n) time | O(n) space
vector<int> twoNumberSum(vector<int> array, int targetSum) {
  // Write your code here.
  std::map<int, bool> memo;
  for (int i = 0; i < array.size(); i++) {
    int target = targetSum - array[i];
    if (memo.find(target) != memo.end()) {
      return vector<int>{target, array[i]};
    } else {
      memo[array[i]] = true;
    }
  }
  // End of your code.
  return {};
}

//***********************************************************************************************************************

// Solution 3

#include <vector>
using namespace std;
// O(nlog(n)) time | O(1) space
// O(nlog(n)) time is due to the sorting step
vector<int> twoNumberSum(vector<int> array, int targetSum) {
  // Write your code here.
  sort(array.begin(), array.end());
  int left_ptr = 0;
  int right_ptr = array.size() - 1;
  while (right_ptr > left_ptr) { // while the two pointers don't overlap
    int currentSum = array[left_ptr] + array[right_ptr];
    if (currentSum == targetSum) {
      return vector<int>{array[left_ptr], array[right_ptr]};
    } else if (currentSum > targetSum) {
      right_ptr--;
    } else if (currentSum < targetSum) {
      left_ptr++;
    }
  }
  // End of your code.
  return {};
}
