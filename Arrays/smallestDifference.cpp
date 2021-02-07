#include <vector>
using namespace std;

// O(n*m) time | O(1) space
vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
  // Write your code here.
  int numberOne = arrayOne[0];
  int numberTwo = arrayTwo[0];
  int smallestDifference = abs(numberOne - numberTwo);
  for (int i = 0; i < arrayOne.size(); i++) {
    for (int j = 0; j < arrayTwo.size(); j++) {
      int currentDifference = abs(arrayOne[i] - arrayTwo[j]);
      if (currentDifference < smallestDifference) {
        smallestDifference = currentDifference;
        numberOne = arrayOne[i];
        numberTwo = arrayTwo[j];
      }
    }
  }
  return {numberOne, numberTwo};
}
//----------------------------------------------------------------- < Better Solution > ---------------------------------

#include <vector>
using namespace std;
// O(nlog(n) + mlog(m)) time | O(1) space
vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
  // Write your code here.
  sort(arrayOne.begin(), arrayOne.end());
  sort(arrayTwo.begin(), arrayTwo.end());
  vector<int> smallestPair;
  int idxOne = 0;
  int idxTwo = 0;
  int currentDiff = INT_MAX;
  int smallestDiff = INT_MAX;
  while (idxOne < arrayOne.size() && idxTwo < arrayTwo.size()) {
    int firstNum = arrayOne[idxOne];
    int secondNum = arrayTwo[idxTwo];
    currentDiff = abs(secondNum - firstNum);
    if (firstNum < secondNum) {
      idxOne++;
    } else if (firstNum > secondNum) {
      idxTwo++;
    } else {
      return {firstNum, secondNum};
    }
    if (currentDiff < smallestDiff) {
      smallestDiff = currentDiff;
      smallestPair = {firstNum, secondNum};
    }
  }
  return smallestPair;
}
