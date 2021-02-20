#include <vector>
using namespace std;

// O(nlog(n)) time | O(1) space
int nonConstructibleChange(vector<int> coins) {
  // Write your code here.
  if (coins.empty())
    return 1;
  sort(coins.begin(), coins.end());
  int change = 0;
  for (int i = 0; i < coins.size(); i++) {
    if (coins[i] > change + 1) {
      return change + 1;
    } else {
      change += coins[i];
    }
  }
  return change + 1;
}
