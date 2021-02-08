using namespace std;

// O(n) time | O(1) space
int longestPeak(vector<int> array) {
  // Write your code here.
  int longestPeakLength = 0;
  int i = 1;
  while (i < int(array.size() - 1)) {
    bool isPeak = array[i] > array[i - 1] && array[i] > array[i + 1];
    if (!isPeak) {
      i++;
      continue;
    }

    int leftIdx = i - 2;
    while (leftIdx >= 0 && array[leftIdx] < array[leftIdx + 1]) {
      leftIdx--;
    }
    int rightIdx = i + 2;
    while (rightIdx < array.size() && array[rightIdx] < array[rightIdx - 1]) {
      rightIdx++;
    }

    int currentPeakLength = rightIdx - leftIdx - 1;
    longestPeakLength = max(longestPeakLength, currentPeakLength);
    i = rightIdx;
  }
  return longestPeakLength;
}
