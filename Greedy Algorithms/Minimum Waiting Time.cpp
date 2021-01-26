// Greedy Algorithm
// O(n^2) time | O(1) space
using namespace std;
#include <algorithm>
#include <vector>

int minimumWaitingTime(vector<int> queries) {
  // Write your code here.
  sort(queries.begin(), queries.end());

  int totalWaitingTime = 0;
  for (int i = 0; i < queries.size(); i++) {
    int waitingTime = 0;
    for (int j = 0; j < i; j++) {
      waitingTime += queries[j];
    }
    totalWaitingTime += waitingTime;
  }
  return totalWaitingTime;
}

// ============================================================ < Another Solution > =====================================================================

// Greedy Algorithm
// O(nlog(n)) time | O(1) space
using namespace std;
#include <algorithm>
#include <vector>

int minimumWaitingTime(vector<int> queries) {
  // Write your code here.
  sort(queries.begin(), queries.end());

  int totalWaitingTime = 0;
  for (int idx = 0; idx < queries.size(); idx++) {
    int duration = queries[idx];
    int queriesLeft = queries.size() - (idx + 1);
    totalWaitingTime += duration * queriesLeft;
  }
  return totalWaitingTime;
}
