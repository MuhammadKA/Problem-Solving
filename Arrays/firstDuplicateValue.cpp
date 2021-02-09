#include <vector>
using namespace std;

// O(n^2) time | O(1) space
int firstDuplicateValue(vector<int> array) {

  int minimumSecondIndex = array.size();
  for (int i = 0; i < array.size(); i++) {
    int value = array[i];
    for (int j = i + 1; j < array.size(); j++) {
      int valueToCompare = array[j];
      if (value == valueToCompare) {
        minimumSecondIndex = min(minimumSecondIndex, j);
      }
    }
  }
  if (minimumSecondIndex == array.size())
    return -1;
  return array[minimumSecondIndex];
}

// -------------- < Time Optimal Solution | Worse Space > ------

#include <unordered_map>
#include <vector>
using namespace std;

// O(n) time | O(n) space
int firstDuplicateValue(vector<int> array) {
  unordered_map<int, bool> seenBefore;
  for (int value : array) {
    if (seenBefore.find(value) != seenBefore.end()) {
      return value;
    }
    seenBefore[value] = true;
  }
  return -1;
}

// -------------- < Best Optimal Solution > ------


#include <vector>
using namespace std;

// O(n) time | O(1) space
int firstDuplicateValue(vector<int> array) { 
	for (int value : array) {
		int absValue = abs(value);
		if (array[absValue - 1] < 0) {
			return absValue;
		}
		array[absValue - 1] *= -1;
	}
	return -1; 
}

