#include <vector>
using namespace std;

// O(nlog(n)) time | O(1) space
bool classPhotos(vector<int> redShirtHeights, vector<int> blueShirtHeights) {
  // Write your code here.
  sort(redShirtHeights.begin(), redShirtHeights.end(), greater<int>());
  sort(blueShirtHeights.begin(), blueShirtHeights.end(), greater<int>());

  string shirtColorInFirstRow =
      redShirtHeights[0] > blueShirtHeights[0] ? "RED" : "BLUE";

  for (int i = 0; i < redShirtHeights.size(); i++) {
    if (shirtColorInFirstRow == "RED") {
      if (redShirtHeights[i] > blueShirtHeights[i])
        continue;
      return false;
    } else {
      if (redShirtHeights[i] < blueShirtHeights[i])
        continue;
      return false;
    }
  }
  return true;
}
