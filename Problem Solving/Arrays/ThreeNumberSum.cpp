// Solution 1
// O(n^3) time | O(1) space

#include <vector>
using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
  // Write your code here.
  vector<vector<int>> triplets{};
  vector<int> temp;
  for (int i = 0; i < array.size() - 2; i++) {
    for (int j = i + 1; j < array.size() - 1; j++) {
      for (int k = j + 1; k < array.size(); k++) {
        if (targetSum - array[i] - array[j] - array[k] == 0) {
          temp.push_back(array[i]);
          temp.push_back(array[j]);
          temp.push_back(array[k]);
          sort(temp.begin(), temp.end());
          triplets.push_back(temp);
          temp.clear();
        }
      }
    }
  }
  sort(triplets.begin(), triplets.end());
  // End of your code.
  return triplets;
}

//***********************************************************************************************************************

// Solution 2
// O(n^2) time | O(n) space

#include <vector>
using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
  // Write your code here.
  sort(array.begin(), array.end());
  vector<int> temp;
  vector<vector<int>> triplets = {};
  for (int curr = 0; curr < array.size() - 2; curr++) {
    int left = curr + 1;
    int right = array.size() - 1;
    while (right > left) {
      if (array[curr] + array[left] + array[right] == targetSum) {
        temp.push_back(array[curr]);
        temp.push_back(array[left]);
        temp.push_back(array[right]);
        sort(temp.begin(), temp.end());
        triplets.push_back(temp);
        temp.clear();
        // Move both pointers at the same time
        // because hitting the targetSum means that if we only move one pointer
        // we will either get a number that is less or greater than the
        // targetSum and not equal to it.
        right--;
        left++;
      } else if (array[curr] + array[left] + array[right] > targetSum) {
        right--;
      } else {
        left++;
      }
    }
  }
  // End of your code.
  sort(triplets.begin(), triplets.end());
  return triplets;
}