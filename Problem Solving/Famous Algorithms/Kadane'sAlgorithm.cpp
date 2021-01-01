#include <vector>
using namespace std;
// Uses Dynamic Programming 

// O(n) time | O(1) space
int kadanesAlgorithm(vector<int> array) {
  // Write your code here.
  int maxEndingHere = array[0];
  int maxSoFar = array[0];
  for (int i = 1; i < array.size(); i++) {
    maxEndingHere = max(maxEndingHere + array[i], array[i]);
    maxSoFar = max(maxSoFar, maxEndingHere);
  }
  return maxSoFar;
}
